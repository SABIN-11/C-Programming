/*Imagine you are managing the information of the drivers in a travel agency daily. Take n numbers of drivers input.*/
/*Information must be following:
    1.Name
    2.Driving License Number:Eg(01-14-00012321)
    3.Route of the driver:Eg("Kathmandu -> Pokhara -> Chitwan -> Lumbini -> Kathmandu")
    4.Kms travelled in that day
    5.Car Model
*/
/*Your program must also print the data in a beautiful fashion*/
/*Use Structures*/

/*Toyota Fortuner

Consumption: 10 km/l (kilometers per liter)
Diesel Consumption per Kilometer: 0.1 liters/km

Hyundai Creta

Consumption: 18 km/l
Diesel Consumption per Kilometer: 0.0556 liters/km

Ford Endeavour

Consumption: 12 km/l
Diesel Consumption per Kilometer: 0.0833 liters/km*/

#include<stdio.h>
#include<string.h>
#include<ctype.h>

//defining n as 3 
#define n 3 //n=number of drivers
#define MAX_SIZE 100 //maximum size of the string

//diesel consumed per km
// #define toyotaFortuner 0.1f 
// #define hyundaiCreta 0.0556f
// #define fordEndeavour 0.0833f

typedef struct travelAgency{

    char name[n][MAX_SIZE];
    char drivingLicense[n][MAX_SIZE];
    char route[n][MAX_SIZE];
    float kms[n];   //kilometers travelled in a day
    char carModel[n][MAX_SIZE];
    char headers[5][MAX_SIZE];
    char ch;
}tA;    //travel agency

void inputOfDrivers(tA*);
void printingDriversData(tA*);

int main(){


    tA driversInfo={{""},{""},{""},{0.0f},{""},{"Name","License No","Route","Kms","Car model"},0};

    inputOfDrivers(&driversInfo);
    printingDriversData(&driversInfo);

    return 0;
}


void inputOfDrivers(tA *driversInfo){

    for(int i=0; i<n; i++){

        printf("Enter your name:");
        fgets(driversInfo->name[i],MAX_SIZE,stdin);
        driversInfo->name[i][strcspn(driversInfo->name[i],"\n")]='\0'; //null terminating the name

        printf("Enter your driving license:");
        fgets(driversInfo->drivingLicense[i],MAX_SIZE,stdin);
        driversInfo->drivingLicense[i][strcspn(driversInfo->drivingLicense[i],"\n")]='\0';  

        printf("Enter your today's route:");
        fgets(driversInfo->route[i],MAX_SIZE,stdin);
        driversInfo->route[i][strcspn(driversInfo->route[i],"\n")]='\0';

        printf("Enter the kilometers that you travelled today:");
        scanf("%f",&driversInfo->kms[i]);

        while(getchar()!='\n'); //clearing input buffer

    do{
        printf("What's your car's model(Toyota Fortuner,Hyundai Creta,Ford Endeavour)? ");
        printf("Enter 't' for toyota, 'h' for Hyundai and 'f' for ford:");
        
        driversInfo->ch=getchar();

        if(tolower(driversInfo->ch)=='t'){
        strcpy(driversInfo->carModel[i],"Toyota Fortuner");
        break;
        }
            
        else if(towlower(driversInfo->ch)=='h'){
        strcpy(driversInfo->carModel[i],"Hyundai Creta");
        break;
        }

        else if(towlower(driversInfo->ch)=='f'){
        strcpy(driversInfo->carModel[i],"Ford Endeavour");
        break;
        }
        
        else
        printf("Invalid input.\n");

    } while(1);

        printf("\n");

        while(getchar()!='\n');

    }

}

void printingDriversData(tA *driversInfo){

    FILE *fptr;
    
    fptr=fopen("Sabin Travel Agency.txt","w");  //creating file to write 

    fprintf(fptr, "+--------------------+----------------+-------------------+----------+-----------------+\n");
    fprintf(fptr, "| %-18s | %-14s | %-17s | %-8s | %-15s |\n", driversInfo->headers[0], driversInfo->headers[1], driversInfo->headers[2], driversInfo->headers[3], driversInfo->headers[4]);
    fprintf(fptr, "+--------------------+----------------+-------------------+----------+-----------------+\n");

    // Print records
    for (int i = 0; i < n; i++) {
        fprintf(fptr, "| %-18s | %-14s | %-17s | %-8.2f | %-15s |\n", driversInfo->name[i], driversInfo->drivingLicense[i], driversInfo->route[i], driversInfo->kms[i], driversInfo->carModel[i]);
    }

    // Print bottom border
    fprintf(fptr, "+--------------------+----------------+-------------------+----------+-----------------+\n");

    fclose(fptr);

}