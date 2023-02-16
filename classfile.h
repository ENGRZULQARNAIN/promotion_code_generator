#include <string>

using namespace std;
////////CLASS SignIN is to store the credential data of a customer wants to signup.
class SignIn
{
public:
  string password;

  // constructor
  SignIn()
  {
    password = "";
  }
};
/// Signup class is used to store all the data of the user which will be given signup time.
class SignUp
{
public:
  SignIn userin;  // this data member store the password of the new user d
  string name;
  string email_;
  int flag;
  int phonenumber[11];
  // constructor
  SignUp()
  {
    name = email_ = "";
    for (int i = 0; i < 11; i++)
      phonenumber[i] = 0;

    flag = 0;
  }
};

class Operations
{
private:
  SignUp *hashArray[2129]; // to store the data of 1419 customers;
  int promo_array[11];     // it used in decryption function.
  char ch_promo_array[11];
  int tableSize;

public:
  // conostructor
  Operations()
  {
    tableSize = 2129;

    for (int i = 0; i < tableSize; i++)
      hashArray[i] = new SignUp();
  }
  // Functions
  void well_come_page();            // show the wellcome page to the user.
   void SignUp_fun();              // signup form will be open to the user calling this function.
   bool SignIn_fun();             // signin function will be open calling this function. 
  int hashFunction(int arr[]);   //  This function will calculate the hash vaule from the phone number of the user.
  ////////////////////////////////////////////////////////////////////////////////////////////////// 
  void promo_code_encrypt_1(int arr[]); 
                                     /// These two function is used to encypt the the phone number 
									 // for generating the promotion code. 
  void promo_code_encrypt_2();
  //////////////////////////////////////////////////////////////////////////////////////////////////
  void promo_code_decrypt_1();
                               // These two function will decrypt the generated promotion code.
                               //  when the user gives the promotion code.
  void promo_code_decrypt_2();
  //////////////////////////////////////////////////////////////////////////////////////////////////
  void coupon_use();   // this function compare and use the coupen vaule to encrypted vaule and decrypted vaule. 


  void display(int);
};
