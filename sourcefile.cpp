#include <iostream>
#include "classfile.h"

using namespace std;

int Operations::hashFunction(int phone[])
{
  int sum = 0;
  for (int i=0; i < 11; i++){
    sum = sum + phone[i];
  }
  return sum % tableSize;
}

void Operations::SignUp_fun()
{
  SignUp obj;
  cout << "\n\nWELCOME TO SIGN UP PAGE\n\n\n";
  cout << "Enter your name here: " << endl;
  cin >> obj.name;
  cout << "Enter your Email here: " << endl;
  cin >> obj.email_;
  cout << "Enter your phone Number here: " << endl;
  for (int i = 0; i < 11; i++){

    cin >> obj.phonenumber[i];
  }

  int index = hashFunction(obj.phonenumber);
  int h = 1;
  while (hashArray[index]->email_!="")
  {
    index = index + h * h;
    h++;
    index %= tableSize;
  }
  hashArray[index]->email_ = obj.email_;
  hashArray[index]->name = obj.name;
  for (int i = 0; i < 11; i++){

    hashArray[index]->phonenumber[i] = obj.phonenumber[i];
      }


   // promo_code function call;
   promo_code_encrypt_1(hashArray[index]->phonenumber);
}


void Operations::display(){
  for(int i=0;i<2129;i++){
    if(hashArray[i]->email_!=""){
  cout<<"hashArray["<<i<<"]"<<"= "<<"\tEmail: "<<hashArray[i]->email_<<"\tname: "<<hashArray[i]->name<<endl;

     cout<<"The phone number is : ";
     for (int j = 0; j < 11; j++){
    cout<<hashArray[i]->phonenumber[j];
  }
  }
  }
}


// promotion code generation.

void Operations::promo_code_encrypt_1(int arr_num[]){
 int var1=65;
    int var2=90;
   for(int i=0;i<11;i++){
        if(i<6){
       promo_array[i]=(arr_num[i])+(var1++);
        }
       else
       {
         promo_array[i]=(var2--)-(arr_num[i]);
       }
 }
 promo_code_encrypt_2();
}

void Operations::promo_code_encrypt_2(){
    for(int i=3;i<=11;i=i+4){
    ch_promo_array[i]='-';
    }
     for(int i=0;i<14;i++){
            if(ch_promo_array[i]!='-'){
        ch_promo_array[i]=promo_array[i];
            }
        cout<<ch_promo_array[i];
     }

     cout<<endl;
}
