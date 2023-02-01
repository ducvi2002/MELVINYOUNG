// *********************************************************
// Course: TCP1101 PROGRAMMING FUNDAMENTALS
// Year: Trimester 1, 2022/23 (T2215)
// Lab: T10L
// Names: MELVIN (CODER OF VOID CREATEBOARD & int main)| SUREN | ROHIT
// IDs: 1221303453| MEMBER_ID_2 | MEMBER_ID_3
// Emails: 1221303453@student.mmu.edu.my | MEMBER_EMAIL_2 | MEMBER_EMAIL_3
// Phones: 018-3702831 | MEMBER_PHONE_2 | MEMBER_PHONE_3
// *********************************************************
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <cstdlib> // for system()
#include <ctime>   // for time() in srand( time(NULL) );
#include <iomanip> // for setw()
using namespace std;

// CHANGE SETTINGS
void changeSettings(int &x_axis, int &y_axis, int &zombie)
{
    cout << " _________________________________________ " << endl;
    cout << "|              Board Settings             |" << endl;
    cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl;
    cout << endl;
    cout << " Please enter odd numbers only. " << endl;
    cout << " Enter number of board rows     =>  ";
    cin >> x_axis;

    // Check if the x-axis dimension is an odd number
    while (x_axis % 2 == 0)
    {
        cout << "Please enter odd numbers only." << endl;
        cout << "Enter number of rows: ";
        cin >> x_axis;
    }

    cout << " Enter number of board columns  =>  ";
    cin >> y_axis;

    // Check if the y-axis dimension is an odd number
    while (y_axis % 2 == 0)
    {
        cout << "Please enter odd numbers only." << endl;
        cout << "Enter number of columns: ";
        cin >> y_axis;
    }

    cout << " _________________________________________ " << endl;
    cout << "|             Zombies Settings            |" << endl;
    cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl;
    cout << " Enter number of zombies        =>  ";
    cin >> zombie;
    while (zombie > 4) //m
    {
        cout << "You think your Alien is Ip Man meh?!" << endl;
        cout << "Even Ip Man only can max fight 10 Japs at one time" << endl;
        cout << "Type less than 4 zombies only!" << endl;
        cout << "Enter number of zombies        =>  ";
        cin >> zombie;
    }
    cout << endl;
    cout << " Settings Updated." << endl;
    cout << endl;
}

void createBoard(int x_axis, int y_axis, int zombie)
{
    // Initialize the game board with empty spaces
    cout << "  #################################" << endl;
    cout << "    ...::: Alien vs Zombie :::... " << endl;
    cout << "  #################################" << endl;
    char board[x_axis][y_axis];

    char objects[] = {' ', ' ', ' ',' ', ' ', ' ',' ', 'r', 'p', 'h', '<', '>', '^', 'v'}; //m
    int noOfObjects = 14; // number of objects in the objects array //m

    for (int i = 0; i < x_axis; ++i)
    {
        for (int j = 0; j < y_axis; ++j)
        {
            int objNo = rand() % noOfObjects; //m
            board[i][j] = objects[objNo]; //m
        }
    }

    //char alien = 'A'

    int centerRow = x_axis / 2;
    int centerCol = y_axis / 2;
    board[centerRow][centerCol] = 'A';

    //create zombie randomly -> Mel

    if (zombie == 1) //m
    {
        int randx1 = rand()% x_axis;
        int randy1 = rand()% y_axis;
        randx1 != centerRow;
        randy1 != centerCol;
        board[randx1][randy1] = '1';
    }
    if (zombie == 2) //m
    {
        int randx1 = rand()% x_axis;
        int randy1 = rand()% y_axis;
        board[randx1][randy1] = '1';
        int randx2 = rand()% x_axis;
        int randy2 = rand()% y_axis;
        randx1 != randx2;
        randy1 != randy2;
        randx2 != centerRow;
        randy2 != centerCol;
        board[randx2][randy2] = '2';
    }

    if (zombie == 3) //m
    {
        int randx1 = rand()% x_axis;
        int randy1 = rand()% y_axis;
        randx1 != centerRow;
        randy1 != centerCol;
        board[randx1][randy1] = '1';
        int randx2 = rand()% x_axis;
        int randy2 = rand()% y_axis;
        randx1 != randx2;
        randy1 != randy2;
        randx2 != centerRow;
        randy2 != centerCol;
        board[randx2][randy2] = '2';
        int randx3 = rand()% x_axis;
        int randy3 = rand()% y_axis;
        randx3 != randx2;
        randy3 != randy2;
        randx3 != randx1;
        randy3 != randy1;
        randx3 != centerRow;
        randy3 != centerCol;
        board[randx3][randy3] = '3';
    }

    if (zombie == 4) //m
    {
        int randx1 = rand()% x_axis;
        int randy1 = rand()% y_axis;
        randx1 != centerRow;
        randy1 != centerCol;
        board[randx1][randy1] = '1';
        int randx2 = rand()% x_axis;
        int randy2 = rand()% y_axis;
        randx1 != randx2;
        randy1 != randy2;
        randx2 != centerRow;
        randy2 != centerCol;
        board[randx2][randy2] = '2';
        int randx3 = rand()% x_axis;
        int randy3 = rand()% y_axis;
        randx3 != randx2;
        randy3 != randy2;
        randx3 != randx1;
        randy3 != randy1;
        randx3 != centerRow;
        randy3 != centerCol;
        board[randx3][randy3] = '3';
        int randx4 = rand()% x_axis;
        int randy4 = rand()% y_axis;
        randx4 != randx3;
        randy4 != randy3;
        randx4 != randx2;
        randy4 != randy2;
        randx4 != randx1;
        randy4 != randy1;
        randx4 != centerRow;
        randy4 != centerCol;
        board[randx4][randy4] = '4';
    }

// Display the board
    if (x_axis >= 50 || y_axis >= 50)
    {
        cout << " ";
        for (int i = 1; i <= x_axis; i++)
        {
            cout << i % 10 << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < x_axis; i++)
    {
        cout << "  ";
        for (int j = 0; j < y_axis; ++j)
        {
            cout << "+-";
        }
        cout << "+" << endl;


        // display row number
        cout << setw(2) << (x_axis - i);
        // display the border
        for (int j = 0; j < y_axis; ++j)
        {
            cout << "|" << board[i][j];
        }
        cout << "|" << endl;
    }
    cout << "  ";
    for (int j = 0; j < y_axis; ++j)
    {
        cout << "+-";
    }
    cout << "+" << endl;


    // display column number
    cout << "  "; //m
    for (int j = 0; j < y_axis; ++j) //m
    {
        int digit = (j + 1) / 10;
        cout << " "; //m
        if (digit == 0)
            cout << " ";
        else
            cout << digit; //m
    }
    cout << endl;
    cout << "  ";
    for (int j = 0; j < y_axis; ++j) //m
    {
        cout << " " << (j + 1) % 10;
    }
    cout << endl << endl;

    //Attributes
    cout << "--> Alien    : Life 100, Attack 0" << endl;
    cout << "--> Zombie 1 : Life 100, Attack 0" << endl;
}

    // DEFAULT SETTINGS
    void displayMainMenu(int x_axis, int y_axis, int zombie)
    {
        cout << " _________________________________________" << endl;
        cout << "|          Default Game Settings          |" << endl;
        cout << "|_________________________________________|" << endl;
        cout << "|                                         |" << endl;
        cout << "|   Number of Board Columns  =>  " << x_axis << "        |" << endl; //c
        cout << "|   Number of Board Rows     =>  " << y_axis << "        |" << endl; //c
        cout << "|   Number of Zombies        =>  " << zombie << "        |" << endl;
        cout << "|_________________________________________|" << endl;
        cout << endl;
        cout << " Do you want to change the settings? (y/n) => ";
    
}

int main()
{
    int x_axis = 5; int y_axis = 9; int zombie = 1; //c
    char answer;
    bool done = false;
    do{
        displayMainMenu(x_axis, y_axis, zombie);
        cin >> answer;
        switch (answer)
        {
            case 'y':
                cout << "Wah, you pattern more than badminton, I like it!" << endl;
                changeSettings(x_axis, y_axis, zombie);
                break;
            case 'n':
                done = true;
                cout << "Wise choice, let's play" << endl;
                createBoard(x_axis, y_axis, zombie);
                break;
            default:
                cout << "Input Error!" << endl;
                cout << "Look, I'm gonna make this simple again for you..." << endl; //part of TWICE - yes or yes lyrics
                cout << "You got two choices..." << endl;
                cout << "type y or n!" << endl;
                cout << endl;
                break;

        }
    
    }while (!done);

    cout << endl;
}