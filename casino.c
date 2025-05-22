#include "casino.h"

// Bubble sort za igraèe
void sortPlayers() {
    int choice;
    printf("\nSortiranje igraèa:\n1. Po imenu\n2. Po prezimenu\n3. Po saldu\nOdabir: ");
    scanf("%d", &choice);

    for (int i = 0; i < playerCount - 1; i++) {
        for (int j = 0; j < playerCount - i - 1; j++) {
            int swap = 0;
            if ((choice == 1 && strcmp(players[j].firstName, players[j + 1].firstName) > 0) ||
                (choice == 2 && strcmp(players[j].lastName, players[j + 1].lastName) > 0) ||
                (choice == 3 && players[j].balance > players[j + 1].balance)) {
                swap = 1;
            }

            if (swap) {
                Player temp = players[j];
                players[j] = players[j + 1];
                players[j + 1] = temp;
            }
        }
    }

    printf("Igraèi su sortirani.\n");
    listPlayers();
}

// Bubble sort za igre
void sortGames() {
    int choice;
    printf("\nSortiranje igara:\n1. Po imenu igre\n2. Po minimalnoj okladi\n3. Po maksimalnoj okladi\nOdabir: ");
    scanf("%d", &choice);

    for (int i = 0; i < gameCount - 1; i++) {
        for (int j = 0; j < gameCount - i - 1; j++) {
            int swap = 0;
            if ((choice == 1 && strcmp(games[j].gameName, games[j + 1].gameName) > 0) ||
                (choice == 2 && games[j].minBet > games[j + 1].minBet) ||
                (choice == 3 && games[j].maxBet > games[j + 1].maxBet)) {
                swap = 1;
            }

            if (swap) {
                Game temp = games[j];
                games[j] = games[j + 1];
                games[j + 1] = temp;
            }
        }
    }

    printf("Igre su sortirane.\n");
    listGames();
}
