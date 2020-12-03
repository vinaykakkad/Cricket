#include "viewRecords.h"
#include "startMatch.h"

void start()
{
    int r = 0;

    system("cls");
    system("color 03");

    printf("******************\n        Press\n\n1 To view records\n2 To start a match\n3 To exit\n******************\n\n");
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
            system("cls");
            startMatch();
            break;
        case 3:
            exit;
            break;
        default:
            printf("You have entered wrong number!!!!\nPlease enter again.\n\n");
            break;
        }

    } while (r != 1 && r != 2 && r != 3);
}

void main()
{
    start();
}
