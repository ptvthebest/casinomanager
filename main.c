#define _CRT_SECURE_NO_WARNINGS
#include "casino.h"

int main() {
    loadPlayers();
    loadGames();

    int choice;
    while (1) {
        printf("\nCasino Game Manager\n");
        printf("1. Dodaj igrača\n2. Prikaz svih igrača\n3. Ažuriraj igrača\n4. Obriši igrača\n");
        printf("5. Dodaj igru\n6. Prikaz svih igara\n7. Sortiraj igrače\n8. Sortiraj igre\n0. Izlaz\n");
        printf("Odabir: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: addPlayer(); break;
        case 2: listPlayers(); break;
        case 3: updatePlayer(); break;
        case 4: deletePlayer(); break;
        case 5: addGame(); break;
        case 6: listGames(); break;
        case 7: sortPlayers(); break; // ✅ Novo
        case 8: sortGames(); break;   // ✅ Novo
        case 0:
            savePlayers();
            saveGames();
            printf("Izlaz.\n");
            return 0;
        default:
            printf("Nevažeća opcija.\n");
        }
    }
}

