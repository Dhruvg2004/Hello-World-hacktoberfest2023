#include<iostream>
#include<string>
using namespace std;
struct data{
    double units,charge;
    string name;
};
int main()
{
    int n;
    printf("no of users :");
    cin>>n;
    cin.ignore();
    data user[n];
    for(int i=0;i<n;i++)
    {
        cout<<"name of user :";
        getline(cin,user[i].name);
        cout<<"total units :";
        cin>>user[i].units;
        cin.ignore();
        
        if(user[i].units <= 100)
        {
            user[i].charge=user[i].units*60;
        }
        else if(user[i].units <= 300)
        {
            user[i].charge=6000 + ((user[i].units-100)*80);
        }
        else 
        {
            user[i].charge=6000 + 16000 + ((user[i].units-300)*90);
        }
        user[i].charge/=100;
        if(user[i].charge >= 300)
        {
            user[i].charge+=50;
        }
        user[i].charge+=(0.15*user[i].charge); 
    }
    for(int i=0;i<n;i++)
    {
        cout<<"name :"<<user[i].name<<endl<<"total charges :"<<user[i].charge<<endl;
    }
}