//
//  main.c
//  2 Player Math Game
//
//  Created by Josh Endter on 6/9/15.
//  Copyright (c) 2015 Josh Endter. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>
#import <stdlib.h>

// setup structs
typedef struct {
    char name[255];
    int lives;
    int score;
    int gamesWon;
} Player;

Player player1;
Player player2;
int playersTurn;
bool playingGame;

void setupNewGame();
void endGame();
bool askQuestion(int playerNumber);

int main(int argc, const char * argv[]) {
    // ask for player 1's name and player 2's name
    
    printf("Player 1's name? ");
    fgets(player1.name, 255, stdin);
    
    printf("Player 2's name? ");
    fgets(player2.name, 255, stdin);
    
    // initialize player 1 and player 2's lives (use function "setupNewGame")
    setupNewGame();
    
    
    
    // start game loop
    
    while (playingGame == true) {
        
        //askQuestion(playersTurn);
        
        if(askQuestion(playersTurn)) {
            // Question was answered correctly
            if (playersTurn == 1) {
                player1.score++;
            } else if (playersTurn == 2) {
                player2.score++;
            }
            printf("Right! \n");
        } else {
            // Question was answered incorrectly
            printf("Nope! \n");
            
            // Remove a life
            if (playersTurn == 1) {
                player1.lives--;
                printf("Player 1 Lives = %d \n", player1.lives);
            } else if (playersTurn == 2) {
                player2.lives--;
                printf("Player 2 Lives = %d \n", player2.lives);
            }
            
            printf("Player 1 Score = %d \nPlayer 2 Score = %d \n", player1.score, player2.score);
        }
        
        if (playersTurn == 1) {
            playersTurn++;
        } else {
            playersTurn = 1;
        }
        
        if (player1.lives == 0 || player2.lives == 0) {
            endGame();
        }
        
    }
    
    return 0;
}

void setupNewGame() {
    player1.score = 0;
    player2.score = 0;
    player1.lives = 3;
    player2.lives = 3;
    playersTurn = 1;
    playingGame = true;
}

void endGame() {
    playingGame = false;
    
    if (player1.score > player2.score) {
        player1.gamesWon++;
    } else if (player2.score > player1.score) {
        player2.gamesWon++;
    } else {
        player1.gamesWon++;
        player2.gamesWon++;
    }
    
    
    bool askForNewGame = true;
    while (askForNewGame) {
        printf("Would you like to play again (y/n)? ");
        char buffer[20];
        scanf("%s", buffer);
        if (buffer[0] == 'y') {
            askForNewGame = false;
            setupNewGame();
        } else if (buffer[0] == 'n') {
            askForNewGame = false;
            printf("Bye! \n");
        } else {
            printf("\n");
        }
    }
    
    
}

bool askQuestion(int playerNumber) {
    int number1 = arc4random_uniform(20)+1;
    int number2 = arc4random_uniform(20)+1;
    int answer;
    
    
    int mathType = arc4random_uniform(3);
    
    printf("Player %d: What does %d ", playerNumber, number1);
    if (mathType == 0) {
        printf("plus");
        answer = number1 + number2;
    } else if (mathType == 1) {
        printf("minus");
        answer = number1 - number2;
    } else if (mathType == 2) {
        printf("multiplied by");
        answer = number1 * number2;
    } else if (mathType == 3) {
        printf("divided by");
        answer = number1 / number2;
    }
    printf(" %d equal? ", number2);
    
    char buffer[20];
    scanf("%s", buffer);
    int userAnswer = atoi(buffer);
    
    if (userAnswer == answer) {
        return true;
    } else {
        return false;
    }
    
    return false;
}


