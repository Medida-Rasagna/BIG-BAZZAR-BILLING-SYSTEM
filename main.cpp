#include<iostream>
#include<fstream>
#include<bits/stdc++.h>

using namespace std;

class shopping
{
private:
    int pcode;
    float price;
    string pname;
    float dis;

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


 cout<<"\t\t\t\t___________________________________\n";
 cout<<"\t\t\t\t                                   \n";
 cout<<"\t\t\t\t       BIGBAZZAR MAIN MENU         \n";
 cout<<"\t\t\t\t                                   \n";
 cout<<"\t\t\t\t___________________________________\n";
 cout<<"\t\t\t\t|   1)ADMINISTRATOR   |\n";
 cout<<"\t\t\t\t|                     |\n";
 cout<<"\t\t\t\t|   2)BUYER           |\n";
 cout<<"\t\t\t\t|                     |\n";
 cout<<"\t\t\t\t|   3)EXIT            |\n";
 cout<<"\t\t\t\t|                     |\n";
 cout<<"\n\t\t\t  PLEASE SELECT!";
 cin>>choice;

 switch(choice)
 {
 case 1:
     cout<<"\t\t\t PLEASE LOGIN \n";
     cout<<"\t\t\t ENTER EMAIL";
     cin>>email;
     cout<<"\t\t\t  PASSWORD     \n";
     cin>>password;

     if(email=="teddy@email.com"  && password=="TEDDY")
     {
         administrator();
     }
     else{
        cout<<"INVALID USER";
     }
     break;

 case 2:
     {
       buyer();
     }
 case 3:
    {
        exit(0);
    }
 default:
     {
         cout<<"PLEASE SELECT FROM THE GIVEN OPTIONS";
     }


 }
goto m;
}

void shopping ::administrator()
{
    m:
    int choice;
    cout<<"\n\n\n\t\t\t ADMINISTRATOR MENU";
    cout<<"\n\t\t\t|______1) ADD THE PRODUCT________|";
    cout<<"\n\t\t\t|                                |";
    cout<<"\n\t\t\t|______2) MODIFY THE PRODUCT_____|";
    cout<<"\n\t\t\t|                                |";
    cout<<"\n\t\t\t|______3) DELETE THE PRODUCT_____|";
    cout<<"\n\t\t\t|                                |";
    cout<<"\n\t\t\t|______4)  BACK TO MAIN MENU_____|";
    cout<<"\n\t\t\t|                                |";

    cout<<"\n\n\t PLEASE ENTER YOUR CHOICE ";
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
        cout<<"INVALID CHOICE";
    }
    goto m;
}

void shopping::buyer()
{
    m:
    int choice;
    cout<<"\t\t\t 1)BUY PRODUCT \n";
    cout<<"                     \n";
    cout<<"\t\t\t 2)BUYER       \n";
    cout<<"                     \n";
    cout<<"\t\t\t 3)GO BACK     \n";
    cout<<"                     \n";
    cout<<"\t\t\t ENTER YOUR CHOICE : ";

    cin>>choice;

    switch(choice)
    {
    case 1:
        receipt();
        break;
    case 2:
        menu();
        break;
    default:
        cout<<"INVALID CHOICE";
    }

goto m;
}

void shopping::add()
{
    m:
    fstream data;
    int c;
    int token =0;
    float p;
    float d;
    string n;

    cout<<"\n\n\t\t\t ADD NEW PRODUCT";
    cout<<"\n\n\t PRODUCT CODE OF THE PRODUCT ";
    cin>>pcode;
    cout<<"\n\n\t NAME OF THE PRODUCT ";
    cin>>pname;
    cout<<"\n\n\t PRICE OF THE PRODUCT ";
    cin>>price;
    cout<<"\n\n\t DISCOUNT ON PRODUCT ";
    cin>>dis;

    data.open("database.text",ios::in);

     if(!data){
        data.open("database.text", ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
    }
    else
    {
        data>>c>>n>>p>>d;

        while(!data.eof())
        {
            if(c== pcode){
                token++;
            }
            data>>c>>n>>p>>d;
        }
        data.close();

    if(token==1)
        goto m;

    else{
       data.open("database.text" ,ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
    }
    }
    cout<<"\n\n\t\t RECORD INSERTED !";
}

void shopping ::edit()
{
    fstream data,data1;
    int pkey;
    int token=0;
    int c;
    float p;
    float d;
    string n;

    cout<<"\n\t\t\t MODIFY THE RECORD";
    cout<<"\n\t\t\t PRODUCT CODE :";
    cin>>pkey;

    data.open("database.text",ios::in);
    if(!data)
    {
        cout<<"\n\n FILE DOESN'T EXIST! ";
    }
    else{
        data1.open("database 1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof())
        {
            if(pkey==pcode)
            {
                cout<<"\n\t\t PRODUCT OF NEW CODE :";
                cin>>c;
                cout<<"\n\t\t NAME OF THE PRODUCT :";
                cin>>n;
                cout<<"\n\t\t PRICE :";
                cin>>p;
                cout<<"\n\t\t DISCOUNT :";
                cin>>d;
                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout<<"\n\t\t RECORD EDITED ";
                token++;

            }
            else{
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";

            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();

        remove("database.text");
        rename("database 1.text","database.text");

        if(token==0)
        {
            cout<<"\n\n REOCRD NOT FOUND SORRY!";
        }

    }
}

void shopping::rem()
{
    fstream data,data1;
    int pkey;
    int token=0;
    cout<<"\n\n\t DELETE PRODUCT";
    cout<<"\n\n\t PRODUCT CODE :";
    cin>>pkey;
    data.open("database.text",ios::in);
    if(!data)
    {
        cout<<"\n\n\t FILE DOESN'T EXIST! ";
    }
    else{
        data1.open("database 1.text",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof())
        {
            if(pkey==pcode)
            {
                cout<<"\n\n\t PRODUCT DELETED SUCCESFULLY! ";
                token++;
            }
            else{
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();
        remove("database.text");
        rename("database 1.text","database.text");

        if(token==0)
        {
            cout<<"\n\n RECORD NOT FOUND";
        }
    }
}
void shopping::lis()
{
    fstream data;
    data.open("database.text",ios::in);
    cout<<"\n\n|______________________________________________________________\n";
    cout<<"ProNo\t\tName\t\t price\t\t Discount\n";
    cout<<"\n\n|______________________________________________________________\n";
    data>>pcode>>pname>>price>>dis;
    while(!data.eof())
    {
        cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\t\t"<<dis<<"\n";
        data>>pcode>>pname>>price>>dis;
    }
    data.close();
}


void shopping::receipt()
{

    fstream data;
    int arrcode[100000];
    int arrqunatity[100000];
    char choice;
    int c=0;
    float amount =0;
    float dis =0;
    float total=0;

    cout<<"\n\n\t\t\t\t BIGBAZZAR RECEIPT ";
    data.open("database.text",ios::in);
    if(!data)
    {
        cout<<"\n\n EMPTY DATABASE! ";
    }
    else{
        data.close();

        lis();
        cout<<"\n\n\t__________________________________________________________\n";
        cout<<"\n|                                                             \n";
        cout<<"\n\n\t                  PLEASE PLACE THE ORDER                  \n";
        cout<<"\n|                                                             \n";
        cout<<"\n\n\t__________________________________________________________\n";
        do
        {
            x:
            cout<<"\n\n ENTER PRODUCT CODE :";
            cin>>arrcode[c];
            cout<<"\n\n ENTER THE PRODUCT QUNATITY :";
            cin>>arrqunatity[c];
            for(int i=0;i<c;i++)
            {
                if(arrcode[c]==arrcode[i])
                {
                    cout<<"\n\n DUPLICATE PRODUCT CODE,PLEASE TRY AGAIN!";
                    goto x;
                }
            }
            c++;
            cout<<"\n\n DO YOU WANT TOT BUY ANOTHER PRODUCT ? IF YES THEN PRESS Y ELSE N";
            cin>>choice;
        }
        while(choice == 'Y');


        cout<<"\n\n\t\t\t____________________BIGBAZZAR RECEIPT_______________________\n";
        cout<<"\nPRODUCT NO \t PRODUCT NAME\t PRODUCT QUNATITY\t PRICE \t AMOUNT \t AMOUNT WITH DISCOUNT\n";


        for(int i=0;i<c;i++)
        {
            data.open("database.text",ios::in);
            data>>pcode>>pname>>price>>dis;
            while(!data.eof())
            {
                if(pcode==arrcode[i])
                {
                    amount = price*arrqunatity[i];
                    dis=amount-(amount*dis/100);
                    total = total+dis;
                    cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrqunatity[i]<<"\t\t"<<price<<"\t\t"<<amount<<"\t\t"<<dis;

                }
                data>>pcode>>pname>>price>>dis;
            }
        }
        data.close();
    }
    cout<<"\n\n__________________________________________________________________________\n";
    cout<<"\n TOTAL AMOUNT :"<<total;
}


int main()
{
    shopping s;
    s.menu();
}
