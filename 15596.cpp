#include<iostream>


long long sum(int *a, int n);
int main(void)
{
    int n;
    std::cin>>n;

    int a[n];

    std::cout<<sum(a,n)<<std::endl;

    return 0;
}

long long sum(int *a, int n)
{
    long long sum=0;
    for(int i=0;i<n;i++)
    {
        std::cin>>a[i];
        sum+=a[i];
    }
    return sum;
}