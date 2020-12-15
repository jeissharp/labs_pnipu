#include <iostream>
#include <conio.h>
using namespace std;

void count(int);

int main()
{
    int n;
    cout<<"Enter the needed number: ";
    cin>>n;
    cout<<"Enter the sequence (ends with 0): ";
    count(n);
    getch();
    return 0;
}

void count(int m)
{
    int k;
    static int number = 1;
    cin>>k;
    if (k == 0) cout<< "Search ended.";
    else 
    {
        if (k==m) cout << k <<  " is the "<<number<<endl;
        number++;
        count(m);   
    }
}

