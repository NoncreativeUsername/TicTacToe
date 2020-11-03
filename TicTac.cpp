#include <cstdlib>
#include <iostream>

char x[9] = { '1','2', '3', '4', '5', '6', '7', '8', '9' };         //game board spaces

void move(char y);                                                  //player move function

void board();                                                       //display game board

void rBoard();                                                      //resets the board

int checkWin(char b, int turn);                                     //checks if one side won, accepts either 'X' or 'O' and the turn number

void opponent();                                                    //randomly places Os

int main()
{
    
    int winX = 0, winO = 0, turn = 0, s = 0;
    bool play = true;
    char sPlayer, pAgain;

    std::cout << "single player (y/n): ";                               //select single player
    std::cin >> sPlayer;


    if (sPlayer == 'y' || sPlayer == 'Y')                          //single player game loop
    {
        board();                                                   //print the board
        while (play)
        {
            move('X');                                             //X moves

            turn++;

            winX = checkWin('X',turn);                             //did X win
            if (winX == 1)
            {
                std::cout << "Xs win" << std::endl << "play again? (y/n): ";          //play again?
                std::cin >> pAgain;
                
                if (pAgain == 'y' || pAgain == 'Y')             //reset to play again
                {
                    rBoard();                                   //rest board
                    board();                                    //reprint board
                    winX = false;                               //remove win flag
                    turn = 0;
                }
                else                                            //dont play again
                {
                    break;
                }

            }
            else if (winX == 2)                                 //game ends in draw
            {
                std::cout << "draw, no winner" << std::endl << "play again? (y/n): ";
                std::cin >> pAgain;

                if (pAgain == 'y' || pAgain == 'Y')             //play again
                {
                    rBoard();
                    board();
                    turn = 0;
                }
                else                                            //dont play again
                {
                    break;
                }
            }

            opponent();                                          //opponent moves

            board();

            turn++;

            board();                                            //print oponents move
            winO = checkWin('O',turn);                          //checks is opponent won
            if (winO == 1)
            {
                std::cout << "Os win" << std::endl << "play again? (y/n): ";
                std::cin >> pAgain;

                if (pAgain == 'y' || pAgain == 'Y')
                {
                    rBoard();                                  //restes to play again
                    board();
                    winO = false;                              //resets win flag
                    turn = 0;
                }
                else                                          //leave game
                {
                    break;
                }

            }
            else if (winO == 2)
            {
                std::cout << "draw, no winner" << std::endl << "play again? (y/n): ";
                std::cin >> pAgain;

                if (pAgain == 'y' || pAgain == 'Y')          //play again
                {
                    rBoard();
                    board();
                    turn = 0;
                }
                else                                        //dont play again
                {
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

            turn++;

            winX = checkWin('X',turn);                      //did X win

            if (winX == 1)
            {
                std::cout << "Xs win" << std::endl << "play again (y/n): ";
                std::cin >> pAgain;

                if (pAgain == 'Y' || pAgain == 'y')         //Play again ?
                {
                    rBoard();                               //reset game
                    board();
                    winX = false;
                    turn = 0;
                }
                else                                        //leave game
                {
                    break;
                }
            }
            else if (winX == 2)
            {
                std::cout << "draw, no winner" << std::endl << "play again? (y/n): ";
                std::cin >> pAgain;

                if (pAgain == 'y' || pAgain == 'Y')         //play again
                {
                    rBoard();
                    board();
                    turn = 0;
                }
                else                                        //dont play again
                {
                    break;
                }
            }

            move('O');                                      //O moves

            turn++;

            winO = checkWin('O',turn);                      //did O win

            if (winO == 1)
            {
                std::cout << "Os win" << std::endl << "play again (y/n): ";
                std::cin >> pAgain;

                if (pAgain == 'Y' || pAgain == 'y')         //play again?
                {
                    rBoard();                               //reset the game
                    board();
                    winO = false;
                    turn = 0;
                }
                else                                        //leave the game
                {
                    break;
                }
            }
            else if (winO == 2)
            {
                std::cout << "draw, no winner" << std::endl << "play again? (y/n): ";
                std::cin >> pAgain;

                if (pAgain == 'y' || pAgain == 'Y')         //play again
                {
                    rBoard();
                    board();
                    turn = 0;
                }
                else                                        //dont play again
                {
                    break;
                }
            }
        }
    }

    return 0;
}

void board()                                                        //display game board
{
    system("cls");                                                  //clear screen before showing updated board

    std::cout << "     |     |     " << std::endl                   //kind of looks like a tic tac toe board
        << "  " << x[0] << "  |  " << x[1] << "  |  " << x[2] << std::endl
        << "_____|_____|_____" << std::endl
        << "     |     |     " << std::endl
        << "  " << x[3] << "  |  " << x[4] << "  |  " << x[5] << std::endl
        << "_____|_____|_____" << std::endl
        << "     |     |     " << std::endl
        << "  " << x[6] << "  |  " << x[7] << "  |  " << x[8] << std::endl
        << "     |     |     " << std::endl;
}

void rBoard()                                                       //resets the board
{
    for (int i = 0; i < 9; i++)                                     //resets each square to initial condition
    {
        x[i] = '0' + i + 1;
    }
}

void move(char y)
{
    int square;                                             //selected square number
    bool empty = true;                                      //is space empty space

    do
    {
        std::cout << "select square: ";                          //pick square
        std::cin >> square;

        if (x[square - 1] != 'X' && x[square - 1] != 'O')               //check is square hasn't been taken
        {
            x[square - 1] = y;
            empty = true;
        }
        else
        {
            empty = false;
        }
    } while (!empty);                                       //loop as long as chosen square not available

    board();
}

int checkWin(char b, int turn)                                      //Accepts char 'X' or 'O' and turn number
{
    if (x[0] == b && x[1] == b && x[2] == b)                        //checks if char b has 3 in a row
    {
        return 1;
    }           
    else if (x[3] == b && x[4] == b && x[5] == b)
    {
        return 1;
    }
    else if (x[6] == b && x[7] == b && x[8] == b)
    {
        return 1;
    }
    else if (x[0] == b && x[4] == b && x[8] == b)
    {
        return 1;
    }
    else if (x[2] == b && x[4] == b && x[6] == b)
    {
        return 1;
    }
    else if (x[0] == b && x[3] == b && x[6] == b)
    {
        return 1;
    }
    else if (x[1] == b && x[4] == b && x[7] == b)
    {
        return 1;
    }
    else if (x[2] == b && x[5] == b && x[8] == b)
    {
        return 1;
    }
    else if (turn >= 9)                                      //9 moves without a winner, draw
    {
        return 2;
    }
    else                                                    //not yet a win or draw
    {
        return 0;
    }
}

void opponent()                                                 //randomly places Os
{
    bool i = true;
    while (i)                                                   //loops as long as it cant find an open square
    {
        int y = rand() % 9;                                     //pick random square between 1 and 9

        if (x[y] != 'X' && x[y] != 'O')                         //checks if space is open
        {
            x[y] = 'O';                                         //places O if space empty
            i = false;
        }
    }
}
