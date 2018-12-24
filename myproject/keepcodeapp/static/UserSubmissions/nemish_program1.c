#include<stdio.h>
int main()
{
    char s[10005], ch;
    int l, i, c=0;
    scanf("%s",&s);
    ch = getchar();
    ch = getchar();
    ch = getchar();
    l = strlen(s);
    for(i=0;i<l;i++)
    if(s[i]==ch)
    c++;
    if(c==2)
    printf("evenprime");
    else
    {
        for(i=2;i<c;i++)
        if((c%i)==0)
        break;
        if(i==c)
        printf("oddprime");
        else
        printf("notprime");
    }
    return 0;
} 
