#include <stdio.h>
#include <conio.h>
#include <time.h>
extern int x, y, fruitx, fruity, flag, game_end, score, height, width;
extern int piece, tailx[100], taily[100];
void record()
{
    char plname[20], nplname[20], cha, c;
    int i, j, px;
    FILE *info;
    info = fopen("record.txt", "a+");
    system("cls");
    printf("Enter your name\n");
    scanf("%[^\n]", plname);

    for (j = 0; plname[j] != '\0'; j++)
    {
        nplname[0] = toupper(plname[0]);
        if (plname[j - 1] == ' ')
        {
            nplname[j] = toupper(plname[j]);
            nplname[j - 1] = plname[j - 1];
        }
        else
            nplname[j] = plname[j];
    }
    nplname[j] = '\0';

    time_t mytime;
    mytime = time(NULL);
    fprintf(info, "Player Name :%s\n", nplname);
    fprintf(info, "Played Date:%s", ctime(&mytime));
    fprintf(info, "Score:%d\n", score); // Use the score variable instead of px
    for (i = 0; i <= 50; i++)
        fprintf(info, "%c", '_');
    fprintf(info, "\n");
    fclose(info);

    printf("Wanna see past records press 'y'\n");
    cha = getch();
    system("cls");
    if (cha == 'y')
    {
        info = fopen("record.txt", "r");
        do
        {
            putchar(c = getc(info));
        } while (c != EOF);
    }
    fclose(info);
}