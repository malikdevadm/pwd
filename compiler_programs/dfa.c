#include<stdio.h>
main ()
{
FILE *fp;
int s=0,flg=1;
char c;
fp = fopen("one.txt", "r");
c=getc(fp);
while(c!=EOF && c!='\n')
{
 switch(s)
 {
   case 0:if(c=='a')
	    s=1;
	    else if(c=='b')
	    s=3;
	    else
	    flg=0;
	    break;	
   case 1:if(c=='a')
	    s=1;
	    else if(c=='b')
	    s=2;
	    else
	    flg=0;
	    break;
   case 2:if(c=='a')
	    s=1;
	    else if(c=='b')
	    s=6;
	    else
	    flg=0;
            break;
   case 3:if(c=='a')
	    s=4;
	    else if(c=='b')
	    s=3;
	    else
	    flg=0;
	    break;	
   case 4:if(c=='a')
	    s=5;
	    else if(c=='b')
	    s=3;
	    else
	    flg=0;
	    break;
   case 5:if(c=='a')
	    s=5;
	    else if(c=='b')
	    s=3;
	    else
	    flg=0;
            break;
   case 6:if(c=='a')
	    s=1;
	    else if(c=='b')
	    s=6;
	    else
	    flg=0;
            break;
 }
if(flg==0)
break;
c=getc(fp);
}
if(flg==0)
{
printf("invalid string \n\n");
}
else if(s==2 || s==4)
{
printf("Accepted \n\n");
}
else
{
printf("rejected \n\n");
}
fclose(fp);
}


