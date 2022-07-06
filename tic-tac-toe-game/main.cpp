#include <bits/stdc++.h>
#include <stdlib.h>
#include <windows.h>

using namespace std;

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

string board[3][3] = {{" "," "," "},{" "," "," "},{" "," "," "}};
int choice;
int row,column;
string turn = "X";
bool draw = false;

void display_board(){

    //Board Status after player turn

    SetConsoleTextAttribute(h, 15);

    int c = 0;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (board[i][j] == " ")
                c++;
        }
    }

    if (c == 9)
    {
        SetConsoleTextAttribute(h, 11);
        cout << "\n\t\t\t\t START !! \n\n\n";
    }
    else{
            SetConsoleTextAttribute(h, 13);
    cout<<"\n\n\t\t\t      |     |     \n";
    cout<<"\t\t\t   ";
    SetConsoleTextAttribute(h, 1);
    cout<<board[0][0];
    SetConsoleTextAttribute(h, 13);
    cout<<"  |  ";
    SetConsoleTextAttribute(h, 1);
    cout<<board[0][1];
    SetConsoleTextAttribute(h, 13);
    cout<<"  |  ";
    SetConsoleTextAttribute(h, 1);
    cout<<board[0][2]<<" \n";
    SetConsoleTextAttribute(h, 13);
    cout<<"\t\t\t _____|_____|_____\n";
    cout<<"\t\t\t      |     |     \n";
    cout<<"\t\t\t   ";
    SetConsoleTextAttribute(h, 1);
    cout<<board[1][0];
    SetConsoleTextAttribute(h, 13);
    cout<<"  |  ";
    SetConsoleTextAttribute(h, 1);
    cout<<board[1][1];
    SetConsoleTextAttribute(h, 13);
    cout<<"  |  ";
    SetConsoleTextAttribute(h, 1);
    cout<<board[1][2]<<" \n";
    SetConsoleTextAttribute(h, 13);
    cout<<"\t\t\t _____|_____|_____\n";
    cout<<"\t\t\t      |     |     \n";
    cout<<"\t\t\t   ";
    SetConsoleTextAttribute(h, 1);
    cout<<board[2][0];
    SetConsoleTextAttribute(h, 13);
    cout<<"  |  ";
    SetConsoleTextAttribute(h, 1);
    cout<<board[2][1];
    SetConsoleTextAttribute(h, 13);
    cout<<"  |  ";
    SetConsoleTextAttribute(h, 1);
    cout<<board[2][2]<<" \n";
    SetConsoleTextAttribute(h, 13);
    cout<<"\t\t\t      |     |     \n\n";
    }
}

//Function which asks the player for input and updates the board accordingly

void player_turn(){
    SetConsoleTextAttribute(h, 14);
    if(turn == "X"){
        cout << "\n\tPlayer - 1 turn :    ";
    }
    else if(turn == "O"){
        cout << "\n\tPlayer - 2 turn :    ";
    }
    //Taking input from user

    cin >> choice;

    bool flag = true;

    //switch case to get which row and column will be update

    switch(choice){
        case 1: row=0; column=0; break;
        case 2: row=0; column=1; break;
        case 3: row=0; column=2; break;
        case 4: row=1; column=0; break;
        case 5: row=1; column=1; break;
        case 6: row=1; column=2; break;
        case 7: row=2; column=0; break;
        case 8: row=2; column=1; break;
        case 9: row=2; column=2; break;
        default:
            SetConsoleTextAttribute(h, 4);

            flag = false;
    }
    //If player chooses a number which is not valid i.e; not between 1 and 9
    if (flag == false){
        cout<<"\n\n\t\t\tINVALID MOVE\n\n";
        player_turn();
    }
    else{
    if(turn == "X" && board[row][column] != "X" && board[row][column] != "O"){
        //Updating the board for player 1
        board[row][column] = "X";
        turn = "O";
    }else if(turn == "O" && board[row][column] != "X" && board[row][column] != "O"){
        //Updating the board for player 2
        board[row][column] = "O";
        turn = "X";
    }else {
        //If player chooses a box which is already filled
        SetConsoleTextAttribute(h, 4);
        cout<<"\n\t\t\tBox already filled!\n\t\t\tPlease choose another!!\n\n";
        player_turn();
    }
    }
}

//Function to check whether game is over or it has to continue

bool gameover(){
    //Checking if player has won by rows
    for(int i=0; i<3; i++)
    if(board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != " ")
    return false;

    //Checking if player has won by columns
    for(int i=0; i<3; i++)
    if(board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != " ")
    return false;

    //Checking if player has won by any of the two diagonals

    if(board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != " ")
    return false;

    if(board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] != " ")
    return false;

    //Checking if the game should continue or not
    for(int i=0; i<3; i++)
    for(int j=0; j<3; j++)
    if(board[i][j] != "X" && board[i][j] != "O")
    return true;

    //Checking if the game has ended in a draw
    draw = true;
    return false;
}

//Main Function
int main()
{
    SetConsoleTextAttribute(h, 10);
    cout << "\n\n\t\t\tT I C     T A C    T O E\t\t\t";
    cout << "\n\n\t\t\t   GAME FOR 2 PLAYERS\n\t\t\t";
    cout << "\n\n\t\t\t     PLAYER 1 : X";
    cout << "\n\n\t\t\t     PLAYER 2 : O\n\t\t\t";
    cout << "\n\n\t\t\t   BOARD  POSITIONS \n";

    //Displaying the valid positions on the board

    cout << "\n\t\t\t      |     |    ";
    cout << "\n\t\t\t   1  |  2  |  3 ";
    cout << "\n\t\t\t _____|_____|____";
    cout << "\n\t\t\t      |     |    ";
    cout << "\n\t\t\t   4  |  5  |  6 ";
    cout << "\n\t\t\t _____|_____|____";
    cout << "\n\t\t\t      |     |    ";
    cout << "\n\t\t\t   7  |  8  |  9 ";
    cout << "\n\t\t\t      |     |    \n\n";

    //Conducting the game between the two players
    while(gameover()){
        display_board();
        player_turn();
        gameover();
    }

    //Checking the result of the game
    if(turn == "O" && draw == false){
        display_board();
        SetConsoleTextAttribute(h, 6);
        cout<<"\n\n\t\t\tCongratulations!!\n\n\t\t\tPlayer 1 wins the game\n\n\n\n";
    }
    else if(turn == "X" && draw == false){
        display_board();
        SetConsoleTextAttribute(h, 6);
        cout<<"\n\n\t\t\tCongratulations!!\n\n\t\t\tPlayer 2 wins the game\n\n\n\n";
    }
    else{
        display_board();
        SetConsoleTextAttribute(h, 6);
        cout<<"\n\n\t\t\tGAME DRAW!!!\n\n";
    }
    SetConsoleTextAttribute(h, 15);
}
