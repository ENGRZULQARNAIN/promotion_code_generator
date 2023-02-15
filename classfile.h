#include<string>

using namespace std;

class SignIn
{
public:
  string email;
  string password;

  // constructor
  SignIn()
  {
    email = "";
    password = "";
  }
};

class SignUp
{
public:
  SignIn userin;
  ///////////////
  string name;
  string email_;
  int phonenumber[11];
  // constructor
  SignUp()
  {
    name = email_ = "";
    for (int i = 0; i < 11; i++)
      phonenumber[i] = 0;
  }
};

class Operations
{
private:
  SignUp *hashArray[2129];
  int promo_array[11];
  char ch_promo_array[14];
  int tableSize;
  int length;

public:
  // conostructor
  Operations()
  {
    tableSize = 2129;
    length = 1;

    for (int i = 0; i < tableSize; i++)
      hashArray[i] = new SignUp();
  }
  // Functions
  void SignUp_fun();
  int hashFunction(int arr[]);
  void promo_code_encrypt_1(int arr[]);
  void promo_code_encrypt_2();
  void promo_code_decrypt_1();
  void promo_code_decrypt_2();
  void coupon_use();
  bool SignIn_fun();
  void well_come_page();
  void display();
};
