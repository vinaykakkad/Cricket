#include"startMatch1.h"
#include"viewRecords1.h"



void startMatch()
{
    int i;
    match newMatch;
    newMatch.battingTeam.runs=newMatch.battingTeam.wickets=newMatch.battingTeam.balls=newMatch.bowlingTeam.runs=newMatch.bowlingTeam.wickets=newMatch.bowlingTeam.balls=0;
    newMatch.innings=1;
    newMatch.battingTeam.order=newMatch.bowlingTeam.order=0;

    system("color 03");
    
    printf("\nEnter the name of the first team: ");
    fflush(stdin);
    scanf("%[^\n]s",newMatch.battingTeam.name);
    printf("Enter the name of the second team: ");
    fflush(stdin);
    scanf("%[^\n]s",newMatch.bowlingTeam.name);
    printf("Enter the venue of the match: ");
    fflush(stdin);
    scanf("%[^\n]s",newMatch.venue);
    printf("Enter the date of the match(dd/mm/yy): ");
    fflush(stdin);
    scanf("%d/%d/%d",&newMatch.match_date.d,&newMatch.match_date.m,&newMatch.match_date.y);
    printf("Enter the number of overs: ");
    fflush(stdin);
    scanf("%d",&newMatch.overs);

    system("cls");

    printf("\nEnter team %s\n\n",newMatch.battingTeam.name);
    for(i=0;i<11;i++)
    {
        printf("%-2d: ",i+1);
        fflush(stdin);
        scanf("%[^\n]s",newMatch.battingTeam.players[i].name);
        newMatch.battingTeam.players[i].out=0;
        newMatch.battingTeam.players[i].batRuns=0;
        newMatch.battingTeam.players[i].batBalls=0;
        newMatch.battingTeam.players[i].bowlRuns=0;
        newMatch.battingTeam.players[i].bowlBalls=0;
        newMatch.battingTeam.players[i].fours=0;
        newMatch.battingTeam.players[i].sixes=0;
        newMatch.battingTeam.players[i].wickets=0;
        newMatch.battingTeam.players[i].extras=0;
        newMatch.battingTeam.players[i].inAt=0;
        newMatch.battingTeam.players[i].overs=0;
        strcpy((newMatch.battingTeam.players[i].outType),"not out");
    }
    
    printf("\nEnter team %s\n\n",newMatch.bowlingTeam.name);
    
    for(i=0;i<11;i++)
    {
        printf("%-2d: ",i+1);
        fflush(stdin);
        scanf("%[^\n]s",newMatch.bowlingTeam.players[i].name);
        newMatch.bowlingTeam.players[i].out=0;
        newMatch.bowlingTeam.players[i].batRuns=0;
        newMatch.bowlingTeam.players[i].batBalls=0;
        newMatch.bowlingTeam.players[i].bowlRuns=0;
        newMatch.bowlingTeam.players[i].bowlBalls=0;
        newMatch.bowlingTeam.players[i].fours=0;
        newMatch.bowlingTeam.players[i].sixes=0;
        newMatch.bowlingTeam.players[i].wickets=0;
        newMatch.bowlingTeam.players[i].extras=0;
        newMatch.bowlingTeam.players[i].inAt=0;
        newMatch.bowlingTeam.players[i].overs=0;
        strcpy((newMatch.bowlingTeam.players[i].outType),"not out");
    }

    system("cls");
    viewTeams(&newMatch);
    afterViewing(&newMatch);
}

void viewTeams(match *newMatch)
{
    int i;

    system("color 03");
    
    printf("\n********************************    ********************************\n\n");
    printf("%-32s    %-32s\n\n",newMatch->battingTeam.name,newMatch->bowlingTeam.name);

    for(i=0;i<11;i++)
    {
        printf("%2d:%-30s   %2d:%-30s\n",i+1,newMatch->battingTeam.players[i].name,i+1,newMatch->bowlingTeam.players[i].name);
    }
    printf("********************************    ********************************\n\n");
}

void afterViewing(match *newMatch)
{
    int r;

    printf("\n********************\n        Press\n\n1 To make changes\n2 Continue\n3 Return to main page\n********************\n\n");

    do
    {
        fflush(stdin);
        scanf("%d",&r);
        
        switch(r)
        {
            case 1:
                editTeam(newMatch);
                break;
            case 2:
                system("cls");
                toss(newMatch);
                scoringMain(newMatch);
                break;
            case 3:
                system("cls");
                start();
                break;
            default:
                printf("You have entered wromg number!!!\nEnter again: ");
                break;
        }
    } while (r!=1 && r!=2 && r!=3);
}

void editTeam(match *newMatch)
{
    int r,no;
    char newPlayer[30];

    system("color 03");
    
    printf("\nEnter \n1 to edit %s \n",newMatch->battingTeam.name);
    printf("2 to edit %s \n\n",newMatch->bowlingTeam.name);

    do
    {
        fflush(stdin);
        scanf("%d",&r);
        
        switch(r)
        {
            case 1:
                printf("\nEnter the number of the player that you want to edit: ");
                fflush(stdin);
                scanf("%d",&no);
                printf("Enter the name of new player: ");
                fflush(stdin);
                scanf("%[^\n]s",newPlayer);
                strcpy(newMatch->battingTeam.players[no-1].name,newPlayer);
                break;
            case 2:
                printf("\nEnter the number of the player that you want to edit: ");
                fflush(stdin);
                scanf("%d",&no);
                printf("Enter the name of new player: ");
                fflush(stdin);
                scanf("%[^\n]s",newPlayer);
                strcpy(newMatch->bowlingTeam.players[no-1].name,newPlayer);
                break;
            default:
                printf("You have entered wrong number!!!\nEnter again: ");
                break;
        }
    } while (r!=1 && r!=2);

    printf("\n********************\n        Press\n\n1 To make more changes\n2 Continue\n3 View Teams\n********************\n\n");

    do
    {
        fflush(stdin);
        scanf("%d",&r);
        
        switch(r)
        {
            case 1:
                system("cls");
                viewTeams(newMatch);
                editTeam(newMatch);
                break;
            case 2:
                system("cls");
                toss(newMatch);
                scoringMain(newMatch);
                break;
            case 3:
                system("cls");
                viewTeams(newMatch);
                afterViewing(newMatch);
                break;
            default:
                printf("You have entered wrong number!!!\nEnter again: ");
                break;
        }
    } while (r!=1 && r!=2 && r!=3);
}

void toss(match *newMatch)
{
    system("color 03");

    printf("\nEnter the winner of the toss(%s/%s): ",newMatch->battingTeam,newMatch->bowlingTeam);
    fflush(stdin);
    scanf("%[^\n]s",newMatch->toss);    
    printf("Enter their decesion(bat/field): ");
    fflush(stdin);
    scanf("%s",newMatch->decision);

    if(strcmp(newMatch->battingTeam.name,newMatch->toss)==0 && strcmp(newMatch->decision,"bat")==0)
    {
    }
    else if (strcmp(newMatch->bowlingTeam.name,newMatch->toss)==0 && strcmp(newMatch->decision,"field")==0)
    {
    }
    else
    {
        changeTeam(&(newMatch->battingTeam),&(newMatch->bowlingTeam));
    }
    system("cls");
    options();
    rules(newMatch);
}

void options()
{
    system("color 03");
    
    printf("\n*******************************************\n");
    printf("runs     0-6 RUNS ARE SCORED\n");
    printf("w       WICKET\n");
    printf("nb      NO BALL\n");
    printf("wide    WIDE\n");
    printf("b       BYES\n");
    printf("lb      LEG-BYES\n");
    printf("cs      CHANGE STRIKE\n");
    printf("*******************************************\n");
}

void rules(match *newMatch)
{
    system("color 03");
    
    if((newMatch->overs)%5==0)
    {
        printf("\nA bowler can bowl a maximum of %d overs\n",(newMatch->overs)/5);
    }
     else
    {
        printf("\n%d bowler(s) can bowl a maximum of %d overs\n",(newMatch->overs)%5,((newMatch->overs)/5)+1);
        printf("%d bowler(s) can bowl a maximum of %d overs\n",5-((newMatch->overs)%5),((newMatch->overs)/5));
    }
}

void scoringMain(match *newMatch)
{

    startScoring(newMatch);
    system("cls");
    innings(newMatch);
    system("cls");
    
    printf("\nEND OF INNINGS!!\n\nPress any key to Continue");
    getch();
    changeTeam(&(newMatch->battingTeam),&(newMatch->bowlingTeam));
    newMatch->innings=2;
    system("cls");
    
    startScoring(newMatch);
    system("cls");
    innings(newMatch);
    system("cls");    
    printf("\nEND OF MATCH!!\n");
    
    if((newMatch->battingTeam.runs)>(newMatch->bowlingTeam.runs))
    {
        printf("\n%s WON!!!\n\n",(newMatch->battingTeam.name));
    }
    else if((newMatch->battingTeam.runs)<(newMatch->bowlingTeam.runs))
    {
        printf("\n%s WON!!!\n\n",(newMatch->bowlingTeam.name));
    }
    else
    {
        printf("\nMATCH TIED!!!\n");
    }

    matchEnd(newMatch);
}
void matchEnd(match *newMatch)  
{
    int r;
    int r1;
    FILE *fp=stdout;

    storeScore(newMatch);

    printf("\n********************\n        Press\n\n1 To view Scorecard\n2 To score new match\n3 To view records\n********************\n\n");
    do
    {
        fflush(stdin);
        scanf("%d",&r);
        
        switch(r)
        {
            case 1:
                system("cls");
                Scorecard(newMatch,fp);
                printf("\n********************\n        Press\n\n1 To score new match\n2 To view records\n3 Return to  main page\n********************\n\n");
                do
                {
                    fflush(stdin);
                    scanf("%d",&r);
        
                    switch(r)
                    {
                        case 1:
                            system("cls");
                            startMatch();
                            break;
                        case 2:
                            system("cls");
                            viewRecords();
                            break;
                        case 3:
                            start();
                            break;
                        default:
                            printf("You have entered wrong number!!!\nEnter again: ");
                            break;
                    }
                } while (r!=1 && r!=2 && r!=3);
                break;
            case 2:
                system("cls");
                startMatch();
                break;
            case 3:
                system("cls");
                viewRecords();
                break;
            default:
                printf("You have entered wrong number!!!\nEnter again: ");
                break;
        }
    } while (r!=1 && r!=2 && r!=3);
    
    
}

void storeScore(match *newMatch)
{
    FILE *count;
    FILE *matches;
    FILE *sc;
    int x;
    char mc[10]="";

    count=fopen("count","r");
    fscanf(count,"%d",&x);
    fclose(count);

    count=fopen("count","w");
    fprintf(count,"%d",(x+1));
    fclose(count);

    itoa((x+1),mc,10);
    
    matches=fopen("matches","a");
    fprintf(matches,"\n%-10s  %-30s   %-30s   %2d/%2d/%2d",mc,(newMatch->battingTeam.name),(newMatch->bowlingTeam.name),(newMatch->match_date.d),(newMatch->match_date.m),(newMatch->match_date.y));
    fclose(matches);

    sc=fopen(mc,"w");
    Scorecard(newMatch,sc);
    fclose(sc);

}

void Scorecard(match *newMatch,FILE *fp)
{
    /*printf("***********************************************************\n");
    printf("*************************SCORECARD*************************\n");
    printf("***********************************************************\n");
    */fprintf(fp,"\n**********************************************************\n");
    fprintf(fp,"%-30s  %3d-%-2d (%2d.%d)\n",newMatch->bowlingTeam.name,newMatch->bowlingTeam.runs,newMatch->bowlingTeam.wickets,(newMatch->bowlingTeam.balls)/6,(newMatch->bowlingTeam.balls)%6);
    fprintf(fp,"***********************************************************\n");
    fprintf(fp,"BATSMAN                                       R   B    4s 6s SR\n\n");
    for(int i=0;i<((newMatch->bowlingTeam.wickets)+2);i++)
    {      
        for(int j=0;j<11;j++)
        {
            if((i+1)==(newMatch->bowlingTeam.players[j].inAt))
            {
                fprintf(fp,"%-30s    %-10s  %-3d %-3d %2d %2d  %2.2f\n",(newMatch->bowlingTeam.players[j].name),(newMatch->bowlingTeam.players[j].outType),(newMatch->bowlingTeam.players[j].batRuns),(newMatch->bowlingTeam.players[j].batBalls),(newMatch->bowlingTeam.players[j].fours),(newMatch->bowlingTeam.players[j].sixes),((float)(newMatch->bowlingTeam.players[j].batRuns)/(newMatch->bowlingTeam.players[j].batBalls))*100);
                break;
            }
        }
    }
    fprintf(fp,"\nDID NOT BAT:\n");
    for(int i=0;i<11;i++)
    {
        if((newMatch->bowlingTeam.players[i].inAt)==0)
        {
            fprintf(fp,"%-s, ",(newMatch->bowlingTeam.players[i].name));
        }
    }
    fprintf(fp,"\n\n***********************************************************\n\n");
    fprintf(fp,"BOWLER                              O     R  W  E  ECO\n");
    for(int i=0;i<11;i++)
    {
        if((newMatch->battingTeam.players[i].overs)!=0)
        {
            fprintf(fp,"%-30s     %2d.%d %3d %2d %2d  %2.2f\n",(newMatch->battingTeam.players[i].name),(newMatch->battingTeam.players[i].bowlBalls)/6,(newMatch->battingTeam.players[i].bowlBalls)%6,(newMatch->battingTeam.players[i].bowlRuns),(newMatch->battingTeam.players[i].wickets),(newMatch->battingTeam.players[i].extras),((float)(newMatch->battingTeam.players[i].bowlRuns)/(newMatch->battingTeam.players[i].bowlBalls))*6);
        }
    }
    fprintf(fp,"\n***********************************************************\n");
    fprintf(fp,"\n***********************************************************\n\n");

    fprintf(fp,"***********************************************************\n");
    fprintf(fp,"%-30s  %3d-%-2d (%2d.%d)\n",newMatch->battingTeam.name,newMatch->battingTeam.runs,newMatch->battingTeam.wickets,(newMatch->battingTeam.balls)/6,(newMatch->battingTeam.balls)%6);
    fprintf(fp,"***********************************************************\n");
    fprintf(fp,"BATSMAN                                       R   B    4s 6s SR\n");
    
    for(int i=0;i<((newMatch->battingTeam.wickets)+2);i++)
    {      
        for(int j=0;j<11;j++)
        {
            if((i+1)==(newMatch->battingTeam.players[j].inAt))
            {
                fprintf(fp,"%-30s    %-10s  %-3d %-3d %2d %2d  %2.2f\n",(newMatch->battingTeam.players[j].name),(newMatch->battingTeam.players[j].outType),(newMatch->battingTeam.players[j].batRuns),(newMatch->battingTeam.players[j].batBalls),(newMatch->battingTeam.players[j].fours),(newMatch->battingTeam.players[j].sixes),((float)(newMatch->battingTeam.players[j].batRuns)/(newMatch->battingTeam.players[j].batBalls))*100);
                break;
            }
        }
    }
    fprintf(fp,"\nDID NOT BAT:\n");
    for(int i=0;i<11;i++)
    {
        if((newMatch->battingTeam.players[i].inAt)==0)
        {
            fprintf(fp,"%-s, ",(newMatch->battingTeam.players[i].name));
        }
    }
    
    fprintf(fp,"\n\n***********************************************************\n\n");

    fprintf(fp,"BOWLER                              O     R  W  E  ECO\n");
    for(int i=0;i<11;i++)
    {
        if((newMatch->bowlingTeam.players[i].overs)!=0)
        {
            fprintf(fp,"%-30s     %2d.%d %3d %2d %2d  %2.2f\n",(newMatch->bowlingTeam.players[i].name),(newMatch->bowlingTeam.players[i].bowlBalls)/6,(newMatch->bowlingTeam.players[i].bowlBalls)%6,(newMatch->bowlingTeam.players[i].bowlRuns),(newMatch->bowlingTeam.players[i].wickets),(newMatch->bowlingTeam.players[i].extras),((float)(newMatch->bowlingTeam.players[i].bowlRuns)/(newMatch->bowlingTeam.players[i].bowlBalls))*6);
        }
    }
    
    fprintf(fp,"\n***********************************************************\n");
    fprintf(fp,"\n***********************************************************\n");
    //printf("***********************************************************\n\n");
}
    
void startScoring(match *newMatch)
{
    system("color 03");
    
    int i;
    char nameOnstrike[30]="";
    char nameOffstrike[30]="";
    char nameBowler[30]="";

    printf("\n\nEnter the name of the opening batsmen(ON STRIKE): ");
    fflush(stdin);
    scanf("%[^\n]s",nameOnstrike);
        for(i=0;i<11;i++)
        {
            if(strcmp(nameOnstrike,(newMatch->battingTeam.players[i].name))==0)
            {
                (newMatch->onStrike)=&(newMatch->battingTeam.players[i]);
                (newMatch->battingTeam.order)++;
                (newMatch->onStrike->inAt)=(newMatch->battingTeam.order);
                break;
            }
        }

    printf("Enter the name of the opening batsmen(OFF STRIKE): ");
    fflush(stdin);
    scanf("%[^\n]s",nameOffstrike);
        for(i=0;i<11;i++)
        {
            if(strcmp(nameOffstrike,(newMatch->battingTeam.players[i].name))==0)
            {
                (newMatch->offStrike)=&(newMatch->battingTeam.players[i]);
                (newMatch->battingTeam.order)++;
                (newMatch->offStrike->inAt)=(newMatch->battingTeam.order);
                break;
            }
        }
    
    printf("\nEnter the name of the opening bowler: ");
    fflush(stdin);
    scanf("%[^\n]s",nameBowler);
        for(i=0;i<11;i++)
        {
            if(strcmp(nameBowler,(newMatch->bowlingTeam.players[i].name))==0)
            {
                (newMatch->currentBowler)=&(newMatch->bowlingTeam.players[i]);
                (newMatch->currentBowler->overs)=1;
                break;
            }
        }
}

void innings(match *newMatch)
{
    if((newMatch->innings)==1)
    {
        while(((newMatch->battingTeam.balls)<((newMatch->overs)*6)) && ((newMatch->battingTeam.wickets)<10))
        {
            ball(newMatch);
        }   
    }
    else if((newMatch->innings)==2)
    {
        while(((newMatch->battingTeam.balls)<((newMatch->overs)*6)) && ((newMatch->battingTeam.wickets)<10) && ((newMatch->battingTeam.runs)<=(newMatch->bowlingTeam.runs)))
        {
            ball(newMatch);
        }
    }
}
void ball(match *newMatch)
{
    char response[10]="";
    int buff=0;
    
        system("cls");
        Summary(newMatch);
        printf("\n");
        options();
        printf("\nEnter the code for last ball: ");
        fflush(stdin);
        scanf("%s",response);
        fflush(stdin);

        buff=0;
        do
        {
            if(strcmp(response,"runs")==0)
            {
                runs(newMatch);
                buff=1;
            }
            else if(strcmp(response,"w")==0)
            {
                w(newMatch);
                buff=1;    
            }
            else if(strcmp(response,"nb")==0)
            {
                nb(newMatch);
                buff=1;
            }
            else if(strcmp(response,"wide")==0)
            {
                wide(newMatch);
                buff=1;
            }
            else if(strcmp(response,"b")==0)
            {
                blb(newMatch);
                buff=1;
            }
            else if(strcmp(response,"lb")==0)
            {
                blb(newMatch);
                buff=1;
            }
            else if(strcmp(response,"cs")==0)
            {
                changeStrike((newMatch->onStrike),(newMatch->offStrike));
                buff=1;
            }
            else
            {
                printf("You have entered wrong code!!!\nEnter again: ");
                fflush(stdin);
                scanf("%s",response);
            }
        }
        while (buff!=1);

        if((newMatch->battingTeam.balls)%6==0)
        {
            if(((newMatch->battingTeam.balls)/6)==(newMatch->overs))
            {
                
            }
            else if((newMatch->innings)==2 && ((newMatch->battingTeam.runs)>(newMatch->battingTeam.runs)))
            {

            }
            else
            {
                printf("END OF OVER\n");
                (newMatch->currentBowler)=nextBowler(newMatch);
                (newMatch->currentBowler->overs)=1;
                changeStrike((newMatch->onStrike),(newMatch->offStrike));
            }
            
            
        }
}


void Summary(match *newMatch)
{
    if((newMatch->innings)==1)
    {
        printf("%-30s    %3d-%-2d (%2d.%d)\n\n",newMatch->battingTeam.name,newMatch->battingTeam.runs,newMatch->battingTeam.wickets,(newMatch->battingTeam.balls)/6,(newMatch->battingTeam.balls)%6);
        printf("BATSMAN                           R   B    4s 6s\n");
        printf("%-30s    %-3d %-3d %2d %2d\n",(newMatch->onStrike->name),(newMatch->onStrike->batRuns),(newMatch->onStrike->batBalls),(newMatch->onStrike->fours),(newMatch->onStrike->sixes));
        printf("%-30s    %-3d %-3d %2d %2d\n\n",(newMatch->offStrike->name),(newMatch->offStrike->batRuns),(newMatch->offStrike->batBalls),(newMatch->offStrike->fours),(newMatch->offStrike->sixes));
        printf("BOWLER                              O     R  W  E\n");
        printf("%-30s     %2d.%d %3d %2d %2d\n",(newMatch->currentBowler->name),(newMatch->currentBowler->bowlBalls)/6,(newMatch->currentBowler->bowlBalls)%6,(newMatch->currentBowler->bowlRuns),(newMatch->currentBowler->wickets),(newMatch->currentBowler->extras));
    }
    else if((newMatch->innings)==2)
    {
        printf("%-30s    %3d-%-2d (%2d.%d)      TARGET: %3d\n\n",newMatch->battingTeam.name,newMatch->battingTeam.runs,newMatch->battingTeam.wickets,(newMatch->battingTeam.balls)/6,(newMatch->battingTeam.balls)%6,(newMatch->bowlingTeam.runs)+1);
        printf("BATSMAN                           R   B    4s 6s\n");
        printf("%-30s    %-3d %-3d %2d %2d\n",(newMatch->onStrike->name),(newMatch->onStrike->batRuns),(newMatch->onStrike->batBalls),(newMatch->onStrike->fours),(newMatch->onStrike->sixes));
        printf("%-30s    %-3d %-3d %2d %2d\n\n",(newMatch->offStrike->name),(newMatch->offStrike->batRuns),(newMatch->offStrike->batBalls),(newMatch->offStrike->fours),(newMatch->offStrike->sixes));
        printf("BOWLER                              O     R  W  E\n");
        printf("%-30s     %2d.%d %3d %2d %2d\n",(newMatch->currentBowler->name),(newMatch->currentBowler->bowlBalls)/6,(newMatch->currentBowler->bowlBalls)%6,(newMatch->currentBowler->bowlRuns),(newMatch->currentBowler->wickets),(newMatch->currentBowler->extras));
    
    }
    
}

void changeTeam(team *battingTeam,team *bowlingTeam)
{
    team a;
    a=*battingTeam;
    *battingTeam=*bowlingTeam;
    *bowlingTeam=a;

}


void changeStrike(player *onStrike,player *offStrike)
{
    player k;
    k=*onStrike;
    *onStrike=*offStrike;
    *offStrike=k;
}

void runs(match *newMatch)
{
    int runs;
    printf("Enter the runs scored:");
    fflush(stdin);
    scanf("%d",&runs);

    newMatch->onStrike->batBalls+=1;
    newMatch->onStrike->batRuns+=runs;
    newMatch->currentBowler->bowlBalls+=1;
    newMatch->currentBowler->bowlRuns+=runs;
    newMatch->battingTeam.balls+=1;
    newMatch->battingTeam.runs+=runs;

    if(runs==4)
    {
        newMatch->onStrike->fours+=1;
    }
    else if(runs==6)
    {
        newMatch->onStrike->sixes+=1;
    }

    if(runs%2==0)
    {    
    }
    else
    {
        changeStrike((newMatch->onStrike),(newMatch->offStrike));
    }
    
}

void nb(match *newMatch)
{
    int runs;

    printf("Enter the runs scored off the bat: ");
    fflush(stdin);
    scanf("%d",&runs);

    newMatch->onStrike->batRuns+=runs;
    newMatch->onStrike->batBalls+=1;
    newMatch->currentBowler->bowlRuns+=(runs+1);
    newMatch->currentBowler->extras+=+1;
    newMatch->battingTeam.runs+=(runs+1);

    if(runs==4)
    {
        newMatch->onStrike->fours+=1;
    }
    else if(runs==6)
    {
        newMatch->onStrike->sixes+=1;
    }
    
    if(runs%2==0)
    {

    }
    else
    {
        changeStrike((newMatch->onStrike),(newMatch->offStrike));
    }
    
}

void wide(match *newMatch)
{
    int runs;
    
    printf("Enter the runs scored: ");
    fflush(stdin);
    scanf("%d",&runs);

    newMatch->currentBowler->bowlRuns+=(runs+1);
    newMatch->currentBowler->extras+=1;
    newMatch->battingTeam.runs+=(runs+1);

    if(runs%2==0)
    {

    }
    else
    {
        changeStrike((newMatch->onStrike),(newMatch->offStrike));
    }
}

void blb(match *newMatch)
{
    int runs;

    printf("Enter the runs scored: ");
    fflush(stdin);
    scanf("%d",&runs);

    newMatch->onStrike->batBalls+=1;
    newMatch->currentBowler->bowlBalls+=1;
    newMatch->battingTeam.runs+=runs;
    newMatch->battingTeam.balls+=1;

    if(runs%2==0)
    {

    }
    else
    {
        changeStrike((newMatch->onStrike),(newMatch->offStrike));
    }
}

void w(match *newMatch)
{
    int r=0;
    char dismissal[10]="";
    char name[30]="";
    
    printf("\nPress:\n 1. if the batsman was bowled\n 2. if the batsman was caught\n 3. if the batsman was stumped \n 4. if the batsman got runout\n\n");
    fflush(stdin);
    scanf("%d",&r);
    fflush(stdin);

    if(r>=1 && r<=3)
    {
        newMatch->onStrike->batBalls+=1;
        newMatch->currentBowler->bowlBalls+=1;
        newMatch->currentBowler->wickets+=1;
        newMatch->battingTeam.balls+=1;
        newMatch->battingTeam.wickets+=1;
    }
    
    do
    {
        switch(r)
        {
            case 1:
            {
                strcpy((newMatch->onStrike->outType),"Bowled");
                (newMatch->onStrike)=nextBatsman((newMatch->onStrike),newMatch);
                (newMatch->battingTeam.order)++;
                (newMatch->onStrike->inAt)=(newMatch->battingTeam.order);
                break;
            }
            case 2:
            {
                strcpy((newMatch->onStrike->outType),"Caught");
                (newMatch->onStrike)=nextBatsman((newMatch->onStrike),newMatch);
                (newMatch->battingTeam.order)++;
                (newMatch->onStrike->inAt)=(newMatch->battingTeam.order);
                break;
            }
            case 3:
            {
                strcpy((newMatch->onStrike->outType),"Stumped");
                (newMatch->onStrike)=nextBatsman((newMatch->onStrike),newMatch);
                (newMatch->battingTeam.order)++;
                (newMatch->onStrike->inAt)=(newMatch->battingTeam.order);
                break;
            }

            case 4:
            {
                newMatch->battingTeam.wickets+=1;
                runOut(newMatch);
                break;
            }
            default:
                printf("You have entered wrong number!!!\nEnter again: ");
                fflush(stdin);
                scanf("%d",&r);
                break;
        }
    }
    while(r!=1 && r!=2 && r!=3 && r!=4);
}

void runOut(match *newMatch)
{
    int r=0;
    char name[30]="";

    printf("Press\n 1.This was a normal delivery\n 2.This was a no-ball\n 3.This was a wide\n 4.This was a bye\n 5.This was a leg-bye\n");
    fflush(stdin);
    scanf("%d",&r);
    fflush(stdin);

    do
    {
        switch(r)
        {
            case 1:
            {
                runs(newMatch);
                break;
            }
            case 2:
            {
                nb(newMatch);
                break;
            }
            case 3:
            {
                wide(newMatch);
                break;
            }
            case 4:
            {
                blb(newMatch);
                break;
            }
            case 5:
            {
                blb(newMatch);
                break;
            }
            default:
                printf("You have entered wrong number!!!\nEnter again: ");
                fflush(stdin);
                scanf("%d",&r);
                break;
        }
    } while (r!=1 && r!=2 && r!=3 && r!=4 && r!=5);

    printf("Enter the name of the batsman who got runout: ");
    fflush(stdin);
    scanf("%[^\n]s",name);
    fflush(stdin);

    if(strcmp(name,(newMatch->onStrike->name))==0)
    {
        strcpy((newMatch->onStrike->outType),"run-out");
        (newMatch->onStrike)=nextBatsman((newMatch->onStrike),newMatch);
        (newMatch->battingTeam.order)++;
        (newMatch->onStrike->inAt)=(newMatch->battingTeam.order);
    }
    else
    {
        strcpy((newMatch->offStrike->outType),"run-out");
        (newMatch->offStrike)=nextBatsman((newMatch->onStrike),newMatch);
        (newMatch->battingTeam.order)++;
        (newMatch->offStrike->inAt)=(newMatch->battingTeam.order);            
    }
}

player* nextBatsman(player *new,match *newMatch)
{
    char name[30]="";

    printf("Enter the name of the next batsman: ");
    fflush(stdin);
    scanf("%[^\n]s",name);
    fflush(stdin);

    for(int i=0;i<11;i++)
    {
        if(strcmp(name,(newMatch->battingTeam.players[i].name))==0)
        {
            return(&(newMatch->battingTeam.players[i]));
            break;
        }
    }
}
player* nextBowler(match *newMatch)
{
    char name[30]="";

    printf("Enter the name of the next bowler: ");
    fflush(stdin);
    scanf("%[^\n]s",name);
    fflush(stdin);

    for(int i=0;i<11;i++)
    {
        if(strcmp(name,(newMatch->bowlingTeam.players[i].name))==0)
        {
            return &(newMatch->bowlingTeam.players[i]);
            break;
        }
    }
}

