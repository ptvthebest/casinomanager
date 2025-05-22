#define _CRT_SECURE_NO_WARNINGS
#include "casino.h"

Player players[100];
Game games[100];
int playerCount = 0;
int gameCount = 0;
int nextPlayerID = 1;
int nextGameID = 1;


void addPlayer() {
    if (playerCount >= 100) {
        printf("Maksimalan broj igraca dosegnut.\n");
        return;
    }

    Player p;
    p.playerID = nextPlayerID++;
    printf("Unesite ime: ");
    scanf("%49s", p.firstName);
    printf("Unesite prezime: ");
    scanf("%49s", p.lastName);
    printf("Unesite saldo: ");
    scanf("%lf", &p.balance);

    players[playerCount++] = p;
    savePlayers();
    printf("Igrac dodan.\n");
}

void listPlayers() {
    printf("\n--- Lista Igraca ---\n");
    for (int i = 0; i < playerCount; i++) {
        printf("%d. %s %s - Saldo: %.2lf\n",
            players[i].playerID,
            players[i].firstName,
            players[i].lastName,
            players[i].balance);
    }
}

void updatePlayer() {
    int id;
    printf("Unesite ID igraca za azuriranje: ");
    scanf("%d", &id);

    for (int i = 0; i < playerCount; i++) {
        if (players[i].playerID == id) {
            printf("Unesite novo saldo: ");
            scanf("%lf", &players[i].balance);
            savePlayers();
            printf("Saldo azurirano.\n");
            return;
        }
    }
    printf("Igrac nije pronaden.\n");
}

void deletePlayer() {
    int id;
    printf("Unesite ID igraca za brisanje: ");
    scanf("%d", &id);

    for (int i = 0; i < playerCount; i++) {
        if (players[i].playerID == id) {
            for (int j = i; j < playerCount - 1; j++) {
                players[j] = players[j + 1];
            }
            playerCount--;
            savePlayers();
            printf("Igrac obrisan.\n");
            return;
        }
    }
    printf("Igrac nije pronaden.\n");
}

void savePlayers() {
    FILE* f = fopen("players.dat", "wb");
    if (!f) return;
    fwrite(&playerCount, sizeof(int), 1, f);
    fwrite(players, sizeof(Player), playerCount, f);
    fclose(f);
}

void loadPlayers() {
    FILE* f = fopen("players.dat", "rb");
    if (!f) return;
    fread(&playerCount, sizeof(int), 1, f);
    fread(players, sizeof(Player), playerCount, f);
    nextPlayerID = playerCount > 0 ? players[playerCount - 1].playerID + 1 : 1;
    fclose(f);
}

void sortPlayers() {
    int choice;
    printf("Sortirati po:\n1. Ime\n2. Prezime\n3. Saldo\nOdabir: ");
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

    printf("Sortirano.\n");
    listPlayers();
}


void addGame() {
    if (gameCount >= 100) {
        printf("Maksimalan broj igara dosegnut.\n");
        return;
    }

    Game g;
    g.gameID = nextGameID++;
    printf("Unesite ime igre: ");
    scanf("%49s", g.gameName);
    printf("Unesite minimalnu okladu: ");
    scanf("%lf", &g.minBet);
    printf("Unesite maksimalnu okladu: ");
    scanf("%lf", &g.maxBet);

    games[gameCount++] = g;
    saveGames();
    printf("Igra dodana.\n");
}

void listGames() {
    printf("\n--- Lista Igara ---\n");
    for (int i = 0; i < gameCount; i++) {
        printf("%d. %s - Min: %.2lf, Max: %.2lf\n",
            games[i].gameID,
            games[i].gameName,
            games[i].minBet,
            games[i].maxBet);
    }
}

void saveGames() {
    FILE* f = fopen("games.dat", "wb");
    if (!f) return;
    fwrite(&gameCount, sizeof(int), 1, f);
    fwrite(games, sizeof(Game), gameCount, f);
    fclose(f);
}


void loadGames() {
    FILE* f = fopen("games.dat", "rb");
    if (!f) return;
    fread(&gameCount, sizeof(int), 1, f);
    fread(games, sizeof(Game), gameCount, f);
    nextGameID = gameCount > 0 ? games[gameCount - 1].gameID + 1 : 1;
    fclose(f);
}


void sortGames() {

    int choice;
    printf("Sortirati igre po:\n1. Naziv\n2. Min oklada\n3. Max oklada\nOdabir: ");
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

    printf("Igre sortirane.\n");
    listGames();
}
