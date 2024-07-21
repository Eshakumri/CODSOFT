#include <iostream>
using namespace std;
char grid[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int row, column;
int choice;
char turns = 'x';
bool draw = false;
void display()
{

    system("cls");
    cout << "  Tic-Tac-Toe game" << endl;
    cout << "Player1 - x" << endl
         << "player2 - o" << endl;
    cout << "\t\t     |     |     " << endl;
    cout << "\t\t  " << grid[0][0] << "  |  " << grid[0][1] << "  |  " << grid[0][2] << endl;
    cout << "\t\t_____|_____|_____" << endl;
    cout << "\t\t     |     |     " << endl;
    cout << "\t\t  " << grid[1][0] << "  |  " << grid[1][1] << "  |  " << grid[1][2] << endl;
    cout << "\t\t_____|_____|_____" << endl;
    cout << "\t\t     |     |     " << endl;
    cout << "\t\t  " << grid[2][0] << "  |  " << grid[2][1] << "  |  " << grid[2][2] << endl;
    cout << "\t\t     |     |     " << endl;
}
void turn()
{
    if (turns == 'x')
    {
        cout << "player1[x] turn" << endl;
    }
    else
    {
        cout << "player2[o] turn" << endl;
    }
    cin >> choice;
    switch (choice)
    {
    case 1:
        row = 0;
        column = 0;
        break;
    case 2:
        row = 0;
        column = 1;
        break;
    case 3:
        row = 0;
        column = 2;
        break;
    case 4:
        row = 1;
        column = 0;
        break;
    case 5:
        row = 1;
        column = 1;
        break;
    case 6:
        row = 1;
        column = 2;
        break;
    case 7:
        row = 2;
        column = 0;
        break;
    case 8:
        row = 2;
        column = 1;
        break;
    case 9:
        row = 2;
        column = 2;
        break;
    default:
        cout << "Invalid choice" << endl;
        break;
    }
    if (turns == 'x' && grid[row][column] != 'x' && grid[row][column] != 'o')
    {
        grid[row][column] = 'x';
        turns = 'o';
    }
    else if (turns == 'o' && grid[row][column] != 'x' && grid[row][column] != 'o')
    {
        grid[row][column] = 'o';
        turns = 'x';
    }
    else
    {
        cout << "Non empty box  \n choose again" << endl;
        turn();
    }
}
bool gameover()
{
    for (int i = 0; i < 3; i++)
    {
        if (grid[i][0] == grid[i][1] && grid[i][0] == grid[i][2])
        {
            return false;
        }
    }
    if (grid[0][0] == grid[1][1] && grid[0][0] == grid[2][2])
    {

        return false;
    }
    if (grid[0][2] == grid[1][1] && grid[0][2] == grid[2][0])
    {

        return false;
    }
    for (int i = 0; i < 3; i++)
    {
        if (grid[0][i] == grid[1][i] && grid[0][i] == grid[2][i])
        {

            return false;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid[i][j] != 'x' && grid[i][j] != 'o')
            {
                return true;
            }
        }
    }
    draw = true;
    int again = true;
    return false;
}
void resetgrid()
{
    char initialgrid[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            grid[i][j] = initialgrid[i][j];
        }
    }
}
int main()
{
    int user = 1;

    while (user == 1)
    {
        resetgrid();
turns='x';
        while (gameover())
        {
            display();
            turn();
            display();
        }
        if (turns == 'x' && draw == false)
        {
            cout << "!!!!Congrats player2 won the match!!!!" << endl;
        }
        else if (turns == 'o' && draw == false)
        {
            cout << "!!!!Congrats player1 won the match!!!!" << endl;
        }
        else
        {
            cout << "!!!!Match is draw!!!!" << endl
                 << endl;
        }
        cout << endl<<endl<<"click\n-> play again(1) \n -> exit(0)";
        cin >> user;
    }
    return 0;
}