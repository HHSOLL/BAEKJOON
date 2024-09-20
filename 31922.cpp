#include<iostream>

using namespace std;

int main(void)
{
    int a,p,c;
    cin>>a;
    cin>>p;
    cin>>c;

    if(a+c>p)
    {
        cout<<a+c<<endl;
    }
    else
    {
        cout<<p<<endl;
    }
    return 0;
}