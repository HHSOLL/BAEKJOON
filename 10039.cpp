#include <iostream>

using namespace std;

int main(void)
{
    int sum = 0;
    int grade = 0;

    for(int i=0;i<5;i++)
    {
        cin>>grade;
        if(grade<40)
        grade = 40;
        sum += grade;
    }

    cout<<sum/5<<endl;

    return 0;
}