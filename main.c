#define _CRT_SECURE_NO_WARNINGS

#include "casino.h"

int main() {
    loadPlayers();
    loadGames();

    int opcija;
    do {
        printf("\n--- Casino Manager ---\n");
        printf("1. Dodaj igraca\n");
        printf("2. Prikazi igrace\n");
        printf("3. Azuriraj saldo igraca\n");
        printf("4. Obrisi igraca\n");
        printf("5. Sortiraj igrace\n");
        printf("6. Dodaj igru\n");
        printf("7. Prikazi igre\n");
        printf("8. Sortiraj igre\n");
        printf("0. Izlaz\n");
        printf("Odabir: ");
        scanf("%d", &opcija);

        switch (opcija) {
        case 1: addPlayer();
            break;
        case 2: listPlayers(); 
            break;
        case 3: updatePlayer();
            break;
        case 4: deletePlayer(); 
            break;
        case 5: sortPlayers(); 
            break;
        case 6: addGame(); 
            break;
        case 7: listGames(); 
            break;
        case 8: sortGames();
            break;
        case 0: printf("Izlaz...\n"); 
            break;
        default: printf("Nepoznata opcija.\n");
        }
    } while (opcija != 0);

    return 0;
}
