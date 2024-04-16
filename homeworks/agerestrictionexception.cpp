
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class AgeRestrictionException : exception {
  private:
    string msg;
    int code;
  public:
    AgeRestrictionException(string msg, int code) : msg(msg), code(code) {};
    const char* what() const noexcept {
      return msg.c_str();
    }
    int getCode() const noexcept {
      return code;
    }
};

void registerParticipant(int age) {
  if (age < 18) {
    throw AgeRestrictionException("too young", 100);
  } else if (age > 101) {
    throw AgeRestrictionException("too old", 101);
  } else {
    cout << "Registration is succesful" << '\n';
  }
}


int main() {
  try {
    registerParticipant(17);
  } catch (AgeRestrictionException& ex) {
    cout << ex.what() << ", error code " << ex.getCode() << '\n';
  }

  return 0;
}
