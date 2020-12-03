#include "viewRecords.h"
#include "startMatch.h"

/***********************************
*  MAIN SCREEN FOR VIEWING RECORDS *
************************************/
void viewRecords()
{
    int match_counter = 0;
    char teama[30] = "", teamb[30] = "";

    system("color 03");

    printf("\nEnter team A: ");
    fflush(stdin);
    scanf("%s", teama);
    printf("Enter team B: ");
    fflush(stdin);
    scanf("%s", teamb);

    match_counter = printList(teama, teamb, &match_counter);

    if (match_counter == 0)
    {
        noMatch();
    }
    else
    {
        matchesFound();
    }
}

/***********************************
* MATCHES PLAYED BETWEEN THE TEAMS *
************************************/
int printList(char *teama, char *teamb, int *match_counter)
{
    FILE *fp;
    FILE *nfp;
    date scanDate;
    char matchCode[5] = "";
    char scanTeama[30] = "", scanTeamb[30] = "";

    system("cls");
    system("color 03");

    fp = fopen("matches", "r");
    nfp = fopen("newList", "w");

    while (!(feof(fp)))
    {

        fscanf(fp, "%s %s %s %d/%d/%d", matchCode, scanTeama, scanTeamb, &scanDate.d, &scanDate.m, &scanDate.y);

        if (((strcmp(teama, scanTeama) == 0) && (strcmp(teamb, scanTeamb) == 0)) || ((strcmp(teama, scanTeamb) == 0) && (strcmp(teamb, scanTeama) == 0)))
        {
            (*match_counter)++;

            if ((*match_counter) == 1)
            {
                printf("\n******************************************************************************************\n");
                printf("\nMATCH CODE FIRST TEAM                     SECOND TEAM                   DATE\n\n");
            }

            printf("%-10s %-30s %-30s %2d/%2d/%2d\n", matchCode, teama, teamb, scanDate.d, scanDate.m, scanDate.y);
            fprintf(nfp, "%-10s %-30s %-30s %2d/%2d/%2d\n", matchCode, teama, teamb, scanDate.d, scanDate.m, scanDate.y);
        }
    }

    if ((*match_counter) != 0)
    {
        printf("\n******************************************************************************************\n");
    }

    fclose(nfp);
    fclose(fp);
    return (*match_counter);
}

/***********************************
*    IF NO MATCH HAS BEEN PLAYED   *
************************************/
void noMatch()
{
    int r;

    system("color 03");

    printf("No match has been played betweem these teams!!!\n");
    printf("\n********************\n        Press\n\n1 To enter again\n2 Return to main page\n********************\n\n");

    do
    {
        fflush(stdin);
        scanf("%d", &r);

        switch (r)
        {
        case 1:
            system("cls");
            viewRecords();
            break;
        case 2:
            start();
            break;
        default:
            printf("You have entered wrong number!!!\nEnter again: ");
            break;
        }
    } while (r != 1 && r != 2);
}

/***********************************
*      IF MATCHES ARE PLAYED       *
************************************/
void matchesFound()
{
    FILE *nfp;
    date matchDate;
    int codeCounter = 0;
    char matchCode[5], scanCode[5];
    char scanTeama[30], scanTeamb[30];

    system("color 03");

    nfp = fopen("newList", "r");

    printf("\nEnter the match code: ");
    fflush(stdin);
    scanf("%s", scanCode);

    while (!(feof(nfp)))
    {
        fscanf(nfp, "%s %s %s %d/%d/%d", matchCode, scanTeama, scanTeamb, &matchDate.d, &matchDate.m, &matchDate.y);
        if (strcmp(matchCode, scanCode) == 0)
        {
            fclose(nfp);
            codeCounter++;
            codeFound(matchCode);
            break;
        }
    }

    if (codeCounter == 0)
    {
        fclose(nfp);
        noCode();
    }
}

/***********************************
*    CORRECT CODE IS ENTERED       *
************************************/
void codeFound(char *matchCode)
{
    int r;
    char c;
    FILE *mfp;

    system("cls");
    system("color 03");

    mfp = fopen(matchCode, "r");

    while (!(feof(mfp)))
    {
        c = getc(mfp);
        putc(c, stdout);
    }

    fclose(mfp);

    printf("\n\n********************\n        Press\n\n1 To view another match\n2 Return to main page\n********************\n\n");

    do
    {
        fflush(stdin);
        scanf("%d", &r);

        switch (r)
        {
        case 1:
            system("cls");
            viewRecords();
            break;
        case 2:
            start();
            break;
        default:
            printf("You have entered wrong number!!!\nEnter again: ");
            break;
        }
    } while (r != 1 && r != 2);
}

/***********************************
*      WRONG CODE IS ENTERED       *
************************************/
void noCode()
{
    int r;

    system("color 03");

    printf("You have entered wrong match code!!!\n");

    printf("\n********************\n        Press\n\n1 To enter again\n2 Return to main page\n********************\n\n");

    do
    {
        fflush(stdin);
        scanf("%d", &r);

        switch (r)
        {
        case 1:
            matchesFound();
            break;
        case 2:
            start();
            break;
        default:
            printf("You have entered wrong number!!!\nEnter again:");
            break;
        }
    } while (r != 1 && r != 2);
}
