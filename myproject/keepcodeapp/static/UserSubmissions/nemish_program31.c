#include<stdio.h>
#include<stdlib.h>
main()
{
    long long int t,n,k,i,j,index;
    scanf("%lld",&t);
    while(t--)
    {
        long long int y=0,f,p,g;
        scanf("%lld %lld",&n,&k);
        long long int a[k];
        for(i=0;i<k;i++)
        {
            a[i]=0;
        }
        for(i=0;i<n;i++)
        {
        scanf("%lld",&f);
        for(j=0;j<f;j++)
        {
            scanf("%lld",&g);
            for(p=0;p<k;p++)
            {
                if(a[p]==g)
                goto A;
            }
            a[y]=g;
            y++;
            A:;
    }
    if(a[y]==k)
    index=i+1;
}
if(a[y]==k && index==n)
printf("all\n");
else if(a[y]==k && index<n)
printf("some\n");
else
printf("sad\n");
}
}

