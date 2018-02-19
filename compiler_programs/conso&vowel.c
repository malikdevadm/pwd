
%%
[aeiouAEIOU] {printf("<v>\t");}
[a-z A-Z] {printf("<c>\t");}
%%
void main()
{
	printf("enter any string=\n");
	yylex();
}
