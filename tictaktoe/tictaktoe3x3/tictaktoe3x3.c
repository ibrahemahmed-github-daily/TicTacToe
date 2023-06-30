#include <stdio.h>
#include <stdlib.h>

#define No_Winner 'N'
#define player_one 'X'
#define player_two 'O'
#define CELL_BUSY 0xFE
#define INVALID_CELL 0xFF
#define cols 3

char playground [3][3]= {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
void render_playground (void);
int get_player_input (void);
char judge (void);

int main ()
{
    int num_empty_cells = 9;
    char winner = 0;
    char current_player = player_one;
    int choice = 0;
    int msg = 0 ;
    while (num_empty_cells != 0)
    {
        winner = judge();
        render_playground();
        if (msg == CELL_BUSY)
        {
            printf ("The selected cell is already selected before , please try another cell\n");
        }
        else if (msg == INVALID_CELL)
        {
            printf ("The selected cell is invalid , please try another cell\n");
        }
        if (winner != No_Winner)
        {
            printf("%c has won the game",winner);
            return 0;
        }
        msg = 0;
        choice = get_player_input ();
        if ((choice == CELL_BUSY )||(choice == INVALID_CELL))
        {
            msg = choice;
        }
        else
        {
            playground[choice/10 -1][choice%10 -1] = current_player;
            current_player = current_player == player_one ? player_two : player_one;
            num_empty_cells-- ;
        }

    }

    return 0;
}

void render_playground (void)
{

    system ("cls");
    printf("\n");
    printf("-------------\n");
    for (int i = 0 ; i < cols ; i++)
    {

        printf("| %c | %c | %c |\n",playground[i][0],playground[i][1],playground[i][2]);
        printf("-------------\n");
    }

}
int get_player_input (void)
{
    int choice ;
    scanf("%d",&choice);
    switch (choice)
    {
    case 11:
    case 12:
    case 13:
    case 21:
    case 22:
    case 23:
    case 31:
    case 32:
    case 33:
        if (playground[(choice/10) -1][(choice%10) -1] != ' ')
        {
            return CELL_BUSY;
        }
        break;
    default:
        return INVALID_CELL;
        break;
    }
    return choice;

}
char judge (void)
{
    char winner = No_Winner ;

    // Diagonal Checking :

    if ((playground[0][0] == playground [1][1])&& (playground[2][2] == playground [1][1]))
    {
        if (playground[1][1] !=' ')
        {
            winner =  playground[1][1];
        }
    }
    if ((playground[0][2] == playground [1][1])&& (playground[2][0] == playground [1][1]))
    {
        if (playground[1][1] !=' ')
        {
            winner =  playground[1][1];
        }
    }

    // Rows & Colums Checking :

    for (int i = 0 ; i < cols ; i++)
    {
        // ROWs :

        if ((playground[i][0] == playground [i][1])&& (playground[i][2] == playground [i][1]))
        {
            if (playground[i][0] != ' ')
            {
                winner = playground[i][0];
            }
        }
        // Cols :

        if ((playground[0][i] == playground [1][i])&& (playground[2][i] == playground [1][i]))
        {
            if (playground[0][i] != ' ')
            {
                winner = playground[0][i];
            }
        }
    }
    return winner;
}
