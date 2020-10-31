#include <cstdlib>
#include <iostream>

using namespace std;

char x[9] = { '1','2', '3', '4', '5', '6', '7', '8', '9' };         //game board

void board()                                                        //display game board
{
    system("cls");

    cout << "     |     |     " << endl 
        << "  " << x[0] << "  |  " << x[1] << "  |  " << x[2] << endl
        << "_____|_____|_____" << endl
        << "     |     |     " << endl
        << "  " << x[3] << "  |  " << x[4] << "  |  " << x[5] << endl
        << "_____|_____|_____" << endl
        << "     |     |     " << endl
        << "  " << x[6] << "  |  " << x[7] << "  |  " << x[8] << endl
        << "     |     |     " << endl;
}

void rBoard()                                                       //resets the board
{
    for (int i = 0; i < 9; i++)
    {
        x[i] = '0' + i + 1;
    }
}

void move(char y)
{
    int n;
    bool empty = true;                                    //empty space flag


    do
    {
        cout << "select square: ";
        cin >> n;

        if (x[n - 1] != 'X' && x[n - 1] != 'O')                            //check is space empty
        {
            x[n - 1] = y;
            empty = true;
        }
        else
        {
            empty = false;
        }
    } while (!empty);                                 //loop as long as chosen spot not empty

    board();
}

bool checkWin(char b)                                        //checks if one side won
{
    if (x[0] == b && x[1] == b && x[2] == b)              //checks all wining scenarios
    {
        return true;
    }
    else if (x[3] == b && x[4] == b && x[5] == b )
    {
        return true;
    }
    else if (x[6] == b && x[7] == b && x[8] == b)
    {
        return true;
    }
    else if (x[0] == b && x[4] == b && x[8] == b)
    {
        return true;
    }
    else if (x[2] == b && x[4] == b && x[6] == b)
    {
        return true;
    }
    else if (x[0] == b && x[3] == b && x[6] == b)
    {
        return true;
    }
    else if (x[1] == b && x[4] == b && x[7] == b)
    {
        return true;
    }
    else if (x[2] == b && x[5] == b && x[8] == b)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void opponent()                                                 //randomly places Os
{
    bool i = true;
    while (i)                                                   //selects random open space
    {
        int y = rand() % 9;

        if (x[y] != 'X' && x[y] != 'O')                         //checks if space is open
        {
            x[y] = 'O';
            i = false;
        }
    }
}

int main()
{
    
    int s = 0;
    bool winX = false, winO = false, play = true;
    char sPlayer, pAgain;

    cout << "single player (y/n): ";                        //select single player
    cin >> sPlayer;


    if (sPlayer == 'y' || sPlayer == 'Y')                   //single player game loop
    {
        board();                                            //print the board
        while (play)
        {


            move('X');                                      //X moves

            winX = checkWin('X');                           //did X win
            if (winX)
            {
                cout << "Xs win" << endl << "play again? (y/n): ";          //play again?
                cin >> pAgain;
                
                if (pAgain == 'y' || pAgain == 'Y')         //reset to play again
                {
                    rBoard();                               //rest board
                    board();                                //reprint board
                    winX = false;                           //remove win flag
                }
                else                                        //dont play again
                {
                    play = false;
                    break;
                }

            }


            opponent();                                 //opponent moves
            board();                                    //print oponents move
            winO = checkWin('O');                       //checks is opponent won
            if (winO)
            {
                cout << "Os win" << endl << "play again? (y/n): ";
                cin >> pAgain;

                if (pAgain == 'y' || pAgain == 'Y')
                {
                    rBoard();                           //restes to play again
                    board();
                    winO = false;                       //resets win flag
                }
                else                                    //leave game
                {
                    play = false;
                    break;
                }

            }
        }
    }
    else                                                    //multiplayer game loop
    {
        board();
        
        while (play)                                        //game loop
        {
            move('X');                                      //X moves

            winX = checkWin('X');                           //did X win

            if (winX)
            {
                cout << "Xs win" << endl << "play again (y/n): ";
                cin >> pAgain;

                if (pAgain == 'Y' || pAgain == 'y')         //Play again ?
                {
                    rBoard();                               //reset game
                    board();
                    winX = false;
                }
                else                                        //leave game
                {
                    break;
                }
            }

            move('O');                                      //O moves

            winO = checkWin('O');                           //did O win

            if (winO)
            {
                cout << "Os win" << endl << "play again (y/n): ";
                cin >> pAgain;

                if (pAgain == 'Y' || pAgain == 'y')         //play again?
                {
                    rBoard();                               //reset the game
                    board();
                    winO = false;
                }
                else                                        //leave the game
                {
                    break;
                }
            }
        }
    }

    return 0;
}