// CODE IS WORKING FINE

#include<stdio.h>
#include<string.h>

void find_first(int);
char nt[6][2],prod[6][10],ter[10],first[6][10];
int nt_num; 

void main()
{

	int n,k,i,j,prod_num, nt_prod;
	char sym,temp,first_no_dup[10];
	
	printf("enter the number of NTs: ");
	scanf("%d",&nt_num);	
	
	// loop to make first of each NT a Null String

	for(i=0;i<nt_num;i++)
			first[i][0]='\0';	
		
//loop to enter NTs andd thier productions.
//PS:convert this code so that NTs are fetched auto matically from productions
	for(i=0;i<nt_num;i++)
	{	

		scanf("%c",&temp);
		printf("enter the %d NT: ", i+1);
		
		scanf("%c",&nt[i][0]);
		nt[i][1]='F';
		printf("enter the rhs of productions seperated by '|' of %c. Ex: ab|cD|^\n ",nt[i][0]);
		scanf("%s",prod[i]);
	}

//enter terminal. PS:make a function to fetch terminal implicitly from productions
	printf("enter terminal lists: ");
	scanf("%s",ter);

//Display entered Production. PS: No need of this code
	printf("\nentered production are as follows:");
	for(i=0;i<nt_num;i++)
		printf("\n%d : %c -> %s",i+1,nt[i][0],prod[i]);

	for(i=0;i<nt_num;i++)
	{
		if(nt[i][1]=='F')
			find_first(i);
	}
	
// code to display first of NTs in a table form:
// show first without duplicate entries.consider the code after this segment.
	printf("\n   NT\t|\tFirst\n");
		printf("------------------------------");
	
	for(i=0;i<nt_num;i++)
	{
		printf("\n   %c\t|  {%s}\n",nt[i][0],first[i]);
		
	}
	printf("\n");

//code for first without duplicate entry if works make a function and 
//overwrite the global first with first_no_dup in the function
// code in test phase.
for(n=0;n<nt_num;n++)
{j=0;
	for(k=0;k<strlen(first[n]);k++)
	{
		if(j==0)
			
			first_no_dup[j++]=first[n][k];
		else
		{
				for(i=0;i<j;i++)
					if(first[n][k]==first_no_dup[i])
							break;
				if(i==j)
					first_no_dup[j++]=first[n][k];
		}
	}
	first_no_dup[j++]='\0';
	printf("\n**TEST: first of %c without duplicate= %s",nt[n][0],first_no_dup);
}

}// main() ends





void find_first(int index)
{
	int i,j,k,flag=0,test_flag=0,null_flag=0,len;
	char ch,temp_str[2]; //temp_str stores the null production
	
	printf("\n**TEST: index=%d :**\n",index);
	printf("\n**TEST: sym=%c :**\n",nt[index][0]);
	
	
	nt[index][1]='T';

//loop to read each character in the production of the current NT.
	for(j=0;prod[index][j]!='\0';j++)
	{
		
		
		flag=0;
	//check whether the production symbol is NULL or not.
	// PS: assuming the null will the last production in each NT change this code according to that. 
	//use strlen to check the last char is Null or not
		if(prod[index][j]=='^')
		{
			printf("\n**TEST: Null Prod found at: %d**\n",j+1);
			temp_str[0]='^';
		  temp_str[1]='\0';
			strcat(first[index],temp_str);
			return;
		}
		
		k=0;
		
		//code to check if the first symbol of a production is a terminal or not
		while(ter[k]!='\0')
		{
			
			if(prod[index][j]==ter[k])
			{
				printf("\n**TEST: Prod=%d starts with terminal=%c :**\n",j+1,ter[k]);
			  temp_str[0]=ter[k];
			  temp_str[1]='\0';
				flag=1;
				break;
			}
			k++;
		}
		
	// if first symbol is terminal then add it into first and move to next prod 
	//i.e. skip symbols in production string until '|' is not found

		if(flag==1)
		{
			printf("\n**TEST: terminal found moving to next Prod :**\n");
			//MERGE(first[index],ter[k]) 
			
			strcat(first[index],temp_str);
			printf("\n**TEST: First[%c] ={%s} :**\n",nt[index][0],first[index]);
			j++;
		//code to skipping the symbols of current production to get the first symbol of next production
			while(prod[index][j]!='|')
			{
			//if current prod. is the last one than '\0' will be encounter.
			//in that  return the first of NT 
				if(prod[index][j]=='\0')
				{
					//before returning first check if the null is true or not. if true add null symbol.	
					//code to check and add null symbol
					if(null_flag)
					{
						len=strlen(first[index]);
						printf("\n**TEST: len=%d",strlen(first[index]));
						first[index][len++]='^';
						first[index][len]='\0';
					}										// if(null_flag) ends

					return;
				} 										// if(prod[index][j]=='\0') ends
				j++;
				test_flag=1;
			}    										// while(prod[index][j]!='|') ends

			printf("\n**TEST: moved to next Prod :**\n");
		} // if(flag==1) ends
		else // it means prod[index][j]==non terminal
		{
			printf("\n**TEST: Prod=%d starts with Non-terminal=%c :**\n",j+1,prod[index][j]);
			k=0;
			for(i=0;i<nt_num;i++)
			{
				if(nt[i][0]==prod[index][j])
				{
					break;
				}			
			}
			
			if(nt[i][1]=='T')
			{
				printf("\n**TEST: for Non-terminal=%c first is already calculated**\n",nt[i][0]);
				printf("\n**TEST: first of %c=%s \tfirst of %c=%s :**\n",nt[index][0],first[index],nt[i][0],first[i]);
				strcat(first[index],first[i]);
				printf("\n**TEST: after merge first of %c=%s :**\n",nt[index][0],first[index]);
			}
			else
			{
				printf("\n**TEST: caculate first of %c :**\n",prod[index][j]);
		
				find_first(i);
				printf("\n**TEST: returned after caculating first of %c :**\n",prod[index][j]);
				printf("\n**TEST: first of %c=%s \tfirst of %c=%s :**\n",nt[index][0],first[index],nt[i][0],first[i]);
				strcat(first[index],first[i]);
				
				printf("\n**TEST: after merge first of %c=%s :**\n",nt[index][0],first[index]);
			}
			// code added after calcuating first without ^
			
			if(first[i][strlen(first[i])-1]=='^')
			{
				first[index][strlen(first[index])-1]='\0';
				// if statement to check whther the next symbol is | or not
				//
				if(prod[index][j+1]=='|')
				{

						j++; // moved to next production
						null_flag=1;
				}
				continue;
			}
			// code finished
			j++;
			while(prod[index][j]!='|')
			{
				if(prod[index][j]=='\0')
				{
					if(null_flag)
					{
						len=strlen(first[index]);
						printf("\n**TEST: len=%d",strlen(first[index]));
						first[index][len++]='^';
						first[index][len]='\0';
					}	
					return;
				}
				j++;
			}
		} 
	}
	// code added after calcuating first without ^
	printf("\n**TEST: null_Flag=%d",null_flag);
	
			// code ends
	//removing duplicate entry
	
}// first() close

