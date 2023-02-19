# Alien vs. Zombie

Thank you for playing our game!

Recently, we discovered a mobile game named Alien Path which currently available in Android and iOS. In that game, the player navigates an alien on a path to destroy robots. It combines several elements of role- playing game, puzzle, path-planning, and strategy to provide a unique gaming experience.

We intends to put our programming skills to the test by developing a simplified, text-based version of this game, with several modifications of our own. We name this modified game as Alien vs. Zombie, due to our peculiar soft spot for aliens and zombies.



Please provide the YouTube link to your [Video Demo](https://youtube.com).


## Compilation Instructions

Provide instructions on how to compile your program, especially when it is non-trivial.

1. Open the terminal. 

2. Make sure that the file has been download 

3. Make sure that the file is in the download.

4. Run the program

5. g++ C:\Users\User\Downloads\main.cpp

6. .\a

## User Manual

ATTRIBUTES
__________

Alien and Zombie are game characters. They share two common attributes: life and attack. A character is
defeated when its life becomes zero. The attack indicates the damage a characterinflicts on its opponent’s
life in one hit. Unlike Alien, Zombie has the range attribute, which defines how far Zombie’s attack can
reach.

Before the game begins, all attributes of Alien and Zombie are initialized with a random number. The only
exception is the Alien’s attack which always starts from ZERO (0) at each turn. This is because Alien’s attack
is accumulated by collecting the Arrow objects in the game board and is reset after each turn.

To make the game interesting, the random values assigned to all attributes must be within a sensible limit.
For example, attack should not be higher than life, and the Zombie’s range must not be larger than any
dimensions of the game board.

HOW TO PLAY?
____________

Both Alien and Zombie can move and attack, but their behaviours differ. Alien moves by continuously
thrusting in one of the FOUR (4) directions (i.e., up, down, left, or right). It is stopped by one of the
following events:
1. It hits the border of the game board (see Game Board).
2. It hits the Rock object (see Game Objects).
3. It hits and attacks Zombie, but Zombie survives the attack.

When Alien moves, it leaves trails on its path. At the end of Alien’s turn, the trails must be reset with
random non-trail game objects before the Zombie’s turn begins.

Alien attacks when it encounters Zombie on the move. If Zombie is defeated by the attack, Zombie will be
removed from the game board while Alien continues to move.

Unlike Alien, Zombie performs both move and attack successively at each turn. However, Zombie can only
move one step in a randomly selected direction (i.e., up, down, left, or right). Zombie can only move to a
location not occupied by Alien.

After a move, Zombie will attack Alien if Alien is with its attack range.

Both characters cannot move outside the board. When Alien hits a border of the board, it stops and its
turn ends. Zombie must also be programmed to avoid moving outside the board.

MULTIPLE ZOMBIES
________________
Each zombie is represented by a unique digit character in the game board starting from 1 to N, where N
is the number of zombies specified by you. The digit ZERO (0) is not used, hence the game can only
support a maximum of NINE (9) zombies.

Each zombie must have different values for its attributes (i.e., life, attack, and range) which are generated
randomly. You are free to decide the maximum and minimum limits of these attributes but ensure that
the limits are sensible.

Zombie cannot move to locations occupied by other zombies.

When Alien finds a pod, the attack must target only ONE (1) zombie closest to the pod. If there are two
or more zombies closest to the pod, any one of them will be choosed randomly.

For defeated zombies, the game should skip their turns, but their attributes must remain displayed
throughout the game.


GAME OBJECTS
____________
__________________________________________________________________________________________________________
| NAME      | Appearance    | Description                                                                |
__________________________________________________________________________________________________________
|Arrow      | ^ (up)        | - Changes Alien's direction of movement.                                   |
|           | v (down)      | - Add 20 attack to Alien.                                                  |
|           | < (left)      |                                                                            |
|           | > (down)      |                                                                            |
__________________________________________________________________________________________________________
|Health     | h             | - Add 20 life to Alien.                                                    |
__________________________________________________________________________________________________________
|Pod        | p             | - Changes Alien's direction of movement.                                   |
__________________________________________________________________________________________________________
|Rock       | r             | - Hides a game object (except Rock and Trail) beneath it.                  |
|           |               | - Reveals the hidden game object when hit by Alien.                        |
|           |               | - Stops the Alien from moving.                                             |
__________________________________________________________________________________________________________
|Empty      |Space          | - Just an empty space on the board.                                        |
__________________________________________________________________________________________________________
|Trail      |.              | - Left by Alien when it moves.                                             |
|           |               | - Reset to a random game object (except the Trail) after Alien’s turn ends.|
__________________________________________________________________________________________________________

GAME CONTROLS
_____________
__________________________________________________________________________________________________________
| COMMAND   | Description                                                                                |
__________________________________________________________________________________________________________
| UP        | Alien move upwards.                                                                        |
__________________________________________________________________________________________________________
| DOWN      | Alien move downwards.                                                                      |
__________________________________________________________________________________________________________
| LEFT      | Alien move to left.                                                                        |
__________________________________________________________________________________________________________
| RIGHT     | Alien move to right.                                                                       |
__________________________________________________________________________________________________________
| ARROW     | Switch the direction of an arrow object in the game board.                                 |
|           | (You will be asked to enter the row and column of the arrow object to switch,              |
|           | followed by the direction of the arrow object to switch to.)                               |
__________________________________________________________________________________________________________
| HELP      | List and describe the commands that you can use in the game.                               |
__________________________________________________________________________________________________________
| SAVE      | Save the current game to a file.(You will asked to enter the name of the file to save to). |
__________________________________________________________________________________________________________
| LOAD      | Load a saved game from a file.(You will asked to enter the name of the file to load from). |
__________________________________________________________________________________________________________
| QUIT      | Quit the game while still in play.(You will asked to confirm your decision)                |
__________________________________________________________________________________________________________


## Progress Log

- [Part 1](PART1.md)
- [Part 2](PART2.md)

## Contributors

Please replace the following with your group members' names. 

Please replace the following with your group members' names. 

- SUREN 
- ROHIT
- MELVIN


