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

using namespace std;

class Alien {
    int life;
    int attack;

public:
    Alien() {
        life = rand() % 20 + 20; // Random value between 20 and 40
        attack = 0;
    }
};

class Zombie {
    int life;
    int attack;
    int range;

public:
    Zombie() {
        life = rand() % 20 + 20; // Random value between 20 and 40
        attack = rand() % 10 + 5; // Random value between 5 and 15
        range = rand() % 3 + 1; // Random value between 1 and 3
    }
};

int main () //MEL
{
cout << "Alien finds a health pack."<< endl;
cout << "Alien's life is increased by 20."<< endl;
cout << "" << endl;
cout << "Press any key to continue ... "<< endl;
cin.ignore();
return(0);
}