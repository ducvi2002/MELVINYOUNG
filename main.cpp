// *********************************************************
// Course: TCP1101 PROGRAMMING FUNDAMENTALS
// Year: Trimester 1, 2022/23 (T2215)
// Lab: T10L
// Names: MELVIN | SURENTHIRAN | ROHIT
// IDs: 1221303453| 1211104053 | 1211103400
// Emails: 1221303453@student.mmu.edu.my | 1211104053@student.mmu.edu.my | 1211103400@student.mmu.edu.my
// Phones: 018-3702831 | 011-11940701 | 011-33791152
// *********************************************************
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <cstdlib> // for system()
#include <ctime>   // for time() in srand( time(NULL) );
#include <iomanip> // for setw()
using namespace std;

class Boards // mel
{
private:
    vector<vector<char>> board_; // convention to put trailing underscore
    int xaxis, yaxis;            // for private data
public:
    Boards(int x_axis, int y_axis)
    {
        init(x_axis, y_axis);
    }

    void init(int x_axis, int y_axis) // for game objects in the board
    {
        xaxis = x_axis;
        yaxis = y_axis;
        char objects[] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', 'r', 'p', 'h', '<', '>', '^', 'v'}; // empty spaces is to lower the chance of the objects be chosen
        int noOfObjects = 14;                                                                    // number of objects in the objects array => thus 7/14 => 50% of chances for a object to be chosen
        // create a 2D array using vector
        board_.resize(yaxis); // create empty rows
        for (int i = 0; i < yaxis; ++i)
        {
            board_[i].resize(xaxis); // resize each row
        }

        // put random characters/objects into the vector array
        for (int i = 0; i < yaxis; ++i)
        {
            for (int j = 0; j < xaxis; ++j)
            {
                int objNo = rand() % noOfObjects;
                board_[i][j] = objects[objNo];
            }
        }
    }

    void display() const //ref from lab11 
    {
        system("cls");//reload display
        cout << "  #################################" << endl;
        cout << "    ...::: Alien vs Zombie :::...  " << endl;
        cout << "  #################################" << endl;
        // for each row
        for (int i = 0; i < yaxis; ++i)
        {
            // display upper border of the row
            cout << "  ";
            for (int j = 0; j < xaxis; ++j)
            {
                cout << "+-";
            }
            cout << "+" << endl;
            // display row number
            cout << setw(2) << (yaxis - i);
            // display cell content & border of each col
            for (int j = 0; j < xaxis; ++j)
            {
                cout << "|" << board_[i][j];
            }
            cout << "|" << endl;
        }
        // display lower border of the last row
        cout << "  ";
        for (int j = 0; j < xaxis; ++j)
        {
            cout << "+-";
        }
        cout << "+" << endl;
        // display col no.
        cout << "  ";
        for (int j = 0; j < xaxis; ++j)
        {
            int digit = (j + 1) / 10;
            cout << " ";
            if (digit == 0)
                cout << " ";
            else
                cout << digit;
        }
        cout << endl;
        cout << "  ";
        for (int j = 0; j < xaxis; ++j)
        {
            cout << " " << (j + 1) % 10;
        }
        cout << endl
             << endl;
    }

    int getxaxis() const // to get the position of xaxis
    {
        return xaxis; // get it from xaxis
    }

    int getyaxis() const // constant the data
    {
        return yaxis;
    }

    char getObject(int col, int row) const // get position of the object, ref from lab11
    {
        return board_[yaxis - row][col - 1];
    }

    void setObject(int &col, int &row, char &ch) // set the position of the object, ref from lab11
    {
        board_[yaxis - row][col - 1] = ch;
    }

    bool isEmpty(int col, int row) // for boxes that empty, fer from lab11
    {
        return getObject(col, row) == ' ';
    }

    bool isInsideMap(int col, int row) // ref from lab11, act as a border, ref from lab11
    {
        return (1 <= col && col <= xaxis && 1 <= row && row <= yaxis);
    }
};

void displayMainMenu(int x_axis, int y_axis, int zombie)
{
    cout << " _________________________________________" << endl;
    cout << "|           Game Settings                 |" << endl;
    cout << "|_________________________________________|" << endl;
    cout << "|                                         |" << endl;
    cout << "|   Number of Board Rows        =>  " << x_axis << "    |" << endl;  // default setting from our command
    cout << "|   Number of Board Columns     =>  " << y_axis << "     |" << endl; // default setting from our command
    cout << "|   Number of Zombies           =>  " << zombie << "     |" << endl; // default setting from our command
    cout << "|_________________________________________|" << endl;
    cout << endl;
    cout << " Do you want to change the settings? (y/n) => ";
}

void changeSettings(int &x_axis, int &y_axis, int &zombie) // &x_axis reference from x_axis for parameter passing
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
    while (zombie > 4) // minimise the zombie command to only less than 4 zombies for better gameplay quality
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

class Alien // mel
{
private:
    char headingA{'A'}, headingtrail{'.'}; //A for Alien and . for trail
    int x_;int y_;
    int health {500}; int attack {0};

public:
    Alien()
    {
    }

    int getX() const
    {
        return x_;
    }

    int getY() const
    {
        return y_;
    }

    void AlienStat() //Alien Stat
    {
        cout << "Alien Health: " << health << " Alien Attack: " << attack << endl;
    }

    void AlienPosition(Boards &Boardcreated) // mel => to ensure Alien in the middle of the board
    {
        x_ = (Boardcreated.getxaxis() / 2) + 1; //(23/2)+1=12.5=13
        y_ = (Boardcreated.getyaxis() / 2) + 1;
        Boardcreated.setObject(x_, y_, headingA); //set the object!
    }

    void commandcenter(const string &command_, Boards &Boardcreated) //mel => receive movement command and separate the task at here
    {
        if (command_ == "left")
        {
            cout << "Alien => Life: " << health << " Attack: " << attack << endl;
            moveLeft(Boardcreated);
        }
        else if (command_ == "right")
        {
            cout << "Alien => Life: " << health << " Attack: " << attack << endl;
            moveRight(Boardcreated);
            
        }
        else if (command_ == "up")
        {
            cout << "Alien => Life: " << health << " Attack: " << attack << endl;
            moveUp(Boardcreated);
        }
        else if (command_ == "down")
        {
            cout << "Alien => Life: " << health << " Attack: " << attack << endl;
            moveDown(Boardcreated);
        }
    }

    void moveLeft(Boards &Boardcreated) // receive command as "left"
    {
        int xsteps = {x_ - 1}; // go to left 1 box
        int ysteps = {y_};     // at the same y axis
        int trailx = {x_};     // old position
        int traily = {y_};     // old position
        if (!Boardcreated.isInsideMap(xsteps, ysteps)) //to ensure alien not exceding after the border 
        {
            cout << "Alien hits a border" << endl;
            cout << "Seriously?!Press other key lah..." << endl;
            return;
        }
        bumped(xsteps, ysteps, Boardcreated); //when Alien bumped into something
        x_--; // keep on -1 for every loop 13-1 =12 ....12-1=11
        moveA(xsteps, ysteps, trailx, traily, Boardcreated); // the Alien moves with new step and trail created
    }

    void moveRight(Boards &Boardcreated) // receive command as "right"
    {

        int xsteps = {x_ + 1}; // go to right 1 box
        int ysteps = {y_};     // at the same y axis
        int trailx = {x_};     // old position
        int traily = {y_};     // old position
        if (!Boardcreated.isInsideMap(xsteps, ysteps))
        {
            cout << "Alien hits a border" << endl;
            cout << "Seriously?!Press other key lah..." << endl;
            return;
        }
        bumped(xsteps, ysteps, Boardcreated);
        x_++; // keep on -1 for every loop
        moveA(xsteps, ysteps, trailx, traily, Boardcreated);
    }

    void moveUp(Boards &Boardcreated) //receive command as "up"
    {

        int xsteps = {x_};
        int ysteps = {y_ + 1};
        int trailx = {x_};
        int traily = {y_};
        if (!Boardcreated.isInsideMap(xsteps, ysteps))
        {
            cout << "Alien hits a border" << endl;
            cout << "Seriously?!Press other key lah..." << endl;
            return;
        }
        bumped(xsteps, ysteps, Boardcreated);
        y_++;
        moveA(xsteps, ysteps, trailx, traily, Boardcreated);
    }

    void moveDown(Boards &Boardcreated) //receive command as "down"
    {

        int xsteps = {x_};
        int ysteps = {y_ - 1};
        int trailx = {x_};
        int traily = {y_};
        if (!Boardcreated.isInsideMap(xsteps, ysteps))
        {
            cout << "Alien hits a border" << endl;
            cout << "Seriously?!Press other key lah..." << endl;
            return;
        }
        bumped(xsteps, ysteps, Boardcreated);
        y_--;
        moveA(xsteps, ysteps, trailx, traily, Boardcreated);
    }

    void moveA(int &xsteps, int &ysteps, int &trailx, int &traily, Boards &Boardcreated) // mel => when the Alien moves
    {
        char obj = Boardcreated.getObject(xsteps, ysteps); //position of the object to be replaced with 'A'
        Boardcreated.setObject(x_, y_, headingA); //set the new box as 'A'
        Boardcreated.setObject(trailx, traily, headingtrail); //set the old box as trail '.'
    }

    void bumped(int &xsteps, int &ysteps, Boards &Boardcreated) // mel => when Alien bumped to an object
    {
        if (Boardcreated.getObject(xsteps, ysteps) == 'r')
        {
            bumpedrock(xsteps, ysteps, Boardcreated);
        }

        else if (Boardcreated.getObject(xsteps, ysteps) == 'p')
        {
            bumpedpod();
        }

        else if (Boardcreated.getObject(xsteps, ysteps) == 'h')
        {
            bumpedhealth();
        }

        else if (Boardcreated.getObject(xsteps, ysteps) == '<')
        {
            bumpedarrow();
        }

        else if (Boardcreated.getObject(xsteps, ysteps) == '>')
        {
            bumpedarrow();
        }

        else if (Boardcreated.getObject(xsteps, ysteps) == '^')
        {
            bumpedarrow();
        }

        else if (Boardcreated.getObject(xsteps, ysteps) == 'v')
        {
            bumpedarrow();
        }

        else if (Boardcreated.getObject(xsteps, ysteps) == ' ')
        {
            system("pause");
        }

        else if (!Boardcreated.isInsideMap(xsteps, ysteps))
        {
            cout << "Alien hits a border" << endl;
            cout << "Seriously?!Press other key lah..." << endl;
            system("pause");
        }
    }

    void bumpedrock(int &x, int &y, Boards Boardcreated) //mel => rock 
    {
        cout << "Alien stumbles upon a rock." << endl;
        char newobject = rand() % 4 + 1; //the object obtained expresssed into number 1 = pod ,2 = health ,3 = arrow ,4 = nothing

        switch (newobject)
        {
        case 1:
            cout << "Alien discovers a pod beneath the rock." << endl;
            break;
        case 2:
            cout << "Alien discovers a health pack beneath the rock." << endl;
            cout << "Alien's life is increased by 20." << endl;
            health += 20;
            break;

        case 3:
            cout << "Alien discovers an arrow beneath the rock." << endl;
            cout << "Alien's attack is increased by 20." << endl;
            attack += 20;
            break;

        case 4:
            cout << "Alien discovers nothing beneath the rock." << endl;
            break;
        }

        cout << "Alien's turns ends. " << endl; // r > object
        cout << "Alien => Life: " << health << " Attack: " << attack << endl;
        system("pause");
    }

    void bumpedpod() //mel => unfinish
    {
        cout << "Alien finds a pod." << endl;
        cout << "It cincai hit a zombie" << endl;
        cout << "Zombie 1 get a damage of 10" << endl;
        system("pause");
    }

    void bumpedhealth() //mel = > health
    {
        cout << "Alien finds a health pack." << endl;
        cout << "Alien's life is increased by 20." << endl;
        health  += 20; //500+20= 520, 2nd encounter will be 520+20=540
        cout << "Alien => Life: " << health << " Attack: " << attack << endl;
        cout << "" << endl;
        system("pause");
    }

    void bumpedarrow() //mel => unfinish
    {
        cout << "Enter row, column and direction:" << endl;
        system("pause");
    }
};

/*/class Zombies => done by SUREN for zombie class and attributes but failed to run due to error
{
private:


public:
    string identifier;
    int life;
    int attack;
    int range;
    int xcor;
    int ycor;

void spawnZombie(vector<vector<string>> &boardgame)
{
    int row, column, amount;
    row = boardgame.size();
    column = boardgame[0].size();

    vector<vector<string>> nocoordinates(row, vector<string>(column));

    cout << "How many zombies do you want?";
    cin >> amount;

    vector<Zombies> zombie;
    zombie.resize(amount);

    srand(time(NULL));  // seed the random number generator

    for (int i = 0; i < zombie.size(); i++)
    {
        zombie[i].identifier = to_string(i);
        zombie[i].life = rand() % 100 + 50;
        zombie[i].attack = rand() % 30 + 10;
        zombie[i].range = rand() % 3 + 1;

        // display the randomly generated variables
        cout << "Zombie " << i << ": life=" << zombie[i].life << ", attack=" << zombie[i].attack << ", range=" << zombie[i].range << endl;
    }

    for (int i = 0; i < zombie.size(); i++)
    {
        int xaxis = rand() % row;
        int yaxis = rand() % column;

        if (!(nocoordinates[xaxis][yaxis] == "no"))
        {
            zombie[i].xcor = xaxis;
            zombie[i].ycor = yaxis;
            boardgame[xaxis][yaxis] = zombie[i].identifier;
        }
        else
        {
            i--;
        }
        nocoordinates[xaxis][yaxis] = "no";
    }
}

void createBoardFromSetting(int x, int y, int z) {
    // initialize boardgame vector
    vector<vector<string>> boardgame(x, vector<string>(y));

    // call spawnZombie function and get the vector of zombies
    vector<Zombies> zombies = spawnZombie(boardgame, z);

    // print out the zombie range, attack, and life
    for (int i = 0; i < zombies.size(); i++)
    {
        cout << "Zombie " << i << ": life=" << zombies[i].life << ", attack=" << zombies[i].attack << ", range=" << zombies[i].range << endl;
    }
}

}; /*/

/*/V done by ROHIT for load/save game but failed to run due to error
void savegame(const Aliens *ali, const Zombies *braineaters, int score, int life, const std::string &filename)
{
    std::ofstream out(filename, std::ios::binary);
    out.write((char *)&score, sizeof(int));
    for (int i = 0; i < score; i++)
    {
        out.write(ali[i].name.c_str(), ali[i].name.size());
        out.write("\0", 1);
        out.write((char *)&ali[i].score, sizeof(int));
    }
    out.close();
}

Aliens *loadgame(int &size, const std::string &filename)
{
    std::ifstream in(filename, std::ios::binary);
    in.read((char *)&size, sizeof(int));
    Aliens *ali = new Aliens[size];
    char buffer[100];
    for (int i = 0; i < size; i++)
    {
        in.getline(buffer, 100, '\0');
        ali[i].name = buffer;
        in.read((char *)&ali[i].score, sizeof(int));
    }
    in.close();
    return ali;
}

int main()
{
    Aliens ali[] = {{"Zombie 1", 30}, {"Zombie 2", 40}, {"Zombie 3", 25}};
    int score = sizeof(Aliens) / sizeof(score);

    savegame(ali, score, "ali.bin");
    Aliens *loadali = loadgame(score, "people.bin");

    for (int i = 0; i < score; i++)
    {
        std::cout << loadali[i].name << " " << loadali[i].score << std::endl;
    }

    delete[] loadali;
    return 0;
} /*/

void help() // mel  => receive command as "help"
{
    cout << "Commands" << endl;
    cout << "1. up    - Move up" << endl;
    cout << "2. down  - Move down" << endl;
    cout << "3. left  - Move left" << endl;
    cout << "4. arrow - Change the direction of an arrow" << endl;
    cout << "5. help  - Display these user commands" << endl;
    cout << "6. save  - Save the game" << endl;
    cout << "7. load  - Load a game" << endl;
    cout << "8. quit  - Quit a game" << endl;
    system("pause");
}

void commands(Alien &playing, Boards &Boardcreated) // mel => command by the Alien
{
    string command;
    cout << "Command: ";
    cin >> command;
    if (command == "left")
    {
        playing.commandcenter(command, Boardcreated);
    }

    else if (command == "right")
    {
        playing.commandcenter(command, Boardcreated);
    }

    else if (command == "up")
    {
        playing.commandcenter(command, Boardcreated);
    }

    else if (command == "down")
    {
        playing.commandcenter(command, Boardcreated);
    }


    else if (command == "help")
    {
        help();
    }
    else if (command == "quit")
    {
        exit(0);
    }
}

void createBoard(const int &x_axis, const int &y_axis, const int &zombie) //mel => game board
{
    Boards Boardcreated = Boards(x_axis, y_axis); //using the x & y either given by us or Alien
    Alien playing;
    playing.AlienPosition(Boardcreated); //Alien position at center
    while (true)
    {
        Boardcreated.display(); //display game board
        commands(playing, Boardcreated); //ask for command
    }
}

int main() // mel => the main function
{
    int x_axis = 23, y_axis = 3, zombie = 1; // default setting given by us
    char answer; //we use switch loop here
    Alien playing;
    bool done = false;
    do
    {
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
            cout << "command Error!" << endl;
            cout << "Look, I'm gonna make this simple again for you..." << endl; // part of TWICE - yes or yes lyrics
            cout << "You got two choices..." << endl;
            cout << "type y or n!" << endl;
            cout << endl;
            break;
        }
    } while (!done);
    cout << endl;
}
