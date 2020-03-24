#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>

typedef struct date
{
    int d,m,y;
}date;

typedef struct player
{
    char name[30];
    char outType[10];
    int out,inAt,overs;
    int batRuns,batBalls,fours,sixes;
    int bowlRuns,bowlBalls,wickets,extras/*,maidens*/;
}player;

typedef struct team
{
    char name[30];
    int balls,runs,wickets,order;
    player players[11];
    
}team;

typedef struct match
{
    team battingTeam,bowlingTeam;
    char venue[30];
    date match_date;
    int overs;
    char toss[30];
    char decision[5];
    int innings;
    player *onStrike;
    player *offStrike;
    player *currentBowler;    
}match;


void start();

void startMatch();

void viewTeams(match *);

void afterViewing(match *);

void editTeam(match *);

void toss(match *);

void options();

void rules(match *);

void scoringMain(match *);

void changeStrike(player * ,player *);

void changeTeam(team *,team *);

void runs(match *);

void nb(match *);

void wide(match *);

void blb(match *);

void w(match *);

void dirDismissal(match *);

void runOut(match *);

void startScoring(match *);

void innings(match *);

void ball(match *);

void Scorecard(match *);

player* nextBatsman(player *,match *);

player* nextBowler(match *);

void Summary(match *);

