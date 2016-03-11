#include <stdio.h>

#define MAX_ARRAY_SIZE 50


int populate_array( int array[] );// Fill array with values from user.
void print_array( int array[], int n );// Print out the array values
void swap( int array[], int index1, int index2 );// Swap two array elements. 
void quicksort( int array[], int low, int high ); // Sorting algorithm
int partition( int array[], int low, int high ); // Find the partition point (pivot)

int main(void)
{
    int myArray[MAX_ARRAY_SIZE];//initializes array to size 50
    int n;//holds size of array
    n = populate_array(myArray);//gets user to enter values to sort, assigns size of array to n
    printf("The initial array contains:\n");
    print_array(myArray, n);//prints initial array
    quicksort(myArray, 0, n-1);//sorts array
    printf("The array is now sorted:\n");
    print_array(myArray, n); //prints sorted array

return(0);
}
/**
 * This fills the array with values from the user
 * @parameter int array to be filled
 * @return size of the array
 */
int populate_array( int array[] )
{
    int flag = 1;//set to true
    int i;//index
    int n;//size of array

    while(flag)//loop while true
    {
        printf("Enter the value of n > ");
       scanf("%d", &n);//sets array size
        if(n <= MAX_ARRAY_SIZE && n >= 0)//if array size is 0-max size
        {
            break;

        }else if(n<0)//user entered a negative number try again
        {
            printf("%d is less than zero. Please try again.\n\n", n);
        
        }else//user enters number larger than max size
        {
            printf("%d exceeds the maximum array size. Please try again.\n\n", n);

        }
    }
    printf("Enter %d integers (positive, negative, or zero) >\n", n);
    
    for(i=0;i<n;i++)//populates the array from user input
    {
        scanf("%d", &array[i]);   
    }
     
    return n;//returns array size
}

/**
 * This prints the array values
 * @parameter array and size
 */
void print_array( int array[], int n )
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%+5d\n", array[i]); 
    }
}

/**
 * This swaps two array elements
 *@parameter the array and two elements
 */
void swap( int array[], int index1, int index2 )
{
    int placeholder = array[index1];//holds value of index1
    array[index1] = array[index2];//assigns index2 value to index1
    array[index2] = placeholder;//assigns index1 value to index2
}

/**
 * This is the sorting algoritm
 * @parameter the array to be sorted and the substring low and high values
 */
void quicksort( int array[], int low, int high )
{
    int pivot;//value to sort around(pivot
    if(low<high)//double checks that low value is smaler than high value
    {
        pivot = partition(array, low, high);//calls partition with the sub array
        quicksort(array, low, pivot-1);//recursive function sorts low values
        quicksort(array, pivot+1, high);//recursive function sorts high values
    }
}

/**
 * This finds the partition point (pivot)
 * @parameter array and sub array
 * @ returns pivot value
 */
int partition( int array[], int low, int high )
{
    int pivot = array[high];//assigns pivot to highest subarray value
    int i = low-1;//makes sure low is the lowest
    int j;//index
    for(j=low;j<high;j++)
    {
        if (array[j]<= pivot)//if index is less or equal to the pivot swap low with index
        {
            i++;
            swap(array, i, j);
        }
    }
    swap(array, i+1, high);
    return i+1;
}



















