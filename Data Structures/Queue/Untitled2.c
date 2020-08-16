#include<stdio.h>
#include<stdlib.h>

int main()
{
    int x;
    scanf("%d",&x);
    int k=5;
    int product=1,sum=0;
    while(k--)
    {
        if(k%2!=0)
        {
            product*=(x%10);
        }
        else
        {
            sum+=x%10;
        }
        x=x/10;
    }
    printf("%d %d",sum,product);
}
