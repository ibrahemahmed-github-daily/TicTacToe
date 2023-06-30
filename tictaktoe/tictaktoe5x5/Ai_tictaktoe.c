#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 5

char matrix[5][5];

// initiallizing the board
void init_matrix(void)
{
    int i, j;
    for (i = 0; i < SIZE; i++){
        for (j = 0; j < SIZE; j++)
        {
            matrix[i][j] = ' ';
        }
    }
       
        
}

// this function is to print the board
void print_matrix(void)
{
    system ("cls");
    printf("\n");
    printf("---------------------\n");
    for (int i = 0 ; i < SIZE ; i++)
    {

        printf("| %c | %c | %c | %c | %c |\n",matrix[i][0],matrix[i][1],matrix[i][2],matrix[i][3],matrix[i][4]);
        printf("---------------------\n");
    }
}

// this function determines if a move is valid
int move_is_valid(int row, int col)
{
    if ((row < 0) || (col < 0) || (row >= SIZE) || (col >= SIZE))
        return 0;
    else if (matrix[row][col] != ' ')
        return 0;
    else
        return 1;
}

// this function checks for a winning line
char three_in_a_row(char winner)
{
    int i;

    // check rows
    for (i = 0; i < SIZE; i++)
        if ((matrix[i][0] == matrix[i][1]) &&
        (matrix[i][1] == matrix[i][2]) &&
        (matrix[i][2] == matrix[i][3]) &&
        (matrix[i][3] == matrix[i][4]) &&
        (matrix[i][0] != ' '))

        winner = matrix[i][0];

    // check columns
    for (i = 0; i < SIZE; i++)
        if ((matrix[0][i] == matrix[1][i]) &&
        (matrix[1][i] == matrix[2][i]) &&
        (matrix[2][i] == matrix[3][i]) &&
        (matrix[3][i] == matrix[4][i]) &&
        (matrix[0][i] != ' '))

        winner = matrix[0][i];

    // test diagonals
    if ((matrix[0][0] == matrix[1][1]) &&
    (matrix[1][1] == matrix[2][2]) &&
    (matrix[2][2] == matrix[3][3]) &&
    (matrix[3][3] == matrix[4][4]) &&
    (matrix[0][0] != ' '))

    winner = matrix[0][0];

    if ((matrix[0][4] == matrix[1][3]) &&
    (matrix[1][3] == matrix[2][2]) &&
    (matrix[2][2] == matrix[3][1]) &&
    (matrix[3][1] == matrix[4][0]) &&
    (matrix[0][4] != ' '))

    winner = matrix[0][4];

    return winner;
}

// this function gets the human move
void get_player_move(void)
{
    int row, col;

    printf("Enter row (0 - 4): ");
    scanf("%d", &row);
    printf("Enter col (0 - 4): ");
    scanf("%d", &col);

    while (!move_is_valid(row, col))
    {
        printf("Invalid move, please try again.\n");


    printf("Enter row (0 - 4): ");
    scanf("%d", &row);
    printf("Enter col (0 - 4): ");
    scanf("%d", &col);
}

matrix[row][col] = 'X';

}


// this function gets the computer move
void get_computer_move(void)
{
    int row, col;


srand(time(NULL));

do
{
    row = rand() % SIZE;
    col = rand() % SIZE;
}
while (!move_is_valid(row, col));

printf("Computer chose row %d, col %d", row, col);


matrix[row][col] = 'O';

}


// main function to play the game
int main(void)
{
    char winner = ' ';
    init_matrix();
    printf("Tic Tac Toe - You are playing against the computer!\n");
    printf("Enter coordinates for your move (row col).\n");

    print_matrix();

    while (winner == ' ')
    {
    get_player_move();
    winner = three_in_a_row(winner);

    if (winner != ' ')
        break;

    get_computer_move();
    winner = three_in_a_row(winner);

    print_matrix();
}

if (winner == 'X')
    printf("You won!\n");
else if (winner == 'O')
    printf("Computer won!\n");
else
    printf("It's a tie!\n");

return 0;

}