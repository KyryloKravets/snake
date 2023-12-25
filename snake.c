#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

void printfield()
{
    char* array[5][5] = {{"⬜", "⬜", "⬜", "⬜", "⬜"},
                         {"⬜", "⬜", "⬜", "⬜", "⬜"},
                         {"⬜", "⬜", "⬛", "⬜", "⬜"},
                         {"⬜", "⬜", "⬜", "⬜", "⬜"},
                         {"⬜", "⬜", "⬜", "⬜", "⬜"}};
}

void place()
{
    char input[1];
    bool condition = true;
    bool spawn_apple = true;
    srand(time(NULL));
    short x1 = 2; // vertical axis of a snake
    short y1 = 2; // horizontal axis of a snake
    short x2 = rand() % 4; // vertical axis of an apple
    short y2 = rand() % 4; // horizontal axis of an apple
    char apple;
    char *w_move;
    char *s_move;
    char *a_move;
    char *d_move;

    char* array[5][5] = {{"⬜", "⬜", "⬜", "⬜", "⬜"},
                         {"⬜", "⬜", "⬜", "⬜", "⬜"},
                         {"⬜", "⬜", "⬛", "⬜", "⬜"},
                         {"⬜", "⬜", "⬜", "⬜", "⬜"},
                         {"⬜", "⬜", "⬜", "⬜", "⬜"}};
    
    array[x2][y2] = "🍏";

    while(condition)
    {
    if(array[x1][y1] == array[x2][y2])
        {
            x2 = rand() % 4;
            y2 = rand() % 4;
            array[x2][y2] = "🍏";
        }

    for(int i = 0; i < 5; i++)
        {
            for(int j = 0; j < 5; j++)
            {
                printf("%s", array[i][j]);
            }
            printf("\n");
        }
    scanf("%s", input);
    //check if substring-move exits and its direction
    w_move = strstr(input, "w");
    s_move = strstr(input, "s");
    a_move = strstr(input, "a");
    d_move = strstr(input, "d");
    //move up
    if(input == w_move && x1 != 0)
    {
        array[x1][y1] = "⬜";
        x1 = x1 - 1;
        array[x1][y1] = "⬛";
    }else if(input == w_move &&x1 == 0)
    {
        array[x1][y1] = "⬜";
        x1 = 4;
        array[x1][y1] = "⬛";
    }
    //move down
    if(input == s_move && x1 != 4)
    {
        array[x1][y1] = "⬜";
        x1 = x1 + 1;
        array[x1][y1] = "⬛";
    }else if(input == s_move && x1 == 4)
    {
        array[x1][y1] = "⬜";
        x1 = 0;
        array[x1][y1] = "⬛";
    }
    //move left
    if(input == a_move && y1 != 0)
    {
        array[x1][y1] = "⬜";
        y1 = y1 - 1;
        array[x1][y1] = "⬛";
    }else if(input == a_move && y1 == 0)
    {
        array[x1][y1] = "⬜";
        y1 = 4;
        array[x1][y1] = "⬛";
    }
    //move right
    if(input == d_move && y1 != 4)
    {
        array[x1][y1] = "⬜";
        y1 = y1 + 1;
        array[x1][y1] = "⬛";
    }else if(input == d_move && y1 == 4)
    {
        array[x1][y1] = "⬜";
        y1 = 0;
        array[x1][y1] = "⬛";
    }
    }
    
}


int main()
{
    //printf("\n");
    place();
    return 0;
}

