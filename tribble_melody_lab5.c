#include <stdio.h>

#define MAX 12

int upc[MAX]= {0,0,0,0,0,0,0,0,0,0,0,0};//initialize array to zeros

void printArray(int []);//will print array values
void getInput(void);//will get the user's barcode
int sum_of_odd(int []);//will calculate the odd sum
int sum_of_even(int []);//will calculate the even sum
void check_digit(int []);//will calculate the check digit

/**
 * Melody Tribble
 * CSCI 112 - Barcode Validator
 * 02/29/16
 */
int main(void)
{   
    getInput();//retrieves values and fills the array
    printArray(upc);//prints array
    check_digit(upc);//makes calculations and determines if barcode is valid

return(0);
}
/**
 * This asks user for barcode and fills array with values
 */
void getInput(void)
{   
    int i;
    printf("Enter a bar code to check. Separate digits with a space >\n");
    
    for(i=0; i<MAX; i++)
    {   
        scanf("%d", &upc[i]);
    }
}
/**
 * This prints the array
 * @parameter is the array to print
 */
void printArray(int n[])
{
    int i;
    printf("\nYou entered the code:");
    for(i=0; i<MAX; i++)
    {
        printf(" %d", n[i]);
    }
    
    printf("\n");
}
/**
 * This calculates & prints the sum of the odd positions in the aray
 * @parameter integer array to calculate
 * @return the calculated sum
 */
int sum_of_odd(int n[])
{
    int odd_sum=0;
    int i;
    //adds the values in the odd indexes together
    for(i=0; i<MAX; i+=2)
    {
        odd_sum = n[i]+odd_sum;
    }
    odd_sum = odd_sum*3;
    printf("STEP 1: Sum of odds times 3 is %d\n", odd_sum);
    return odd_sum;
}

/**
 * This calculates, prints the sum of the even positions in the array
 * @parameter integer array to calculate
 * @return the calculated sum
 */
int sum_of_even(int n[])
{
    int even_sum=0;
    int i;
    //adds the values in the even indexes together
    for(i=1; i<MAX-1; i+=2)
    {
        even_sum = n[i]+even_sum;
    }
    printf("STEP 2: Sum of the even digits is %d\n", even_sum);

    return even_sum;
}
/**
 * This calculates the check digit to determine if the barcode is valid
 * @parameter integer array to validate
 */
void check_digit(int n[])
{
    int oddSum = sum_of_odd(n);
    int evenSum = sum_of_even(n);
    int checkSum = oddSum + evenSum;
    
    printf("STEP 3: Total sum is %d\n", checkSum);
    
    int checkDigit = checkSum%10;
        if(checkDigit != 0)
        {
            checkDigit = 10 - checkDigit;
        }  
    
    printf("STEP 4: Calculated check digit is %d\n", checkDigit);
    if(checkDigit == n[MAX-1])
    {
        printf("STEP 5: Check digit and last digit match\nBarcode is VALID.\n");
    }else
    {
        printf("STEP 5: Check digit and last digit do not match\nBarcode is INVALID.\n");
    }
}

