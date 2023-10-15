#include<stdio.h>
int main()
{
	int n,i,j,k,a[100];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        for(k=0;a[i]!=0;)
        {
            j=a[i]%10;
            k+=j;
            a[i]/=10;
        }
        a[i]=k;
    }
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}