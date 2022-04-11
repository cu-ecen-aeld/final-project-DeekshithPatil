#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h>

#include "user_interface.h"

#define MIN_NUMBER_OF_LOADS                     1
#define MAX_NUMBER_OF_LOADS                     9

#define MIN_MODE_NUMBER                         0
#define MAX_MODE_NUMBER                         3

#define MODE_TOGGLE                             0
#define MODE_SET_RESET_ONLY                     1
#define MODE_SET_RESET_DURATION                 2
#define MODE_SET_RESET_INSTANT                  3

#define RESET                                   0
#define SET                                     1

#define MAX_HOURS                               23
#define MAX_MINUTES                             59
#define MAX_SECONDS                             59

static int get_load_number(void);
static int get_mode_number(void);
static int get_set_reset_val(void);
static int get_duration_seconds(void);
static void get_time_instant(char *instant);

void get_user_data(char *transmit_buffer)
{
    int val;
    int duration;
    char instant[20];

    int load = get_load_number();

    int mode = get_mode_number();

    printf("Load number = %d\n",load);
    printf("Mode = %d\n",mode);

    if(mode == MODE_TOGGLE)
    {
        // NO more data is needed 
        sprintf(transmit_buffer,"%d,%d;",load,mode);
    }

    else if(mode == MODE_SET_RESET_ONLY)
    {
        val = get_set_reset_val();
        sprintf(transmit_buffer,"%d,%d,%d;",load,mode,val);
    }

    else if(mode == MODE_SET_RESET_DURATION)
    {
        val = get_set_reset_val();
        duration = get_duration_seconds();
        sprintf(transmit_buffer,"%d,%d,%d,%d;",load,mode,val,duration);
    }

    else if(mode == MODE_SET_RESET_INSTANT)
    {
        val = get_set_reset_val();
        get_time_instant(instant);
        sprintf(transmit_buffer,"%d,%d,%d,%s;",load,mode,val,instant);
    }

    return;
}

/*
* Brief - Used to get the fourth paramter in the packet that needs to be transmitted, i.e instant of time
* Is called only when mode is MODE_SET_RESET_INSTANT
*/
static void get_time_instant(char *instant)
{
    int hours;
    int minutes;
    int seconds;

    printf("\n************* Instant **************\n");
    
    //Get hours
    while(1)
    {
        printf("Enter the hours: \n");
        scanf("%d",&hours);

        if(hours > MAX_HOURS)
        {
            printf("Invalid entry. Hours cannot be greate than %d\n",MAX_HOURS);
        }

        else
        {
            break;
        }
    }

    //Get minutes
    while(1)
    {
        printf("Enter the minutes: \n");
        scanf("%d",&minutes);

        if(minutes > MAX_MINUTES)
        {
            printf("Invalid entry. Minutes cannot be greater than %d\n",MAX_MINUTES);
        }

        else
        {
            break;
        }
    }

    //Get seconds
    while(1)
    {
        printf("Enter the seconds: \n");
        scanf("%d",&seconds);

        if(seconds > MAX_SECONDS)
        {
            printf("Invalid entry. Seconds cannot be greater than %d\n",MAX_SECONDS);
        }

        else
        {
            break;
        }
    }

    sprintf(instant,"%d:%d:%d",hours,minutes,seconds);

    return;
}

/*
* Brief - Used to get the fourth paramter in the packet that needs to be transmitted, i.e duration
* Is called only when mode is MODE_SET_RESET_DURATION
*/
static int get_duration_seconds(void)
{
    int number;
    
    printf("\n************* Duration **************\n");

    while(1)
    {
        printf("Enter the duration in seconds\n");

        scanf("%d",&number);

        if(number < 0)
        {
            printf("Invalid entry. Duration should be greater than 0\n");
        }

        else
        {
            break;
        }
    }

    return number;
}


/*
* Brief - Used to get the third parameter in the packet that needs to be transmitted, i.e set / reset (or On / Off)
*/
static int get_set_reset_val(void)
{
    int number;

    printf("\n************* Set/Reset **************\n");

    while(1)
    {
        printf("Enter 1 for set (ON) or 0 for reset (0)\n");

        scanf("%d",&number);

        if((number != SET) && (number != RESET))
        {
            printf("Invalid entry. Entry should either be a 0 or 1\n");
        }

        else
        {
            break;
        }
    }

    return number;
}


/*
* Brief - Used to get the second parameter in the packet that needs to be transmitted, i.e mode of control
* The following are the modes in which the load can be controlled
* 0 - Togle the current state of the load
* 1 - Set / Reset the electrical load
* 2 - Set / Reset the electrical load for a specific duration of time
* 3 - Set / Reset the electrical load at a particular instant of time
*
* NOTE: Here Set / Reset refers to Turning the load On / Off
*/
static int get_mode_number(void)
{
    char mode[5];
    int number;

    printf("\n************* Mode of Control **************\n");
    printf("0 - Togle the current state of the load\n");
    printf("1 - Set / Reset the electrical load\n");
    printf("2 - Set / Reset the electrical load for a specific duration of time\n");
    printf("3 - Set / Reset the electrical load at a particular instant of time\n");

    while(1)
    {
        printf("Enter the required mode of control: \n");
        scanf("%4s",mode); //Scan upto 4 digits only

        number = atoi(mode);

        if((number < MIN_MODE_NUMBER) || (number > MAX_MODE_NUMBER))
        {
            printf("Invalid Entry. Please make sure that the entered number is between %d and %d inclusive. \n",MIN_MODE_NUMBER,MAX_MODE_NUMBER);
        }

        else
        {
            break;
        }

    }

    return number;
    
}


/*
* Brief - Used to get the first parameter in the packet that needs to be transmitted, i.e Load number
*/
static int get_load_number(void)
{
    char load[5];
    int number;
    printf("\n************* Load Control **************\n");

    while(1)
    {
        printf("Enter the number of the load to be controlled: \n");
        scanf("%4s", load); //Scan upto 4 digits only   
        
        number = atoi(load);

        if(number > MAX_NUMBER_OF_LOADS)
        {
            printf("Sorry. The maximum number allowed is %d. Please try again!\n",MAX_NUMBER_OF_LOADS);
        }

        else if(number < MIN_NUMBER_OF_LOADS)
        {
            printf("Sorry. The minimum number allowed is %d. Please try again!\n",MIN_NUMBER_OF_LOADS);
        }

        else
        {
            break;
        }
    }
    
    return number;
}