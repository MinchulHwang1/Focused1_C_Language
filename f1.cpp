/*
* FILE : f1.cpp
* PROJECT : Focused 1
* PROGRAMMER : Minchul Hwang
* FIRST VERSION : 2023-01-09
* Description : This project is a program that receives two types of information (destination, flight time)
				from the user and puts them into a variable in a structure and outputs them.
				Dynamic allocation is included in the information received and the information stored in the structure.
* The functions in this file are used to fillFlightInfo() and printFlightInfo()
*/
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>

#define kDestinationString 30
#define kDateSting 30
#define kInfo 10
#define kCount 10
#define kTable 72
#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS


typedef struct { 
	char* destination;
	char* date;
}FlightInfo;


void fillFlightInfo(FlightInfo* pFlight, char des[], char dat[]);
void printFlightInfo(FlightInfo arrFlight[]);


int main() {

	int i = 0;
	FlightInfo flightInformation[kInfo] = { };       
	char destinationString[kDestinationString] = " ";
	char dateString[kDateSting] = " ";
	char* alloc_destinationInfo = NULL;
	char* alloc_dateInfo = NULL;

	//loop until user input information of flight
	for (i; i < kCount; i++) {
		int len_des = 0, len_dat = 0;
		printf("Please Input destination : ");
		fgets(destinationString, sizeof(destinationString), stdin);

		printf("Please Input Flight date : ");
		fgets(dateString, sizeof(dateString), stdin);

		len_des = strlen(destinationString);
		len_dat = strlen(dateString);

		if (len_des > 0 && len_dat > 0) {
			
			//the string which user input puts into malloc memory
			alloc_destinationInfo = (char*)malloc(sizeof(char) * (len_des)+1);
			alloc_dateInfo = (char*)malloc(sizeof(char) * (len_dat)+1);

			if (alloc_destinationInfo != NULL && alloc_dateInfo != NULL) {
				//put flight information into allocated memory
				strncpy(alloc_destinationInfo, destinationString, len_des + 1); 
				strncpy(alloc_dateInfo, dateString, len_dat + 1);
				fillFlightInfo(&flightInformation[i], alloc_destinationInfo, alloc_dateInfo);
			}

			else
				printf("There are errors!\n");
		}
	}

	printFlightInfo(flightInformation);

	free(alloc_destinationInfo);
	free(alloc_dateInfo);

	return 0;
}



/*
* Function : fillFlightInfo()
* Description : This function dynamically allocates the destination and time entered by the user and puts them into the FlightInfo structure.
* Parameters : Flight* pFlight : Structure with destination and flight time as fields. Stores the values ​​entered by the user.
*			   char des[] : An array that stores the destinations entered by the user.
*			   char dat[] : An array that stores the flight date entered by the user.
* Returns : None
*/
void fillFlightInfo(FlightInfo* pFlight, char des[], char dat[]) {

	int len_des = strlen(des);
	int len_dat = strlen(dat);
	
	//Allocating struct pointer memory
	pFlight->destination = (char*)malloc(sizeof(char) * (len_des)+1);
	pFlight->date = (char*)malloc(sizeof(char) * (len_dat)+1);

	
	if (pFlight->destination != NULL && pFlight->date != NULL) {
		
		strncpy(pFlight->destination, des, len_des + 1);
		strncpy(pFlight->date, dat, len_dat + 1);
		
	}
	else {
		printf("There are errors!\n");
	}
}




/*
* Function : printFlightInfo()
* Description : This function outputs the data stored in the structure.
* Parameters : FlightInfo arrFlight[] : A structure that stores data values ​​entered by the user.
* Returns : None
*/
void printFlightInfo(FlightInfo arrFlight[]) {
	int i = 0;
	char table[kTable] = {};
	char nothingDestinaion[] = "There is no destination";
	table[0] = ' ';
	printf("\n"); 
	printf("\n");

	for (i = 1; i < kTable; i++)
		table[i] = '-';
	for (i = 0; i < kTable; i++)
		printf("%c", table[i]);
	printf("\n");

	printf("%c%44s", '|',"Flight Schedule");
	printf("%28c\n", '|');

	for (i = 0; i < kTable; i++)
		printf("%c", table[i]);
	printf("\n");

	printf("%c%25s%11c", '|', "* Destination *", '|');
	printf("%21s%15c\n", "* Date *", '|');


	for (i = 0; i < kTable; i++)
		printf("%c", table[i]);
	printf("\n");

	for (i = 0; i < kCount; i++) {
		
		arrFlight[i].destination = strtok(arrFlight[i].destination, "\n");
		arrFlight[i].date = strtok(arrFlight[i].date, "\n");
		printf("|%-35s", arrFlight[i].destination);
		printf("|%-35s|\n", arrFlight[i].date);
	
	}

	for (i = 0; i < kTable; i++)
		printf("%c", table[i]);
	printf("\n");
}
