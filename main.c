#include "header/participant.h"
#include "header/mylist.h"
#include "header/service.h"

#include <stdio.h>

//CONCURS DE PROGRAMARE


void test() {
    testAddParticipant();
    testUpdateParticipant();
    testDeleteParticipant();
    testDestructParticipant();
    testDestroyList();
}

/// Prints the application menu
void print_menu() {
    printf("\n********MENIU********\n");
    printf("1. Adauga participant\n");
    printf("2. Actualizeaza participant\n");
    printf("3. Sterge participanti\n");
    printf("4. Filtreaza participanti\n");
    printf("5. Sorteaza participanti\n");
    printf("6. Iesire\n\n");
}

void addMenuParticipant(MyList* l) {
    printf("Nume: ");
    char nume[30];
    scanf_s("%s", nume, 30);
    printf("Prenume: ");
    char prenume[30];
    scanf_s("%s", prenume, 30);
    printf("Scor:");
    float scor;
    scanf_s("%f", &scor);
    int error = addParticipant(l, constructParticipant(nume, prenume, scor));
    if (error != 0) {
        printf("Participant invalid.\n");
    }
    else {
        printf("Participant adaugat.\n");
    }
}

void updateMenuParticipant(MyList* l) {
    printf("Nume vechi: ");
    char nume[30];
    scanf_s("%s", nume, 30);
    printf("Prenume vechi: ");
    char prenume[30];
    scanf_s("%s", prenume, 30);
    printf("Scor vechi:");
    float scor;
    scanf_s("%f", &scor);
    printf("Nume nou: ");
    char numenou[30];
    scanf_s("%s", numenou, 30);
    printf("Prenume nou: ");
    char prenumenou[30];
    scanf_s("%s", prenumenou, 30);
    printf("Scor nou:");
    float scornou;
    scanf_s("%f", &scornou);
    int error = updateParticipant(l, constructParticipant(nume, prenume, scor),
                                  constructParticipant(numenou, prenumenou, scornou));
    if (error != 0) {
        printf("Participant invalid.\n");
    }
    else {
        printf("Participant modificat.\n");
    }
}

void deleteMenuParticipant(MyList* l) {
    printf("Nume: ");
    char nume[30];
    scanf_s("%s", nume, 30);
    printf("Prenume: ");
    char prenume[30];
    scanf_s("%s", prenume, 30);
    printf("Scor:");
    float scor;
    scanf_s("%f", &scor);
    int error = deleteParticipant(l, constructParticipant(nume, prenume, scor));
    if (error != 0) {
        printf("Participant invalid.\n");
    }
    else {
        printf("Participant adaugat.\n");
    }
}


void run() {
    MyList database = create();
    int exit = 1;
    while (exit) {
        print_menu();
        int option;
        printf("Introduceti optiunea dvs: ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                addMenuParticipant(&database);
                break;
            case 2:
                updateMenuParticipant(&database);
                break;
            case 3:
                deleteMenuParticipant(&database);
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                destroy(&database);
                exit = 0;
                break;
            default:
                printf("OPTIUNE INVALIDA!");
        }
        printf("Lungimea listei este %d", size(&database));
    }
}

int main() {
    test();
    run();
    return 0;
}
