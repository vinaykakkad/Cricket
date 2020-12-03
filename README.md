# Cricket

## Code
- css.c : Entry point
- viewRecords.c : Functions for viewing past records
- startMatch.c : Functions related to scoring a match and generating scorecard
- matches.txt: List of all the matches scored
- count.txt : Keeps the count of matches scored, to generate a unique code for new matches
- newList.txt : To display temporay data of matches between two selected teams 

## To compile and run
```sh
gcc startMatch.c viewRecords.c css.c -o a.exe
.\a.exe
```
