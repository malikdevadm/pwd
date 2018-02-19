#include<stdio.h>
main ()
{
FILE *fp;
int s=0,flg=1;
char c;
fp = fopen("one.txt", "r");
c=getc(fp);
while(c!=EOF)
{
 switch(s)
 {
   case 0:if(c=='a')
	    s=1;
	    else if(c=='b')
	    s=0;
	    else
	    flg=0;
	    break;	
   case 1:if(c=='a')
	    s=2;
	    else if(c=='b')
	    s=0;
	    else
	    flg=0;
	    break;
   case 2:if(c=='a')
	    s=2;
	    else if(c=='b')
	    s=0;
	    else
	    flg=0;
            break;
 }
if(flg==0)
break;
c=getc(fp);
printf("%c,%d",c,flg);
}
if(flg==0)
{
printf("invalid string");
}
else if(s==2)
{
printf("Accepted");
}
else
{
printf("rejected");
}
fclose(fp);
}


