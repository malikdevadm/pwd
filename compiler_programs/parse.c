#include<stdio.h>
void A();
void B();
int i=0;
char a;
FILE *fp;



void main()
{

fp=fopen("nikhil.txt","r");
a=fgetc(fp);
if(a=='a' || a=='b')
printf("S\n");
else
printf("wrong format \n");

if(a=='a')
{
a=fgetc(fp);
printf("aA \n");
A();
}
else if(a=='b')
{
a=fgetc(fp);
printf("bB \n");
B();
}
}


void A()
{

if(a=='a')
{a=fgetc(fp);
printf("aA \n");
A();
}
else
{
printf("B\n");
B();
}

}


void B()
{

if(a=='b')
{a=fgetc(fp);
printf("bB \n");
B();
}
else if(a=='d')
{
a=fgetc(fp);
printf("d \n");
}
else
printf("wrong input");

}

