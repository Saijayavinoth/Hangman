#include<stdio.h>
#include<stdlib.h>
char a[100],q[100],*ptr;
int i=0,tr=5;
void getquestion()
{
printf("enter the question.\n");
scanf("%[^\n]s",q);
}
void replacement()
{
	do
	{
	if(q[i]!=' ')
	a[i]='_';
	else
	a[i]=' ';
	i++;
	}while(q[i]!='\0');
}
void guess()
{
int j=0,k=1;
i=0;

	while(1)
	{
	printf("\n%s\n",a);
	printf("\nmake your guess by typing the letter\n");
	fflush(stdin);
	scanf("%c",ptr+i);
		for(j=0;j<i;j++)
		{
			if(ptr[i]==ptr[j])
			{
			printf("you have made this guess already");
			j=i;
			}
		}
		if(j==i)
		{
			for(j=0;a[j]!='\0';j++)
			{
				if(ptr[i]==q[j])
				{
				a[j]=q[j];
				k=2;
				}
			}
			if(k==1)
			{
			if(tr>1)
			printf("wrong guess. you can make only %d more wrong guesses. Beware! ur man at stake",--tr);
			else
			tr--;
			}
		k=1;j=0;
			for(j=0;a[j]!='\0'&&a[j]!='_';j++);
			if(a[j]=='\0')
			{
			printf("\n%s",a);
			printf("U have saved ur man ");
			
			break;
			}
			if(tr==0)
			{
			printf("u lost");
			break;
			}
		}
	i++;
	}
}				
int main()
{
ptr=(char*)malloc(100*sizeof(char));
getquestion();
replacement();
//guess();
guess();
return 0;
}
