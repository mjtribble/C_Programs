/*
 * Melody Tribble
 * CSCI 112 Lab 4
 * February 26, 2016
 */
#include <stdio.h>
#include <math.h> 
   
// displays user menu, reads input, and validates input
int user_menu();

// Equation functions that are pass by reference
void equation1(float *);            // calculate motion equation 1
void equation2(float *);            // calculate motion equation 2
void equation3(float *);            // calculate motion equation 3
void equation4(float *);            // calculate motion equation 4
    //
//User input functions return a value from user
float get_position_initial(void);   // Prompts user for x0
float get_position_final(void);     // Prompts user for xf
float get_velocity_initial(void);   // Prompts user for v0
float get_velocity_final(void);     // Prompts user for vf
float get_acceleration(void);       // Prompts user for a
float get_time(void);               // Prompts user for t

/*
 * This begins program
 */
int main(void)
{
    //print welcome message
    printf("Welcome to the MOTION EQUATION CALCULATOR\n\n");

    //Variable for the user choice menu.
    int user_choice;

    do
    {
        user_choice = user_menu();
        float result;
        
        switch (user_choice)
        {
            case 1:
                    equation1(&result);
                    break;
            case 2:
                    equation2(&result);
                    break;
            case 3:
                    equation3(&result);
                    break;
            case 4:
                    equation4(&result);
                    break;
            case 5:
                   printf("Thank you for using the MOTION EQUATION CALCULATOR. Goodbye.\n");
                    return 0;
                    break;
            default:
                    break; 
        }
        
        printf("Your result is %.4f.\n\n", result);
 
    }while(user_choice !=5);
    
    return 0;
}

// displays user menu, reads input, and validates input
int user_menu()
{
    int flag = 1;
    int i; //holds user input
    while(flag)
    {
        printf("Choose a motion equation 1-4 or choose 5 to QUIT > ");
        scanf("%d", &i);

        if(i<1 || i>5)
        {
            printf("Invalid Option. Please try again.\n\n");
        }else
        {
            break;
        }
     }
     return i;
}
/*
 * This calculates equation 1 the final velocity
 * @ parameter result pointer
 */
void equation1(float *vf)        
{
    float v0 = get_velocity_initial();
    float a = get_acceleration();
    float t = get_time();

    *vf = v0 + a * t;
}

/*
 * This calculates equation 2 the final position
 * @ parameter result pointer
 */
void equation2(float *pf)  
{
    float p0 = get_position_initial();
    float v0 = get_velocity_initial();
    float t = get_time();
    float a = get_acceleration();
    
    *pf = p0 + v0 * t + .5 * a * pow(t, 2);
}

/*
 * This calculates equation 3 the final velocity
 * @ parameter result pointer
 */
void equation3(float *vf)           
{
    float v0 = get_velocity_initial();
    float a = get_acceleration();
    float pf = get_position_final();
    float p0 = get_position_initial();

    *vf = sqrt(pow(v0, 2)+2*a*(pf - p0));
}

/*
 * This calculates equation 4 the final position
 * @ parameter result pointer
 */
void equation4(float *pf)           
{
    float p0 = get_position_initial();
    float vf = get_velocity_final();
    float v0 = get_velocity_initial();
    float t = get_time();

    *pf = p0 + .5 * (vf +v0) * t; 
}
/*
 * This asks the user for x0
 * @returns x0
 */
float get_position_initial(void)   // Prompts user for x0
{
    float i; //holds user input
    printf("\tEnter initial position > ");
    scanf("%f", &i);

    return i;
}

/*
 * This asks the user for xf
 * @returns xf
 */
float get_position_final(void)
{
    float i; //holds user input
    printf("\tEnter final position > ");
    scanf("%f", &i);

    return i;
}

/*
 * This asks the user for v0
 * @returns v0
 */
float get_velocity_initial(void)
{
    float i; //holds user input
    printf("\tEnter initial velocity > ");
    scanf("%f", &i);
 
    return i;

}

/*
 * This asks the user for vf
 * @returns vf
 */
float get_velocity_final(void)
{
    float i; //holds user input
    printf("\tEnter final velocity > ");
    scanf("%f", &i);
 
    return i;

}

/*
 * This asks the user for a
 * @returns a
 */
float get_acceleration(void)  
{
    float i; //holds user input
    printf("\tEnter acceleration > ");
    scanf("%f", &i);
    
    return i;

}

/*
 * This asks the user for t
 * @returns t
 */
float get_time(void)              
{
    float i; //holds user input
    printf("\tEnter time > ");
    scanf("%f", &i);

    return i;

}



