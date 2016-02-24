/**
 * Melody Tribble
 * CSCI 112 - Program0
 * 02/11/2016
 **/
#include <stdio.h>

int get_input(void);
int is_valid(int);
void print_pattern(int);
/*
 * program starts here
 */
int
main(void)
{
	int input;//will hold the user's response
	input = get_input();
	print_pattern(input);
	return(0);
}
/*
 * This asks the user for a specific number 
 * @return an odd integer from 1-9
 */
int get_input(void)
{
	int input;//will hold the user's input
	int flag;//will flag the end of the while loop when 0
	
	
	//will keep asking the user for a number until the flag is 0
	do
	{
		printf("Enter an odd number less than or equal to 9 and greater than 0 > ");
		scanf("%d", &input);//stores number in the variable input
		flag = is_valid(input);//calls the is_valid() method and assigns flag a 0 for true or 1 for false
	}
	while(flag!=0);	 	
	//returns valid number 
	return input;
}
/*
 *This checks if the user's input is valid
 *@parameter user's number
 *@return 0 or 1 int
 */
int is_valid(int num)
{
	if(num>9)//User's number is greater than 9
	{
		printf("You have entered a number greater than 9. Please try again.\n\n");	
		return 1;//returns false
	}else if(num<=0)//User's number is less than 1
	{
		printf("You have entered a number less than 1. Please try again.\n\n");
		return 1;//returns false
	}else if(num%2==0)//User's number is even
	{
		printf("You have entered an even number. Please try again.\n\n");
		return 1;//returns false	
	}else//it is a valid entry
	{
		return 0;//returns true
	}
}
/*
 *This prints a diamond with numbers
 *@parameter an odd number between 1 and 9
 */
void print_pattern(int num)
{
	int i;//counter for number of lines
	printf("\n");//adds a space
	for(i=1; i<=num; i+=2){//increments by two until it reaches user's number
		printf("%*s", num-i, "");//creates appropriate number of spaces for diamond shape
		int j=1;//counter for one line
		while(j<=i)
		{
			printf("%d ",j);//prints 1- i
			j++;//increments by 1
		}
		printf("\n");//moves to next line
	}
	for(i=num-2; i>0; i-=2){//prints bottom half of diamond, opposite of above	
		printf("%*s", num-i, "");
		int j=1;
		while(j<=i)
		{			
			printf("%d ",j);
			j++;
		}
		printf("\n");
	}	
}



















