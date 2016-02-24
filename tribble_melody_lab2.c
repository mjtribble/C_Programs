
/*Melody Tribble
*CSCI 112 - Lab 2
*02/01/16
*/

#include <stdio.h>
#include <float.h>
#include <math.h>

/*Declares variables and functions*/
double max=DBL_MIN;
double min=DBL_MAX;
int i,n;
double average, std_dev, sum, sum_squares,range;
double getInput(void);
int getN(void);


/*
 * Main function, entry point to program
 */
int main(void)
{
	n=getN();
	for(i=0;i<n;i++){//iterates through n times

		double current = getInput();//sets current to the user's input
		sum += current;//adds up sum
		sum_squares += pow(current,2.0);//adds up sum of squares

		if (current <= min){//if less than sets to min
			min = current;
		}
		
		if(current>=max){//if greater than sets to max
			max = current;		
		}
	}//end for loop	
	//sets values to 0 if there are no numbers to input
	if (n==0){
		max = 0;
		min = 0;	
		average = 0;
		std_dev = 0;
		range = 0;
	
	}else{//make calculations for average,range, and std deviation
		average = sum/n;
		std_dev = sqrt((sum_squares/(double)n)-pow(average, 2.0));
		range = max - min;
	}//end if/else statement
	
	//prints output 
	printf(	"The Highest is: %.3f\n"
		"The Lowest is: %.3f\n"
		"The Average is: %.3f\n"
		"The Range is: %.3f\n"
		"The Standard deviation is: %.3f\n" , max, min, average,range, std_dev);
return(0);
}

/*
 *This asks the user for a number double
 * @return a value to be computed
 */
double getInput(void)
{
	double number =0;
	printf("Enter a number: ");
	scanf("%lf", &number);

	return number;
}

/*
 *This asks the user for a positive integer
 *@return The number of times user is prompted to enter a value 
 */
int getN(void)
{
	int num = -1;
	do{
		printf("Enter a value for N that is >= 0: ");
		scanf("%d", &num);
	 
		if(num<0){//if the number is less than 0, prints an error
			  //asks user to enter value again
			printf("Invalid value for N\n");
		}		
	}while(num<0);
	
	return num;
}
