#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

/***********************************
*      RETURN TO MAIN SCREEN       *
************************************/
void start();

/***********************************
*  MAIN SCREEN FOR VIEWING RECORDS *
************************************/
void viewRecords();

/***********************************
* MATCHES PLAYED BETWEEN THE TEAMS *
************************************/
int printList(char *, char *, int *);

/***********************************
*    IF NO MATCH HAS BEEN PLAYED   *
************************************/
void noMatch();

/***********************************
*      IF MATCHES ARE PLAYED       *
************************************/
void matchesFound();

/***********************************
*    CORRECT CODE IS ENTERED       *
************************************/
void codeFound(char *);

/***********************************
*      WRONG CODE IS ENTERED       *
************************************/
void noCode();