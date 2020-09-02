#include <math.h>
#include <string.h>
#include "dataPoints.h"

/* A struct to make sure we can get all the correct properties of our points*/
struct Points
{
    int *coordinates;
    char *identifier;
    double distance;
};
typedef struct Points Points;


/* Calculates the distance from input point*/
double distCalc(int* p1, int *p2)
{
    double distance = 0;
    int i;
    
    for (i = 0; i < 10; i++)
    {
         distance += pow(((double)p1[i] - (double)p2[i]), 2.0);
    }
    
    distance = sqrt(distance);
   
    return distance;
}

/* A funtion to make a point, based on inputarray, and the "input" for this specific point*/
Points makePoint(int input[10],int corrdinates[10], char *identifier)
{
    Points point;

    point.coordinates = corrdinates;
    point.identifier = identifier;
    point.distance = distCalc(input, corrdinates);

    return point;
}

/* Sorts our array of points, accending from closest to input point*/
int cmpFunc(const void *a, const void *b)
{
    Points *PointA = (Points *)a;
    Points *PointB = (Points *)b;

    if (PointA -> distance < PointB -> distance)
    {
        return -1;
    }
    
    else if (PointA -> distance > PointB -> distance)
    {
        return 1;
    }

    else
    {
        return 0;
    }
    
}

/* Takes the inputArray, requires array of [9] : Assigns the value of the answer to the correspoding index in the input array*/
void question(int arr[]){

    printf("Jeg oensker en uddannelse med hoejt matematisk indhold\n 4 - Helt enig\n 3 - Delvis enig\n 2 - Hverken enig eller uenig\n 1 - Delvis uenig\n 0 - Helt uenig\n");
    scanf(" %d", &arr[0]);

    printf("Jeg oensker min uddannelse indeholder naturvidenskablige fag som fx fysik og kemi\n 4 - Helt enig\n 3 - Delvis enig\n 2 - Hverken enig eller uenig\n 1 - Delvis uenig\n 0 - Helt uenig\n");
    scanf(" %d", &arr[1]);
    
    printf("Jeg oensker paa min uddannelse at der arbejdes med computerkode og algoritmer\n 4 - Helt enig\n 3 - Delvis enig\n 2 - Hverken enig eller uenig\n 1 - Delvis uenig\n 0 - Helt uenig\n");
    scanf(" %d", &arr[2]);
    
    printf("Jeg oensker at min uddannelse indeholder arbejde med hardware, som fx microelektronik og printboard\n 4 - Helt enig\n 3 - Delvis enig\n 2 - Hverken enig eller uenig\n 1 - Delvis uenig\n 0 - Helt uenig\n");
    scanf(" %d", &arr[3]);
    
    printf("Jeg oensker at bruge min kreativitet til at fremstille visuelle designs, animation eller arkitektoniske designs\n 4 - Helt enig\n 3 - Delvis enig\n 2 - Hverken enig eller uenig\n 1 - Delvis uenig\n 0 - Helt uenig\n");
    scanf(" %d", &arr[4]);
    
    printf("Jeg oensker at arbejde med softwaresystemer, servere, big data eller sikkerhed\n 4 - Helt enig\n 3 - Delvis enig\n 2 - Hverken enig eller uenig\n 1 - Delvis uenig\n 0 - Helt uenig\n");
    scanf(" %d", &arr[5]);
    
    printf("Jeg oensker at skabe nye loesninger og designs\n 4 - Helt enig\n 3 - Delvis enig\n 2 - Hverken enig eller uenig\n 1 - Delvis uenig\n 0 - Helt uenig\n");
    scanf(" %d", &arr[6]);
    
    printf("Jeg oensker at optimere eksisterende loesninger\n 4 - Helt enig\n 3 - Delvis enig\n 2 - Hverken enig eller uenig\n 1 - Delvis uenig\n 0 - Helt uenig\n");
    scanf(" %d", &arr[7]);
    
    printf("Jeg oensker at arbejde mere teoretisk end praktisk\n 4 - Helt enig\n 3 - Delvis enig\n 2 - Hverken enig eller uenig\n 1 - Delvis uenig\n 0 - Helt uenig\n");
    scanf(" %d", &arr[8]);
}

/* Needs to be rewritten, to allow for percentagewise difference*/
char* kPicker(Points Pointarr[], int k, Points inputPoint)
{
    int i, largest, buff = 0;

    int eduArr[15] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};


    for (i = 0; i < k; i++)
    {
        if (strcmp(Pointarr[i].identifier, "Datalogi") == 0)
        {
            eduArr[0]++;
        }
    
        else if (strcmp(Pointarr[i].identifier, "Datavidenskab") == 0)
        {
            eduArr[1]++;
        }

        else if (strcmp(Pointarr[i].identifier, "Informationsteknologi") == 0)
        {
            eduArr[2]++;
        }

        else if (strcmp(Pointarr[i].identifier, "Interaktionsdesign") == 0)
        {
            eduArr[3]++;
        }
        
        else if (strcmp(Pointarr[i].identifier, "Software") == 0)
        {
            eduArr[4]++;
        }
        
        else if (strcmp(Pointarr[i].identifier, "By-, Energi- og Miljoeplanlaegning") == 0)
        {
            eduArr[5]++;
        }

        else if (strcmp(Pointarr[i].identifier, "Geografi") == 0)
        {
            eduArr[6]++;
        }

        else if (strcmp(Pointarr[i].identifier, "Landinspektoervidenskab") == 0)
        {
            eduArr[7]++;
        }

        else if (strcmp(Pointarr[i].identifier, "Teknoantropologi") == 0)
        {
            eduArr[8]++;
        }

        else if (strcmp(Pointarr[i].identifier, "Arkitektur og design") == 0)
        {
            eduArr[9]++;
        }

        else if (strcmp(Pointarr[i].identifier, "Medialogi") == 0)
        {
            eduArr[10]++;
        }

        else if (strcmp(Pointarr[i].identifier, "Elektronik og IT") == 0)
        {
            eduArr[11]++;
        }

        else if (strcmp(Pointarr[i].identifier, "Internetteknologier og computersystemer") == 0)
        {
            eduArr[12]++;
        }

        else if (strcmp(Pointarr[i].identifier, "Produkt- og designpsykologi") == 0)
        {
            eduArr[13]++;
        }
        
        else if (strcmp(Pointarr[i].identifier, "Robotteknologi") == 0)
        {
            eduArr[14]++;
        }
    }

    largest = eduArr[0];

    for (i = 1; i < 15 ; i++)
    {
        if (largest < eduArr[i])
        {
            largest = eduArr[i];
            buff = i;
        }
    }
    
    switch (buff)
    {
    case 0:
        return "Datalogi";
        break;

    case 1:
        return "Datavidenskab";
        break;

    case 2:
        return "Informationsteknologi";
        break;

    case 3:
        return "Interaktionsdesign";
        break;

    case 4:
        return "Software";
        break;

    case 5:
        return "By-, Energi- og Miljoeplanlaegning";
        break;

    case 6:
        return "Geografi";
        break;

    case 7:
        return "Landinspektoervidenskab";
        break;

    case 8:
        return "Teknoantropologi";
        break;

    case 9:
        return "Arkitektur og design";
        break;

    case 10:
        return "Medialogi";
        break;

    case 11:
        return "Elektronik og IT";
        break;

    case 12:
        return "Internetteknologier og computersystemer";
        break;

    case 13:
        return "Produkt- og designpsykologi";
        break;

    case 14:
        return "Robotteknologi";
        break;

    default:
        return "Something went wrong";
        break;
    }

}

void createPointArr(Points PointArr[45], int inputarr[])
{
    PointArr[0] = makePoint(inputarr, datalogiarr1, "Datalogi");
    PointArr[1] = makePoint(inputarr, datalogiarr2, "Datalogi");
    PointArr[2] = makePoint(inputarr, datalogiarr3, "Datalogi");
    PointArr[3] = makePoint(inputarr, softwarearr1, "Software");
    PointArr[4] = makePoint(inputarr, softwarearr2, "Software");
    PointArr[5] = makePoint(inputarr, softwarearr3, "Software");
    PointArr[6] = makePoint(inputarr, datavidenskabarr1, "Datavidenskab");
    PointArr[7] = makePoint(inputarr, datavidenskabarr2, "Datavidenskab");
    PointArr[8] = makePoint(inputarr, datavidenskabarr3, "Datavidenskab");
    PointArr[9] = makePoint(inputarr, intdesignarr1, "Interaktionsdesign");
    PointArr[10] = makePoint(inputarr, intdesignarr2, "Interaktionsdesign");
    PointArr[11] = makePoint(inputarr, intdesignarr3, "Interaktionsdesign");
    PointArr[12] = makePoint(inputarr, infotekarr1, "Informationsteknologi");
    PointArr[13] = makePoint(inputarr, infotekarr2, "Informationsteknologi");
    PointArr[14] = makePoint(inputarr, infotekarr3, "Informationsteknologi");
    PointArr[15] = makePoint(inputarr, miljoearr1, "By-, Energi- og Miljoeplanlaegning");
    PointArr[16] = makePoint(inputarr, miljoearr2, "By-, Energi- og Miljoeplanlaegning");
    PointArr[17] = makePoint(inputarr, miljoearr3, "By-, Energi- og Miljoeplanlaegning");
    PointArr[18] = makePoint(inputarr, geografiarr1, "Geografi");
    PointArr[19] = makePoint(inputarr, geografiarr2, "Geografi");
    PointArr[20] = makePoint(inputarr, geografiarr3, "Geografi");
    PointArr[21] = makePoint(inputarr, landvidarr1, "Landinspektoervidenskab");
    PointArr[22] = makePoint(inputarr, landvidarr2, "Landinspektoervidenskab");
    PointArr[23] = makePoint(inputarr, landvidarr3, "Landinspektoervidenskab");
    PointArr[24] = makePoint(inputarr, tekantroarr1, "Teknoantropologi");
    PointArr[25] = makePoint(inputarr, tekantroarr2, "Teknoantropologi");
    PointArr[26] = makePoint(inputarr, tekantroarr3, "Teknoantropologi");
    PointArr[27] = makePoint(inputarr, arkdesignarr1, "Arkitektur og design");
    PointArr[28] = makePoint(inputarr, arkdesignarr2, "Arkitektur og design");
    PointArr[29] = makePoint(inputarr, arkdesignarr3, "Arkitektur og design");
    PointArr[30] = makePoint(inputarr, medialogiarr1, "Medialogi");
    PointArr[31] = makePoint(inputarr, medialogiarr2, "Medialogi");
    PointArr[32] = makePoint(inputarr, medialogiarr3, "Medialogi");
    PointArr[33] = makePoint(inputarr, elekitarr1, "Elektronik og IT");
    PointArr[34] = makePoint(inputarr, elekitarr2, "Elektronik og IT");
    PointArr[35] = makePoint(inputarr, elekitarr3, "Elektronik og IT");
    PointArr[36] = makePoint(inputarr, intcomarr1, "Internetteknologier og computersystemer");
    PointArr[37] = makePoint(inputarr, intcomarr2, "Internetteknologier og computersystemer");
    PointArr[38] = makePoint(inputarr, intcomarr3, "Internetteknologier og computersystemer");
    PointArr[39] = makePoint(inputarr, proddesignarr1, "Produkt- og designpsykologi");
    PointArr[40] = makePoint(inputarr, proddesignarr2, "Produkt- og designpsykologi");
    PointArr[41] = makePoint(inputarr, proddesignarr3, "Produkt- og designpsykologi");
    PointArr[42] = makePoint(inputarr, robottekarr1, "Robotteknologi");
    PointArr[43] = makePoint(inputarr, robottekarr3, "Robotteknologi");
    PointArr[44] = makePoint(inputarr, robottekarr2, "Robotteknologi");
}

void percentageCalc(Points PointArr[], Points inputPoint)
{
    int i, j = 0;
    double percentageDeviation;
    char buff[30] = "";

    for (i = 0; i < 45; i++)
    {
        if (strcmp(buff, PointArr[i].identifier) != 0 && j < 3)
        {
            percentageDeviation = (double)PointArr[i].distance / (double)PointArr[44].distance * 100.0;
            percentageDeviation = 100 - percentageDeviation;
            printf("Procent match for %s er %0.2f%%\n", PointArr[i].identifier, percentageDeviation);

            strcpy(buff, PointArr[i].identifier);            
            j++;
        }
    }

}