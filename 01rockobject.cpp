// *********************************************************
// Course: TCP1101 PROGRAMMING FUNDAMENTALS
// Year: Trimester 1, 2022/23 (T2215)
// Lab: T10L
// Names: MELVIN (CODER OF THIS TASK)| SUREN | ROHIT
// IDs: 1221303453| MEMBER_ID_2 | MEMBER_ID_3
// Emails: 1221303453@student.mmu.edu.my | MEMBER_EMAIL_2 | MEMBER_EMAIL_3
// Phones: 018-3702831 | MEMBER_PHONE_2 | MEMBER_PHONE_3
// *********************************************************
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main ()
{

    srand(time(NULL)); //randomly choose without having repeating senario
    const string object[4] = {" a health potion", " a pod"," nothing"," an arrow"};
    string x = object [rand()% 4]; //chOose 1 out of the 4 from the string

    cout << "Alien stumbles upon a rock." << endl;
    cout << "Alien discover" << x << " beneath the rock." << endl;
    cout << "Press any key to continue ... "<< endl;
    cin.ignore();//ignore any key inputs
    cout << "Alien's turns ends. The trail is reset. "<< endl; //r > object
    cout << "Press any key to continue ... "<< endl;
    cin.ignore();
    return(0);
}
