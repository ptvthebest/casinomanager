#ifndef CASINO_H
#define CASINO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int playerID;
    char firstName[50];
    char lastName[50];
    double balance;
} Player;

typedef struct {
    int gameID;
    char gameName[50];
    double minBet;
    double maxBet;
} Game;

 Player players[100];
 Game games[100];
 int playerCount;
 int gameCount;
 int nextPlayerID;
 int nextGameID;

void addPlayer();
void listPlayers();
void updatePlayer();
void deletePlayer();
void savePlayers();
void loadPlayers();
void sortPlayers();

void addGame();
void listGames();
void updateGame();
void deleteGame();
void saveGames();
void loadGames();
void sortGames();

#endif
