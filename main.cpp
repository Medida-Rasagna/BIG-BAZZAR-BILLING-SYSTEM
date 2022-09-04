#include<iostream>
#include<fstream>
#include<bits/stdc++.h>
#include <string>

using namespace std;

class shopping
{
private:
    int pcode;
    float price;
    float discount;
    string name;

public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void rem();
    void lis();
    void receipt();
};

void shopping :: menu()
{
    m:
    int choice;
    string email;
    string password;



    cout<< "\t\t\t\t\t___________________________________\n";
    cout<< "\t\t\t\t\t                                     \n";
   cout<< "\t\t\t\t\t       BIG BAZZAR MAIN MENU           \n";
   cout<< "\t\t\t\t\t                                      \n";
   cout<< "\t\t\t\t\t_____________________________________\n";
   cout<< "\t\t\t\t\t                                      \n";
   cout << "\t\t\t\t\t| 1) ADMIMISTRATOR |\n ";
   cout << "\t\t\t\t\t|                  |\n ";
   cout << "\t\t\t\t\t| 2) BUYER         |\n ";
   cout << "\t\t\t\t\t|                  |\n ";
   cout << "\t\t\t\t\t| 3) EXIT          |\n ";
   cout<< "\n\t\t\t\t\\t Please Select!";
   cin>>choice;

   switch(choice){
   case 1:
         cout<<" Please Login \n";
         cout<<" Enter Email \n";
         cin>>email;
         cout<<" password \n";
         cin>>password;

         if(email == "teddy@email.com"  && password == "Teddy@123456789")
         {
           administrator();
         }
         else{
            cout<<"Invalid Email/password";
         }
         break;
   case 2:
         {
             buyer();
         }
         break;
   case 3:
         {
            exit(0);
         }
         break;
   default:
         {
          cout<<"Please select from the given options";
         }
         break;
   }
goto m;

}

void shopping :: administrator()
{
    m:
    int choice;
    cout<<"\n\n\n\t\t\t ADMINISTRATOR MENU";
    cout<<"\n\n\n\t\t\t  1)Add The Product";
    cout<<"\n\n\n\t\t\t|                    |";
    cout<<"\n\n\n\t\t\t   2)Modify The Product";
    cout<<"\n\n\n\t\t\t|                     |";
    cout<<"\n\n\n\t\t\t|  3)Delete The Product";
    cout<<"\n\n\n\t\t\t|                      | ";
    cout<<"\n\n\n\t\t\t|   4)Back to main menu";

    cout<<"\n\n\nPlease enter your choice";
    cin>>choice;

    switch(choice)
    {
    case 1:
         add();
         break;
    case 2:
         edit();
         break;
    case 3:
         rem();
         break;
    case 4:
         menu();
         break;
    default :
        cout<<"Invalid choice!";
        break;
    }
    goto m;
}

void shopping :: buyer()
{
    m:
    int choice;
    cout<<"\t\t\t 1) Buyer \n";
    cout<<"                 \n";
    cout<<"\t\t\t 2)Buy Product\n";
    cout<<"                   \n";
    cout<<"\t\t\t 3) Go back   \n";
    cout<<"Enter Your Choice : ";

    cin>>choice;

    switch(choice)
    {
    case 1:
        receipt();
        break;
     case 2:
        menu();
        break;
     default :
        cout<<"Invalid Choice";
        break;
    }
    goto m;
}

void shopping :: add()
{
    m:
    fstream data;
    int c;
    int token =0;
    float p;
    float d;
    string n;

    cout<<"\n\n Add New Product";
    cout<<"\n\n Product code of the product ";
    cin>>pcode;
    cout<<"\n\n Name of the product ";
    cin>>name;
    cout<<"\n\n Price of the product ";
    cin>>price;
    cout<<"\n\n Discount on product";
    cin>>discount;

    data.open("database.text",ios::in);

    if(!data){
        data.open("database.text", ios::app|ios::out);
        data<<" "<<pcode<<" "<<name<<" "<<price<<" "<<discount<<"\n";
        data.close();
    }
    else{
        data>>c>>n>>p>>d;

        while(!data.eof())
        {
            if(c ==pcode)
            {
                token++;
            }
            data>>c>>n>>p>>d;
        }
        data.close();

    if(token==1)
     goto m;
    else{
       data.open("database.text" ,ios::app|ios::out);
        data<<" "<<pcode<<" "<<name<<" "<<price<<" "<<discount<<"\n";
        data.close();
    }
}
    cout<<"\n\n\n Record Inserted !";

}

void shopping :: edit()
{

    fstream data,data1;
    int pkey;
    int token=0;
    int c;
    float p;
    float d;
    string n;

    cout<<"\n\n Modify the record";
    cout<<"\n\n Product code :";
    cin>>pkey;

    data.open("database.text",ios::in);
    if(!data)
    {
        cout<<"\n\nFile does not exist !";
    }
    else{
        data1.open("database 1.text",ios::app|ios::out);
        data>>pcode>>name>>price>>discount;
        while(!data.eof())
        {
            if(pkey==pcode)
            {
                cout<<"\n\n\t Product new code :";
                cin>>c;
                cout<<"\n\n\t Name of the product :";
                cin>>n;
                cout<<"\n\n\t Price :";
                cin>>p;
                cout<<"\n\n\t Discount :";
                cin>>d;
                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout<<"\n\n\t\t Record Edited";
            }
            else
            {
                data1<<" "<<pcode<<" "<<name<<" "<<price<<" "<<discount<<"\n";
            }
            data>>pcode>>name>>price>>discount;
        }
        data.close();
        data1.close();

         remove("database.text");
         rename("database 1.text","database.text");

         if(token==0)
         {
             cout<<"\n\n Record not found sorry !";
         }
    }


}
void shopping ::rem()
{
    fstream data,data1;
    int pkey;
    int token=0;
    cout<<"\n\n\t Delete Product";
    cout<<"\n\n\t Enter the product code :";
    cin>>pkey;
    data.open("database.text",ios::in);
    if(!data)
    {
        cout<<"File does not exist";
    }
    else
    {
      data1.open("database 1.text",ios::app|ios::out);
    data>>pcode>>name>>price>>discount;
    while(!data.eof())
    {
        if(pkey==pcode)
        {
            cout<<"\n\n\t Product deleted successfully";
            token++;
        }
        else
        {
            data<<" "<<pcode<<" "<<name<<" "<<price<<" "<<discount<<"\n";
        }
        data>>pcode>>name>>price>>discount;
    }
    data.close();
    data1.close();
    remove("database.text");
    rename("database 1.text","database.text");

         if(token==0)
         {
             cout<<"\n\n Record not found  !";
         }
    }
}

void shopping ::lis()
{
    fstream data;
    data.open("database.text",ios::in);
    cout<<"\n\n________________________________________________\n";
    cout<<"Product Number\t\tName\t\tPrice\n";
    cout<<"\n\n________________________________________________\n";
     data>>pcode>>name>>price>>discount;
     while(!data.eof())
     {
         cout<<pcode<<"\t\t"<<name<<"\t\t"<<price<<"\n";
         data>>pcode>>name>>price>>discount;
     }
     data.close();
}

void shopping ::receipt()
{
  fstream data;

  int arrc[100000];
  int arrq[100000];
  char choice;
  int c=0;
  float amount =0;
  float discount =0;
  float total=0;

  cout<<"\n\n\t\t\t\t RECEIPT ";
  data.open("database.text",ios::in);
  if(!data)
  {
      cout<<"\n\n Empty database";
  }
  else
  {
      data.close();

      lis();
      cout<<"\n\n____________________________________________\n";
      cout<<"\n\n|                                             \n";
      cout<<"\n\n          Please Place The Order              \n";
      cout<<"\n\n______________________________________________\n";
      cout<<"\n\n|                                             \n";
      do
      {
          m:
          cout<<"\n\n Enter Product code :";
          cin>>arrc[c];
          cout<<"\n\nEnter the product quantity :";
          cin>>arrq[c];
          for(int i=0;i<c;i++)
          {
              if(arrc[c]==arrc[i])
              {
                  cout<<"\n\n Duplicate Product Code. Please Try again!";
                  goto m;
              }
          }
          c++;
           cout<<"\n\n Do You want to buy another product? If yes then press Y else N";
           cin>>choice;
      }
      while(choice == 'Y');

      cout<<"\n\n\t\t\t                  BIG BAZZAR RECEIPT                  \n";
      cout<<"\n\nProduct Number \t Product Name\t Product Quantity\t Price\t Amount\t Amount with Discount \n";

      for(int i=0; i<c; i++)
      {
          data.open("database.text",ios::in);
          data>>pcode>>name>>price>>discount;
          while(!data.eof())
          {
              if(pcode==arrc[i])
              {
                  amount=price*arrq[i];
                  discount=amount-(amount*discount/100);
                  total=total+discount;
                  cout<<"\n"<<pcode<<"\t\t"<<name<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t\t"<<amount<<"\t\t"<<discount;

              }
              data>>pcode>>name>>price>>discount;
          }
      }
      data.close();

  }
  cout<<"\n\n______________________________________________________";
  cout<<"\n Total Amount :"<<total<<"\n\n\n";
}

int main()
{
    shopping s;
    s.menu();
}


