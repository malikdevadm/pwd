#include<stdio.h>
int n,m=0,i=0,j=2;
char a[10][10],f[20],s[20];
struct priority
{
char sym;
int priority;
int asso;
}p[10];


void parse();
void main()
{
s[0]='$';
p[0].sym='+';
p[1].sym='-';
p[2].sym='*';
p[3].sym='/';
p[4].sym='d';
p[5].sym='$';
p[0].priority=1;
p[1].priority=1;
p[2].priority=2;
p[3].priority=2;
p[4].priority=5;
p[5].priority=0;
p[0].asso=1;
p[0].asso=0;
p[0].asso=1;
p[0].asso=1;
p[0].asso=2;
p[0].asso=0;

 int i,z;
 char c,ch;
 printf("Enter the no.of productions:");
 scanf("%d",&n);
 printf("Enter the productions(epsilon=$):\n");
 for(i=0;i<n;i++)
  {
scanf("%s%c",a[i],&ch);
}
printf("  + - * / id $ \n");
for(i=0;i<6;i++)
{
printf("%c ",p[i].sym);
for(j=0;j<6;j++)
{
if(p[i].priority>p[j].priority)
{
printf("> ");
}
else if(p[i].priority<p[j].priority)
{
printf("< ");
}
else{
printf("= ");
}
}printf("\n");
}





}


