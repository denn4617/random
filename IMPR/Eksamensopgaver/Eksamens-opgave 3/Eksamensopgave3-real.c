#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This is the struct i use for storing the lines from the .txt file, i store unnecceary data, as this is more conviniet*/
struct Match
{
    char day[3];
    int date;
    int month;
    int hours;
    int minutes;
    char team1[5];
    char team2[5];
    int goals1;
    int goals2;
    int audiencenumber;
}; typedef struct Match Match;

/* This is my struct for the teams, and all the important values*/
struct Team
{
    char name[5];
    int goal_score;
    int goals_against;
    int points;
}; typedef struct Team Team;

/* Here i enumerate the teams, for easier use later*/
enum teamsEnum {AaB, FCK, BIF, OB, FCN, AGF, RFC, HOB, EFB, VB, SDR, VEN, FCM, ACH};

void readData(FILE *inputFile, Match matches[]);
void makeTeams(Team teams[]);
void makeTeamScores(Match matches[], Team teams[]);
int cmpfunc(const void *a, const void *b);
void setValuesHome(int team, int i, Match matches[], Team teams[]);
void setValuesOut(int team, int i, Match matches[], Team teams[]);

int main(int argc, char const *argv[])
{
    /* Variable declaration */
    FILE *inputFile;
    int i = 0;
    Match matches[182];
    Team teams[14];

    /* Opening file for reading*/
    inputFile = fopen("kampe-2018-2019.txt", "r");

    /*Checking if the file has been correctly open*/
    if(inputFile == NULL)
    {
        printf("Something went wrong with opening of file, fix your code");
        exit(1);
    }

    readData(inputFile, matches);
    makeTeams(teams);
    makeTeamScores(matches, teams);
    qsort(teams, 14, sizeof(Team), cmpfunc);

    for ( i = 0; i < 14; i++)
    {
        printf("Team: %-3s | Goals Scored: %d | Goals scored aganist: %d | Points: %d\n", teams[i].name,
        teams[i].goal_score, teams[i].goals_against, teams[i].points);
    }
    

    fclose(inputFile);
    return 0;
}

/* I use this fuction to read data from our input file, and then store it correctly for futher proccessing */
void readData(FILE *inputFile, Match matches[])
{
    char buffersting[100];
    int i = 0;

    while (!feof(inputFile))
    {
        fgets(buffersting, sizeof(buffersting), inputFile);
        sscanf(buffersting, "%s %d/%d %d.%d %s - %s %d - %d %d", matches[i].day,
               &matches[i].date, &matches[i].month, &matches[i].hours, &matches[i].minutes, matches[i].team1, matches[i].team2,
               &matches[i].goals1, &matches[i].goals2, &matches[i].audiencenumber);

        i++;
    }
}

/* Here i put all the correct teamnames into my array of teams, that is the type of struct team*/ 
void makeTeams(Team teams[])
{
    strcpy(teams[AaB].name, "AaB");
    strcpy(teams[FCK].name, "FCK");
    strcpy(teams[BIF].name, "BIF");
    strcpy(teams[OB].name, "OB");
    strcpy(teams[FCN].name, "FCN");
    strcpy(teams[AGF].name, "AGF");
    strcpy(teams[RFC].name, "RFC");
    strcpy(teams[HOB].name, "HOB");
    strcpy(teams[EFB].name, "EFB");
    strcpy(teams[VB].name, "VB");
    strcpy(teams[SDR].name, "SDR");
    strcpy(teams[VEN].name, "VEN");
    strcpy(teams[FCM].name, "FCM");
    strcpy(teams[ACH].name, "ACH");
}

/* This function iterates over the matches, and asssigns the correct values to the teams based on the match */ 
void makeTeamScores(Match matches[], Team teams[])
{
    int i;
    for (i = 0; i < 182; i++)
    {
        if (strcmp(matches[i].team1, "AaB") == 0)
            setValuesHome(AaB, i, matches, teams);

        if (strcmp(matches[i].team2, "AaB") == 0)
            setValuesOut(AaB, i, matches, teams);

        if (strcmp(matches[i].team1, "FCK") == 0)
            setValuesHome(FCK, i, matches, teams);

        if (strcmp(matches[i].team2, "FCK") == 0)
            setValuesOut(FCK, i, matches, teams);

        if (strcmp(matches[i].team1, "BIF") == 0)
            setValuesHome(BIF, i, matches, teams);   

        if (strcmp(matches[i].team2, "BIF") == 0)
            setValuesOut(BIF, i, matches, teams);

        if (strcmp(matches[i].team1, "OB") == 0)
            setValuesHome(OB, i, matches, teams);

        if (strcmp(matches[i].team2, "OB") == 0)
            setValuesOut(OB, i, matches, teams);

        if (strcmp(matches[i].team1, "FCN") == 0)
            setValuesHome(FCN, i, matches, teams);

        if (strcmp(matches[i].team2, "FCN") == 0)
            setValuesOut(FCN, i, matches, teams);

        if (strcmp(matches[i].team1, "AGF") == 0)
            setValuesHome(AGF, i, matches, teams);

        if (strcmp(matches[i].team2, "AGF") == 0)
            setValuesOut(AGF, i, matches, teams);

        if (strcmp(matches[i].team1, "RFC") == 0)
            setValuesHome(RFC, i, matches, teams);

        if (strcmp(matches[i].team2, "RFC") == 0)
            setValuesOut(RFC, i, matches, teams);

        if (strcmp(matches[i].team1, "HOB") == 0)
            setValuesHome(HOB, i, matches, teams);

        if (strcmp(matches[i].team2, "HOB") == 0)
            setValuesOut(HOB, i, matches, teams);

        if (strcmp(matches[i].team1, "EFB") == 0)
            setValuesHome(EFB, i, matches, teams);

        if (strcmp(matches[i].team2, "EFB") == 0)
            setValuesOut(EFB, i, matches, teams);

        if (strcmp(matches[i].team1, "VB") == 0)
            setValuesHome(VB, i, matches, teams);

        if (strcmp(matches[i].team2, "VB") == 0)
            setValuesOut(VB, i, matches, teams);

        if (strcmp(matches[i].team1, "SDR") == 0)
            setValuesHome(SDR, i, matches, teams);

        if (strcmp(matches[i].team2, "SDR") == 0)
            setValuesOut(SDR, i, matches, teams);

        if (strcmp(matches[i].team1, "VEN") == 0)
            setValuesHome(VEN, i, matches, teams);

        if (strcmp(matches[i].team2, "VEN") == 0)
            setValuesOut(VEN, i, matches, teams);

        if (strcmp(matches[i].team1, "FCM") == 0)
            setValuesHome(FCM, i, matches, teams);

        if (strcmp(matches[i].team2, "FCM") == 0)
            setValuesOut(FCM, i, matches, teams);

        if (strcmp(matches[i].team1, "ACH") == 0)
            setValuesHome(ACH, i, matches, teams);

        if (strcmp(matches[i].team2, "ACH") == 0)
            setValuesOut(ACH, i, matches, teams);
    }
}

/* This is my sorting fuction, that primarily sorts by points, but if two teams has the same points, it sorts by goal diffirence*/
int cmpfunc(const void *a, const void *b)
{ 
    Team *team1 = (Team *)a;
    Team *team2 = (Team *)b;

    if (team2 -> points == team1 -> points)
        return((team2 -> goal_score - team2 -> goals_against) - (team1 -> goal_score - team2 -> goals_against));

    else
        return (team2 -> points - team1 -> points);
}

/* This is the fuction to assign the correct values from a match, if the team is team1 */ 
void setValuesHome(int team, int i, Match matches[], Team teams[])
{
    teams[team].goal_score += matches[i].goals1;
    teams[team].goals_against += matches[i].goals2;

    if (matches[i].goals1 > matches[i].goals2)
        teams[team].points += 3;

    else if (matches[i].goals1 == matches[i].goals2)
        teams[team].points += 1;
}

/* This is the fuction to assign the correct values from a match, if the team is team2 */ 
void setValuesOut(int team, int i, Match matches[], Team teams[])
{
    teams[team].goal_score += matches[i].goals2;
    teams[team].goals_against += matches[i].goals1;

    if (matches[i].goals1 < matches[i].goals2)
        teams[team].points += 3;

    else if (matches[i].goals1 == matches[i].goals2)
        teams[team].points += 1;
}