/*
 * computes values based on an user input and a formula
 */
#include<stdio.h>
double x1, x2, x3, x4, x5;
double get_input(void);
double get_next(double a, double b);
void print_result();

int
main(void)
{
	x1 = get_input();/*assigns x1 & x2 to user input numbers*/
	x2 = get_input();
	x3 = get_next(x1, x2);
	x4 = get_next(x2, x3);
	x5 = get_next(x3, x4);
	print_result();
	
	return(0);
}

double get_input(void)/*prompts user for 2 inputs*/
{
	double i=0;
	printf("Enter a number ");
	scanf("%lf", &i);
	return i;
}

void print_result()/*prints result*/
{
	printf("The result is %.2f \n", x5);

}

double get_next(double a, double b)/*preforms calculation*/
{
	double xn = a / 2 + 3 * b;
	return xn;
}


