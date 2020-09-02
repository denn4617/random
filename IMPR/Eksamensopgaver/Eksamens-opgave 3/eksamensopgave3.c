/*    
 *     | Navn: Dennis Kilic                                                                         |
 *     | Gruppenummer: A317b                                                                        |
 *     | Studieretning: Software                                                                    |
 *     | Email: dkilia19@student.aau.dk                                                             |
 *     | Hjælp: Casper Benjamin Norspang hjalp med "comparator" funktionen(cnorsp19@student.auu.dk) |
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MATCHES 182
#define TEAMS 14

struct Match
{
    char weekday[3], teamHome[5], teamVisitor[5];
    int score_home, score_visitor, audience, hour, minute, day, month;
}; typedef struct Match Match;

struct Team
{
    char teamName[5];
    int scoredGoals, concededGoals, points;
}; typedef struct Team Team;

enum soccerTeams {VB, HOB, SDR, AaB, FCM, AGF, FCN, EFB, VEN, OB, FCK, ACH, RFC, BIF};

/* Prototype declaration */
void read_file(Match matches[], FILE *input_file);
void team_func(Team teams[]);
int comparator(const void *a, const void *b);
void home_value(int i, int team, Team teams[], Match matches[]);
void visitor_value(int i, int team, Team teams[], Match matches[]);
void teamscore_func(Team teams[], Match matches[]);
void scoreboard(Team teams[]);

int main(void)
{
    FILE *input_file;
    Team teams[TEAMS];
    Match matches[MATCHES];

    input_file = fopen("kampe-2018-2019.txt", "r");

    if (input_file == NULL)
    {
        perror("Error:");
        return(-1);   
    }
    read_file(matches, input_file);
    team_func(teams);
    teamscore_func(teams, matches);
    qsort(teams, TEAMS, sizeof(Team), comparator);
    scoreboard(teams);

    fclose(input_file);
    return 0;
}

void read_file(Match matches[], FILE *input_file)
{
    int i = 0;
    char str[75];

    while (!feof(input_file))
    {
        fgets(str, sizeof(str), input_file);
        sscanf(str, "%s %d/%d %d.%d %s - %s %d - %d %d", matches[i].weekday, &matches[i].day, &matches[i].month, &matches[i].hour, &matches[i].minute, matches[i].teamHome, matches[i].teamVisitor, &matches[i].score_home, &matches[i].score_visitor, &matches[i].audience);
        i++;
    }   
}

void team_func(Team teams[])
{
    strcpy(teams[VB].teamName,  "VB" );
    strcpy(teams[HOB].teamName, "HOB");
    strcpy(teams[SDR].teamName, "SDR");
    strcpy(teams[AaB].teamName, "AaB");
    strcpy(teams[FCM].teamName, "FCM");
    strcpy(teams[AGF].teamName, "AGF");
    strcpy(teams[FCN].teamName, "FCN");
    strcpy(teams[EFB].teamName, "EFB");
    strcpy(teams[VEN].teamName, "VEN");
    strcpy(teams[OB].teamName,  "OB" );
    strcpy(teams[FCK].teamName, "FCK");
    strcpy(teams[ACH].teamName, "ACH");
    strcpy(teams[RFC].teamName, "RFC");
    strcpy(teams[BIF].teamName, "BIF");
}

int comparator(const void *a, const void *b)
{
    Team *teamHome = (Team *)a;
    Team *teamVisitor = (Team *)b;

    if (teamVisitor -> points == teamHome -> points)
    {
        return((teamVisitor -> scoredGoals - teamVisitor -> concededGoals) - (teamHome -> scoredGoals - teamVisitor -> concededGoals));
    }else
    {
        return(teamVisitor -> points - teamHome -> points);
    } 
}

void home_value(int i, int team, Team teams[], Match matches[])
{
    teams[team].scoredGoals += matches[i].score_home;
    teams[team].concededGoals += matches[i].score_visitor;

    if (matches[i].score_home > matches[i].score_visitor)
    {
        teams[team].points += 3;
    }else if (matches[i].score_home == matches[i].score_visitor)
    {
        teams[team].points += 1;
    }   
}

void visitor_value(int i, int team, Team teams[], Match matches[])
{
    teams[team].scoredGoals += matches[i].score_visitor;
    teams[team].concededGoals += matches[i].score_home;

    if (matches[i].score_visitor < matches[i].score_home)
    {
        teams[team].points += 3;
    }else if (matches[i].score_home == matches[i].score_visitor)
    {
        teams[team].points += 1;
    }
}

void teamscore_func(Team teams[], Match matches[]) 
{
    int i;
    for (i = 0; i < MATCHES; i++)
    {
        if (strcmp(matches[i].teamHome,"VB") == 0)
        {
            home_value(i, VB, teams, matches);
        }
        if (strcmp(matches[i].teamVisitor,"VB") == 0)
        {
            visitor_value(i, VB, teams, matches);
        }
        if (strcmp(matches[i].teamHome,"HOB") == 0)
        {
            home_value(i, HOB, teams, matches);
        }
        if (strcmp(matches[i].teamVisitor,"HOB") == 0)
        {
            visitor_value(i, HOB, teams, matches);
        }
        if (strcmp(matches[i].teamHome,"SDR") == 0)
        {
            home_value(i, SDR, teams, matches);
        }
        if (strcmp(matches[i].teamVisitor,"SDR") == 0)
        {
            visitor_value(i, SDR, teams, matches);
        }
        if (strcmp(matches[i].teamHome,"AaB") == 0)
        {
            home_value(i, AaB, teams, matches);
        }
        if (strcmp(matches[i].teamVisitor,"AaB") == 0)
        {
            visitor_value(i, AaB, teams, matches);
        }
        if (strcmp(matches[i].teamHome,"FCM") == 0)
        {
            home_value(i, FCM, teams, matches);
        }
        if (strcmp(matches[i].teamVisitor,"FCM") == 0)
        {
            visitor_value(i, FCM, teams, matches);
        }
        if (strcmp(matches[i].teamHome,"AGF") == 0)
        {
            home_value(i, AGF, teams, matches);
        }
        if (strcmp(matches[i].teamVisitor,"AGF") == 0)
        {
            visitor_value(i, AGF, teams, matches);
        }
        if (strcmp(matches[i].teamHome,"FCN") == 0)
        {
            home_value(i, FCN, teams, matches);
        }
        if (strcmp(matches[i].teamVisitor,"FCN") == 0)
        {
            visitor_value(i, FCN, teams, matches);
        }
        if (strcmp(matches[i].teamHome,"EFB") == 0)
        {
            home_value(i, EFB, teams, matches);
        }
        if (strcmp(matches[i].teamVisitor,"EFB") == 0)
        {
            visitor_value(i, EFB, teams, matches);
        }
        if (strcmp(matches[i].teamHome,"VEN") == 0)
        {
            home_value(i, VEN, teams, matches);
        }
        if (strcmp(matches[i].teamVisitor,"VEN") == 0)
        {
            visitor_value(i, VEN, teams, matches);
        }
        if (strcmp(matches[i].teamHome,"OB") == 0)
        {
            home_value(i, OB, teams, matches);
        }
        if (strcmp(matches[i].teamVisitor,"OB") == 0)
        {
            visitor_value(i, OB, teams, matches);
        }
        if (strcmp(matches[i].teamHome,"FCK") == 0)
        {
            home_value(i, FCK, teams, matches);
        }
        if (strcmp(matches[i].teamVisitor,"FCK") == 0)
        {
            visitor_value(i, FCK, teams, matches);
        }
        if (strcmp(matches[i].teamHome,"ACH") == 0)
        {
            home_value(i, ACH, teams, matches);
        }
        if (strcmp(matches[i].teamVisitor,"ACH") == 0)
        {
            visitor_value(i, ACH, teams, matches);
        }
        if (strcmp(matches[i].teamHome,"RFC") == 0)
        {
            home_value(i, RFC, teams, matches);
        }
        if (strcmp(matches[i].teamVisitor,"RFC") == 0)
        {
            visitor_value(i, RFC, teams, matches);
        }
        if (strcmp(matches[i].teamHome,"BIF") == 0)
        {
            home_value(i, BIF, teams, matches);
        }
        if (strcmp(matches[i].teamVisitor,"BIF") == 0)
        {
            visitor_value(i, BIF, teams, matches);
        }   
    }
}

void scoreboard(Team teams[])
{
    int i;
    printf("|===================================================|\n");
    printf("|Team|   |Goals scored|   |Goals conceded|   |Points|");
    printf("\n|===================================================|\n");
    for (i = 0; i < TEAMS; i++)
    {
        printf("|%s\t\t  %d\t\t  %d\t\t  %d|\t\t\n", teams[i].teamName, teams[i].scoredGoals, teams[i].concededGoals, teams[i].points);
    }
    printf("|===================================================|\n");
}