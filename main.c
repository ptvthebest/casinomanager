#define _CRT_SECURE_NO_WARNINGS
#include "casino.h"

Player players[100];
Game games[100];
int playerCount = 0;
int gameCount = 0;
int nextPlayerID = 1;
int nextGameID = 1;

// Dodavanje novog igrača
void addPlayer() {
    Player p;
    p.playerID = nextPlayerID++;

    printf("Ime: ");
    scanf("%s", p.firstName);
    printf("Prezime: ");
    scanf("%s", p.lastName);
    printf("Saldo: ");
    scanf("%lf", &p.balance);

    players[playerCount++] = p;
    printf("Igrač dodan.\n");
}

// Ispis svih igrača
void listPlayers() {
    printf("\nPopis igrača:\n");
    for (int i = 0; i < playerCount; i++) {
        printf("ID: %d | %s %s | Saldo: %.2f\n", players[i].playerID, players[i].firstName, players[i].lastName, players[i].balance);
    }
}

// Ažuriranje podataka igrača
void updatePlayer() {
    int id;
    printf("Unesite ID igrača za ažuriranje: ");
    scanf("%d", &id);

    for (int i = 0; i < playerCount; i++) {
        if (players[i].playerID == id) {
            printf("Novo ime: ");
            scanf("%s", players[i].firstName);
            printf("Novo prezime: ");
            scanf("%s", players[i].lastName);
            printf("Novi saldo: ");
            scanf("%lf", &players[i].balance);
            printf("Igrač ažuriran.\n");
            return;
        }
    }

    printf("Igrač s tim ID-om nije pronađen.\n");
}

// Brisanje igrača
void deletePlayer() {
    int id;
    printf("Unesite ID igrača za brisanje: ");
    scanf("%d", &id);

    for (int i = 0; i < playerCount; i++) {
        if (players[i].playerID == id) {
            for (int j = i; j < playerCount - 1; j++) {
                players[j] = players[j + 1];
            }
            playerCount--;
            printf("Igrač obrisan.\n");
            return;
        }
    }

    printf("Igrač s tim ID-om nije pronađen.\n");
}

// Spremanje igrača u datoteku
void savePlayers() {
    FILE* f = fopen("players.dat", "wb");
    if (!f) return;
    fwrite(&playerCount, sizeof(int), 1, f);
    fwrite(players, sizeof(Player), playerCount, f);
    fclose(f);
}

// Učitavanje igrača iz datoteke
void loadPlayers() {
    FILE* f = fopen("players.dat", "rb");
    if (!f) return;
    fread(&playerCount, sizeof(int), 1, f);
    fread(players, sizeof(Player), playerCount, f);
    fclose(f);
}

// Dodavanje igre
void addGame() {
    Game g;
    g.gameID = nextGameID++;

    printf("Naziv igre: ");
    scanf("%s", g.gameName);
    printf("Minimalna oklada: ");
    scanf("%lf", &g.minBet);
    printf("Maksimalna oklada: ");
    scanf("%lf", &g.maxBet);

    games[gameCount++] = g;
    printf("Igra dodana.\n");
}

// Ispis svih igara
void listGames() {
    printf("\nPopis igara:\n");
    for (int i = 0; i < gameCount; i++) {
        printf("ID: %d | %s | Min: %.2f | Max: %.2f\n", games[i].gameID, games[i].gameName, games[i].minBet, games[i].maxBet);
    }
}

// Ažuriranje igre
void updateGame() {
    int id;
    printf("Unesite ID igre za ažuriranje: ");
    scanf("%d", &id);

    for (int i = 0; i < gameCount; i++) {
        if (games[i].gameID == id) {
            printf("Novi naziv igre: ");
            scanf("%s", games[i].gameName);
            printf("Nova minimalna oklada: ");
            scanf("%lf", &games[i].minBet);
            printf("Nova maksimalna oklada: ");
            scanf("%lf", &games[i].maxBet);
            printf("Igra ažurirana.\n");
            return;
        }
    }

    printf("Igra s tim ID-om nije pronađena.\n");
}

// Brisanje igre
void deleteGame() {
    int id;
    printf("Unesite ID igre za brisanje: ");
    scanf("%d", &id);

    for (int i = 0; i < gameCount; i++) {
        if (games[i].gameID == id) {
            for (int j = i; j < gameCount - 1; j++) {
                games[j] = games[j + 1];
            }
            gameCount--;
            printf("Igra obrisana.\n");
            return;
        }
    }

    printf("Igra s tim ID-om nije pronađena.\n");
}

// Spremanje igara u datoteku
void saveGames() {
    FILE* f = fopen("games.dat", "wb");
    if (!f) return;
    fwrite(&gameCount, sizeof(int), 1, f);
    fwrite(games, sizeof(Game), gameCount, f);
    fclose(f);
}

// Učitavanje igara iz datoteke
void loadGames() {
    FILE* f = fopen("games.dat", "rb");
    if (!f) return;
    fread(&gameCount, sizeof(int), 1, f);
    fread(games, sizeof(Game), gameCount, f);
    fclose(f);
}

// Sortiranje igrača (bubble sort)
void sortPlayers() {
    int choice;
    printf("\nSortiranje igrača:\n1. Po imenu\n2. Po prezimenu\n3. Po saldu\nOdabir: ");
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

    printf("Igrači su sortirani.\n");
    listPlayers();
}

// Sortiranje igara (bubble sort)
void sortGames() {
    int choice;
    printf("\nSortiranje igara:\n1. Po imenu\n2. Po min. okladi\n3. Po max. okladi\nOdabir: ");
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
