#include <iostream>
#include <string>
#include "classfile.h"
#include <cstdio>

using namespace std;
//////////////////////////////////////////////////////////////////////////
int Operations::hashFunction(int phone[])
{
  int sum = 0;
  for (int i = 0; i < 11; i++)
  {
    sum = sum + phone[i];
  }
  return sum % tableSize;
}
///////////////////SIGN UP FORM ////////////////////////////
void Operations::SignUp_fun()
{
    system("CLS");
  SignUp obj;
  cout << "\n\nWELCOME TO SIGN UP PAGE\n\n\n";
  cout << "Enter your name here: " << endl;
  cin >> obj.name;
  cout << "Enter your Email here: " << endl;
  cin >> obj.email_;
  cout << "Enter your phone Number here: " << endl;
  for (int i = 0; i < 11; i++)
  {

    cin >> obj.phonenumber[i];
  }

  int index = hashFunction(obj.phonenumber);
  int h = 1;  // quadratic probing.
  while (hashArray[index]->email_ != "")
  {
    index = index + h * h;
    h++;
    index %= tableSize;
  }
  hashArray[index]->email_ = obj.email_;
  hashArray[index]->name = obj.name;
  for (int i = 0; i < 11; i++)
  {

    hashArray[index]->phonenumber[i] = obj.phonenumber[i];
  }
  cout << " Create password here :";
  cin >> hashArray[index]->userin.password;

  // promo_code function call;
  promo_code_encrypt_1(hashArray[index]->phonenumber);

  system("CLS");
  well_come_page();
}
/////////////////////////////////////////////////////////////////////////
void Operations::display(int index)
{

  cout << "\nEmail: " << hashArray[index]->email_ << "\nName: " << hashArray[index]->name << endl;

  cout << "\nThe phone number is : ";
  for (int j = 0; j < 11; j++)
  {
    cout << hashArray[index]->phonenumber[j];
  }
}
/////////////////////////////////////////////////////////////////////////////////////////////////
// promotion code generation.

void Operations::promo_code_encrypt_1(int arr_num[])
{
  int var1 = 65;
  int var2 = 90;
  for (int i = 0; i < 11; i++)
  {
    if (i < 6)
    {
      promo_array[i] = (arr_num[i]) + (var1++);
    }
    else
    {
      promo_array[i] = (var2--) - (arr_num[i]);
    }
  }
  promo_code_encrypt_2();
}
////////////////////////////////////////////////////////////////////////////////////////////
void Operations::promo_code_encrypt_2()
{
  for (int i = 0; i < 11; i++)
  {

    ch_promo_array[i] = promo_array[i];
  }
}
////////////////////////////////////////////////////////////////////////
void Operations::promo_code_decrypt_1()
{
  for (int i = 0; i < 11; i++)
  {

    promo_array[i] = ch_promo_array[i];
  }
  promo_code_decrypt_2();
}
//////////////////////////////////////////////////////////////////////////////////////
void Operations::promo_code_decrypt_2()
{

  int var1 = 65;
  int var2 = 90;
  for (int i = 0; i < 11; i++)
  {
    if (i < 6)
    {
      promo_array[i] = (promo_array[i]) - (var1++);
    }
    else
    {
      promo_array[i] = (var2--) - (promo_array[i]);
    }
  }
}

/////////////////////////////////////////////////////////////////////////////////
bool Operations::SignIn_fun()
{
  bool flag = false;
  cout << "Enter your phone number:  ";
  int phone[11];
  for (int i = 0; i < 11; i++)
  {
    cin >> phone[i];
  }
  string password1;
  cout << "Enter your password(without space): ";
  cin >> password1;

  int index = hashFunction(phone);
  hashArray[index]->flag++;
  if (hashArray[index]->name == "" && hashArray[index]->email_ == "")
  {
    cout << "YOUR RECORD WAS NOT FOUND! PLZ SIGN UP" << endl;
    return flag;
  }
  else
  {
    for (int i = 0; i < 11; i++)
    {
      if (hashArray[index]->phonenumber[i] == phone[i])
      {
        flag = true;
      }
      else
      {
        flag = false;
        break;
      }
    }
    if (flag && password1 == hashArray[index]->userin.password)
    {
      flag = true;
    }
    else
    {
      flag = false;
    }
  }

  return flag;
}
/////////////////////////////////////////////////////////////////////////////////
void Operations::coupon_use()
{
  int index;
  index = hashFunction(promo_array);
  if (hashArray[index]->flag > 1)
  {
    cout << "you have used the promo code once." << endl;
  }
  else
  {
    for (int i = 0; i < 11; i++)
    {
      cout << ch_promo_array[i];
    }

    cout << "\n\nEnter your coupon or promotion code here(with-dashes): ";
    for (int i = 0; i < 11; i++)
    {
      cin >> ch_promo_array[i];
    }
    promo_code_decrypt_1();
    index = hashFunction(promo_array);
    bool flag = false;
    for (int i = 0; i < 11; i++)
    {
      if (hashArray[index]->phonenumber[i] == promo_array[i])
      {
        flag = true;
      }
      else
      {
        flag = false;
        break;
      }
    }

    if (flag)
    {
      display(index);
      cout << "\n\t\t\tCONRAGULATONS\n you have taken 20% discount on every product" << endl;
    }
  }
  char ch;
  cout << "Do you want to exit [Y/N]: ";
  cin >> ch;
  if (ch == 'Y')
    well_come_page();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void Operations::well_come_page()
{
  system("CLS");
  int choice;
  bool flag = true;
  cout << "\t\tPLEASE SELECT AN OPTION LIKE (1,2,3,ETC)" << endl;
  cout << "1->SIGN_UP" << endl
       << "2->SIGN_IN" << endl;
  cout << "\n\nEnter a choice here" << endl;

  cin >> choice;

  switch (choice)
  {
  case 1:
    SignUp_fun();
    break;
  case 2:
    do
    {
      flag = SignIn_fun();
      if (flag)
      {
        system("CLS");
        coupon_use();
      }
      else
      {
        cout << "login Information is incorrect!" << endl;
      }
    } while (flag == false);

    break;
  default:
    std::cout << "Invalid input." << std::endl;
  }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
