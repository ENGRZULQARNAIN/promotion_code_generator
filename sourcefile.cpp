#include <iostream>
#include<string>
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

     cin>>obj.phonenumber[i];
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
    cout<<" Create password here :";
    cin>>hashArray[index]->userin.password;


   // promo_code function call;
   promo_code_encrypt_1(hashArray[index]->phonenumber);

   system("CLS");
   well_come_page();
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
       cout<<promo_array[i]<<" ";
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
       // cout<<ch_promo_array[i];
     }

     cout<<endl;

     //promo_code_decrypt_1();
}

void Operations::promo_code_decrypt_1(){
for(int i=0;i<11;i++){
    if(ch_promo_array[i]!='-'){
        promo_array[i]=ch_promo_array[i];
    }
    //cout<<promo_array[i]<<" ";
}
//cout<<endl;
promo_code_decrypt_2();
}


void Operations::promo_code_decrypt_2(){

    int var1=65;
    int var2=90;
   for(int i=0;i<11;i++){
        if(i<6){
       promo_array[i]=(promo_array[i])-(var1++);
        }
       else
       {
         promo_array[i]=(var2--)-(promo_array[i]);
       }
      //cout<<promo_array[i]<<"-";
 }

}
bool Operations::SignIn_fun(){
    bool flag=false;
cout<<"Enter your phone number:  ";
int phone[11];
for(int i=0;i<11;i++){
    cin>>phone[i];
}
string password1;
cout<<"Enter your password(without space): ";
cin>>password1;

int index=hashFunction(phone);
if(hashArray[index]->name=="" && hashArray[index]->email_==""){
    cout<<"YOUR RECORD WAS NOT FOUND! PLZ SIGN UP"<<endl;
    return flag;
}
else{
        //int check=0;
    for(int i=0; i< 11; i++){
            cout<<hashArray[index]->phonenumber[i]<<" ";
        if(hashArray[index]->phonenumber[i]==phone[i])
        {
            flag=true;
        }
        else{
            flag=false;
            break;
        }
    }
    if(flag&&password1==hashArray[index]->userin.password){
    // this is the blo
       flag=true;
    }
    else{
            flag=false;
        //cout<<" \nYour password is Incorrect please enter correct password \n";
        //SignIn_fun();
    }
}

return flag;

}

void Operations::coupon_use(){
    for(int i=0;i<14;i++){
        cout<<ch_promo_array[i];
    }
cout<<"\n\nEnter your coupon or promotion code here(with-dashes): ";
for(int i=0;i<11;i++){
  cin>>ch_promo_array[i];
}
promo_code_decrypt_1();
int index=hashFunction(promo_array);
bool flag=false;
for(int i=0;i<11;i++){
if(hashArray[index]->phonenumber[i]==promo_array[i]){
    flag=true;
}else{
  flag=false;
  break;
}
}

 if(flag){
    display();

    cout<<"\n\\t\t\t\tCONRAGULATONS\n you have taken 20% discount on every product"<<endl;
 }
}
void Operations::well_come_page(){
int choice;
       bool flag=true;
     cout<<"\t\tPLEASE SELECT AN OPTION LIKE (1,2,3,ETC)"<<endl;
     cout<<"1->SIGN_UP"<<endl
     <<"2->SIGN_IN"<<endl;
     cout<<"\n\nEnter a choice here"<<endl;
     cin>>choice;

  switch (choice) {
        case 1:
             SignUp_fun();
            break;
        case 2:
             do{
   flag=SignIn_fun();
   if(flag){
    coupon_use();
   }else{
       cout<<"login Information is incorrect!"<<endl;
   }
   }while(flag==false);
            break;
        default:
            std::cout << "Invalid input." << std::endl;
    }

}


