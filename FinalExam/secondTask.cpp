#include <iostream>

class Stream {
protected:
    std::string buffer;
public:
    Stream() = default;
    virtual ~Stream() = default;
    Stream(const Stream &other) {
      this->buffer = other.buffer;
    }
    Stream(std::string string) {
      buffer = string;
    }
    virtual Stream* copy() = 0;
    virtual char get() = 0;
    virtual std::string take(unsigned n) {
      std::string part = buffer.substr(0, 10);

      auto last = buffer.begin();
      for (int i = 0; i < n; ++i) {
        if (last != buffer.end()) {
          last += 1;
        }
      }
      buffer.erase(buffer.begin(), last);

      return part;
    }
};

class StringStream: public Stream {
public:
    StringStream() = default;
    StringStream(std::string string):Stream(string) {}
    char get() override {
      char result = '\0';
      if (buffer.begin() != buffer.end()) {
        result = buffer.at(0);
        buffer.erase(buffer.begin());
      }

      return result;
    }

    Stream *copy() override {
      return new StringStream(buffer);
    }
};

class MergeStream: public Stream {
    Stream *leftStream;
    Stream *rightStream;
    bool source; /* True = left, false = right*/
    bool empty;
public:
    MergeStream() = default;
    ~MergeStream() {
      delete leftStream;
      delete rightStream;
    };
    MergeStream(Stream *left, Stream *right) {
      leftStream = left->copy();
      rightStream = right->copy();
      source = true;
      empty = false;
    }

    Stream *copy() override {
      return new MergeStream(leftStream, rightStream);
    }

    char get() override {
      if (empty) { /* Проверява дали някой от потоците не е свършил - асистента каза че тогава трябва да приключи програмата - сори за хотфикса - рева */
        return 0;
      }

      source = !source; /* flip */
      if (!source) {
        return leftStream->get();
      } else {
        return rightStream->get();
      }
    }

    std::string take(unsigned n) override {
      if (empty) { /* Проверява дали някой от потоците не е свършил - асистента каза че тогава трябва да приключи програмата - сори за хотфикса - рева */
        return "";
      }

      std::string result;
      for (int i = 0; i < n; ++i) {
        char first = this->get();
        if (first != 0) {
          result += first;
        } else {
          empty = true;
          return result;
        }
      }

      return result;
    }
};

int main() {
  StringStream *stringStream = new StringStream("Hello world!");
  std::cout << stringStream->take(10) << std::endl;
  std::cout << stringStream->take(10) << std::endl;

  StringStream *s1 = new StringStream("ABCABC");
  StringStream *s2 = new StringStream("123123");
  StringStream *s3 = new StringStream("=,=,=!");

  MergeStream *m1 = new MergeStream(s1, s2);
  MergeStream *m2 = new MergeStream(m1, s3);

  /* Важно, когато се имплементира възможността да се копират потоците примерът на подточка В) не е валиден, защото
   * там м1 и м2 използват едни и също потоци - тоест когато м1 прави операции те имат ефект след това върху информацията,
   * с която разполага м2, но когато се направят копия на потоците в м2 има достатъчно символа повече от 12 !! Тоест за
   * пример В) без копиращ механизъм програмата ще изведе A=1,B=2,C=3!, а със копиращ A=1,B=2,C=3!A ... ;) (да приемем, че когато свърши единият поток то merg-a приключва)
   * Съжалавям за обърканата ми реч ;ддд */

  std::cout << m1->take(6) << std::endl;
  std::cout << m2->take(15) << std::endl;

  delete stringStream;
  delete s1;
  delete s2;
  delete s3;
  delete m1;
  delete m2;
  return 0;
}

