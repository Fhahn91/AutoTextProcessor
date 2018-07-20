/* Program that opens and scans a file containing automobile detail, uses user defined
 * structures and functions created to handle them. Program also displays data from file
 * in console windows
 */

 /* Written by Francis Hahn for COP-1220
  * Professor Galvis
  * 4/24/18
  * Homework #8: Auto Structure
  */

#include <stdio.h>
#include <stdlib.h>

/* Defining max size of strings */
#define NAMELENGTH 30
#define MaxCars 10

/* Structure for month day and year */
typedef struct
{
    int month,
        day,
        year;
}date_t;

/* Structure for gas tank capacity and amount full */
typedef struct
{
    double capacity,
           current;
}tank_t;

/* Structure for automobile */
typedef struct
{
    char make[NAMELENGTH],
         model[NAMELENGTH];
    int odometer;
    date_t manDate,
           purDate;
    tank_t gasTank;
}auto_t;

/* Prototypes */
int fscan_auto(FILE *filePlace, auto_t *getAuto);
int fscan_date(FILE *filePlace, auto_t *getAuto);
int fscan_tank(FILE *filePlace, tank_t *getTank);
void print_auto(auto_t getAuto);
void print_date(auto_t getAuto);
void print_tank(tank_t getTank);


/* Driver */
int main()
{
    /* printf("%s", "\nCheck1");
     * getch();
    */

    /* Declaring variables */
    auto_t scanHold[MaxCars];
    tank_t scanTank[MaxCars];

    int i,
        j;

    /* Opening file to be read for auto data */
    FILE *carData;
    carData = fopen("auto.txt", "r");

    /* printf("\n%s", "Check2");
     * getch();
     */

    /* Scanning and filling user-defined structure with data from file */
    for ( i = 0; i < MaxCars && fscan_tank(carData, &scanTank[i]) != EOF; i++)
    {
        fscan_auto(carData, &scanHold[i]);
        fscan_date(carData, &scanHold[i]);
        fscan_tank(carData, &scanTank[i]);
        /* printf("\n%s", "CheckScan");
         * getch();
         */
    }

    /* printf("\n%s", "CheckPastScan");
     * getch();
     */

    /* Displaying structure and table header */
    printf("\nMake\tModel\tOdometer\tManufacture Date\tPurchase Date\tTank Capacity and Contents");
    printf("\n---------------------------------------------------------------------------------------------------");
    for ( j = 0; j < i; j++)
    {
        print_auto(scanHold[j]);
        print_date(scanHold[j]);
        print_tank(scanTank[j]);
        /* printf("\n%s", "CheckPrint");
         * getch();
         */
    }
    /* Closing file with auto data */
    fclose(carData);
    getch();
    return(0);

}

/* Function that scans file and fills user defined structure with data */
int
fscan_date(FILE *filePlace, auto_t *getAuto)
{
    int result;
    /* printf("\n%s", "CheckDateScanEntry"); */
    result = fscanf(filePlace, " %d %d %d %d %d %d", &getAuto->purDate.month,
                                                     &getAuto->purDate.day,
                                                     &getAuto->purDate.year,
                                                     &getAuto->manDate.month,
                                                     &getAuto->manDate.day,
                                                     &getAuto->manDate.year);
    /* Checks if input was successful */
    if (result == 6)
        result = 1;
    else if (result != EOF)
        result = 0;
    /* printf("\n%s", "CheckDateScanExit"); */
    return(result);
}

/* Function that scans file and fills user defined structure with data */
int
fscan_tank(FILE *filePlace, tank_t *getTank)
{
    int result;
    /* printf("\n%s", "CheckTankScanEntry"); */
    result = fscanf(filePlace, " %lf %lf", &getTank->capacity,
                                           &getTank->current);
    /* Checks if input was successful */
    if (result == 2)
        result = 1;
    else if ( result != EOF)
        result = 0;
    /* printf("\n%s", "CheckTankScanExit"); */
    return(result);
}

/* Function that scans file and fills user defined structure with data */
int
fscan_auto(FILE *filePlace, auto_t *getAuto)
{
    /* printf("\n%s", "CheckAutoScanEntry");
     * getch();
     */

    int result;

    result = fscanf(filePlace, "%s %s %d",   getAuto->make,
                                             getAuto->model,
                                            &getAuto->odometer);
    /* Checks if input was successful */
    if (result == 3)
        result = 1;
    else if ( result != EOF)
        result = 0;


    /* printf("\n%s\t%s\t%d", getAuto->make,
     *                        getAuto->model,
     *                      getAuto->odometer);
     */

    /* printf("\n%s", "CheckAutoScanExit");
     * getch();
     */
    return(result);
}

/* Function that prints data from user-defined structure */
void
print_date(auto_t getAuto)
{
    printf("\t\t%d-%d-%d\t\t%d-%d-%d", getAuto.manDate.month,
                                       getAuto.manDate.day,
                                       getAuto.manDate.year,
                                       getAuto.purDate.month,
                                       getAuto.purDate.day,
                                       getAuto.purDate.year);
}

/* Function that prints data from user-defined structure */
void
print_tank(tank_t getTank)
{
    printf("\t%2.1f - %2.1f", getTank.capacity,
                                getTank.current);

}

/* Function that prints data from user-defined structure */
void
print_auto(auto_t getAuto)
{
    printf("\n%s\t%s\t%d", getAuto.make,
                           getAuto.model,
                           getAuto.odometer);
}
