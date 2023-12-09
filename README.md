# Chess Game
Welcome to my Chess Game project! This project is an implementation of a chess game using c++ and SFML for the visuals.

## Features
- Local Co-op: Play Chess against your friends and family
- Single Player: There are 4 different levels of chess bots to play against.
    - Level 1: This is the bot that plays chess using the strategy that we all started out with, moving the pieces randomly
    - Level 2: This bot has an actual strategy! It will rank moves based whether they checkmate you, check you, capture you, or do anything else
    - Level 3: This bot ranks moves based on how many moves you will have after it makes the move and chooses the one that gives you the least amount of moves
    - Level 4: This bot combines the previous two bots to form the hardest bot to beat!
- Bot fights: Watch two bots duke it out to see who is strongest!

## Usage
1. Clone the repository
    ```console
    git clone https://github.com/Party14534/chessGame.git
    ```

2. Navigate to the build folder
    ```console
    cd build
    ```

3. Run the project with the pre-compiled executables for windows and linux

## Arguments
- To play against bots, launch the game in the console with the level of bot after the application name
    ```console
    ./chess.exe <bot level>
    ```
- To watch two bots battle, launch the game in the console with two levels of bots after the application name
    ```console
    ./chess.exe <black bot level> <white bot level>
    ```

## Acknowledgements
- Thank you to Tom7 aka suckerpinch on youtube for inspiring me to make this game as well as the ideas for how each AI should work. Here is a link to his wonderful [video](https://youtu.be/DpXy041BIlA?si=14lR3zDQuJ_fEKbS)
