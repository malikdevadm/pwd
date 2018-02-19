#include<stdio.h>
 
#define SIZE 10
void main()
{
	int i=0,j=3,nump;
	char p[5][SIZE];
	printf("enter number of production ");
	scanf("%d",&nump);
	printf("enter production ");
	 for(i=0;i<nump;i++)
	 {
	  scanf("%s",p[i]);
	 }
       printf("\n\nGRAMMER........");
     for(i=0;i<nump;i++)
    {
    printf("\n%s",p[i]);
        while(p[i][j]!=)
	{	
	if(p[i][0]==p[i][j])
	printf("grammer is recursive,,,production number=%d",i);
	else
	j++;
       } 
    }
}
