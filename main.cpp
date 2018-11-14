#include<iostream>
#include<windows.h>
#include<conio.h>
#define Enter 13    //for admin password
#define TAB 9       //for admin password
#define BKSP 8      //for admin password
#define SPACE 32    //for admin password
using namespace std;
char pass[50]; //array for password

void IUBAT_Logo();
int FrontPage();
void Loading();
void Admin();
bool AdminPass();
string password();   //for store password
void Employee();

class Product
{
    string name;
    int ID,Quantity;
    float price;
public:
    void Info()    //Employee can access
    {
        cout<<"product info"<<endl;
    }
    void Buy()
    {
        cout<<"Buy product"<<endl;
    }
    void Sell()    //Employee can access but admin can't
    {
        cout<<"Sell product"<<endl;
    }
    //void Add();
    //void Delete();
    void Edit()
    {
        cout<<"product info edit"<<endl;
    }
    void BuyHistory()
    {
        cout<<"BuyHistory"<<endl;
    }
    void SellHistory()  //Employee can access
    {
        cout<<"SellHistory"<<endl;
    }
};

int main()
{
    int input_Access = FrontPage();
    if(input_Access == 1)
        Admin();
    else if(input_Access == 2)
        Employee();
    else
        cout<<"Enter either 1 or 2..(You entered Something else)";
    return 0;
}
void IUBAT_Logo()
{
    cout<<"\n\n\t\tIII	UUU	UUU	BBBBBBBBB    	  AAA	    TTTTTTTTTTTTTT"<<endl;
    cout<<  "\t\tIII	UUU	UUU	BBB   BBBB       AA AA	         TTT"<<endl;
    cout<<  "\t\tIII	UUU	UUU	BBB   BBBB      AA   AA	         TTT"<<endl;
    cout<<  "\t\tIII	UUU	UUU	BBBBBBBB       AAAAAAAAA	 TTT"<<endl;
    cout<<  "\t\tIII	UUU	UUU	BBB   BBBB    AAA     AAA	 TTT"<<endl;
    cout<<  "\t\tIII	UUUU   UUUU	BBB   BBBB   AAA      AAAA       TTT"<<endl;
    cout<<  "\t\tIII	 UUUUUUUUU	BBBBBBBBB   AAAA       AAAA	 TTT"<<endl;
}
int FrontPage()
{
    IUBAT_Logo();
    cout<<"\n\n\t\t\t***WELCOME TO RAISHA DEPARTMENTAL STORE***\n\n";
    cout<<"\t\t\t\tPress Enter to continue.\n";
    getch();
    system("cls");
    IUBAT_Logo();
    Loading();
    IUBAT_Logo();
    cout<<"\n\n\t\tAccess to the program as :\n";
    cout<<"\t\t1. Admin(Enter 1)\n";
    cout<<"\t\t2. Employee(Enter 2)\n";
    cout<<"\t\tEnter 1 or 2 : ";
    int input;
    cin>>input;
    return input;
    getch();
}
void Loading()
{
    cout<<"\n\n\t\tLoading";
    for(int i=0;i<3;i++)
    {
        cout<<".";
        Sleep(0400);
    }
    system("cls");
}
void Admin()
{
    system("cls");
    IUBAT_Logo();
    bool access = false;
    access = AdminPass();
    system("cls");
    IUBAT_Logo();
    int adminInput;
    cout<<"\n\n\t\tAccess as an Admin .\n";
    cout<<"\t\t1 . Show product Information.\n";
    cout<<"\t\t2 . Buy product.\n";
    cout<<"\t\t3 . Edit product information.\n";
    cout<<"\t\t4 . Buy history.\n";
    cout<<"\t\t5 . Sell history.\n";
    cout<<"\t\tEnter a number to choose one option : ";
    cin>>adminInput;
    system("cls");
    IUBAT_Logo();
    Product pro;
    switch(adminInput)
    {
    case 1:
        pro.Info();
        break;
    case 2:
        pro.Buy();
        break;
    case 3:
        pro.Edit();
        break;
    case 4:
        pro.BuyHistory();
        break;
    case 5:
        pro.SellHistory();
        break;
    default:
        cout<<"Enter a number between 1-5";
        break;
    }
}
string password()
{
    char ch;
    int i = 0;
    while(1)
    {
        ch = getch();
        if(ch == Enter || ch == TAB)
        {
            pass[i] = '\0';
            break;
        }
        else if(ch == BKSP)
        {
            if(i > 0)
            {
                i--;
                cout<<"\b \b";
            }
        }
        else
        {
            pass[i++] = ch;
            cout<<"* \b";
        }
    }
    return pass;
}
bool AdminPass()
{
    string username;
    string passw;
    bool loginLoop = false;
    do
    {
        cout<<"\n\n\t\tEnter Username and Password : \n";
        cout<<"\n\t\tUsername : ";
        cin>>username;
        cout<<"\n\t\tPassword : ";
        passw = password();

        if(username == "raisha_tabassum" && passw == "raisha18103143")
        {
            cout<<"\n\t\tAccess granted..";
            loginLoop = true;
        }
        else
        {
            system("cls");
            IUBAT_Logo();
            cout<<"\n\n\t\tYou Enter Wrong username or password.Try Again..\n";
        }
    }while(!loginLoop);
}
void Employee()
{
    system("cls");
    IUBAT_Logo();
    int employeeInput;
    cout<<"\n\n\t\tAccess as an employee .\n";
    cout<<"\t\t1 . Show product Information.\n";
    cout<<"\t\t2 . Make customer bill.\n";
    cout<<"\t\t3 . Sell history.\n";
    cout<<"\t\tEnter a number to choose one option : ";
    cin>>employeeInput;
    system("cls");
    IUBAT_Logo();
    Product pro;
    switch(employeeInput)
    {
    case 1:
        pro.Info();
        break;
    case 2:
        pro.Sell();
        break;
    case 3:
        pro.SellHistory();
        break;
    default:
        cout<<"Enter a number between 1-3";
        break;
    }
}
