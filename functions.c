#include <stdio.h>
#include "functions.h"

#define MAXPOLE 1000
#define ABECEDA 26
#define LOWERCASE 32 // po odrátaní 32 od malej abecedy sa dostanete na uppercase

int povodny_text(char *znaky) {
    FILE *fr;
    int i = 0;
    char c;

    if ((fr = fopen("c:/Users/richg/Desktop/PPProjekt/bugtest.txt", "r")) == NULL) {
        printf(" Spravu sa nepodarilo nacitat \n");
    } else {

        while ((c = getc(fr)) != EOF && i <= MAXPOLE) {
            znaky[i++] = c;
        }
        if (fclose(fr) == EOF) {
            printf("Chyba: zatvarania suboru.");
        }
        return i;
    }
}

void vypis_znakov_odzadu(char znaky[], int dlzka) {
    if (dlzka == 0) {
        printf("Sprava nie je nacitana. \n");
    } else {
        for (int i = dlzka; i >= 0; i--) {
            putchar(znaky[i]);
        }
        putchar('\n');
    }
}

void vypis_znakov(char znaky[], int dlzka) {
    if (dlzka == 0) {
        printf("Sprava nie je nacitana. \n");
    } else {
        for (int i = 0; i < dlzka; i++) {
            putchar(znaky[i]);
        }
        putchar('\n');
    }
}

int prepis(char znaky[], char noveznaky[], int dlzka) {
    int j = 0;
    if (dlzka == 0) {
        printf("Sprava nie je nacitana. \n");
    } else {
        for (int i = 0; i < dlzka; i++) {
            if (znaky[i] >= 'a' && znaky[i] <= 'z') {
                noveznaky[j++] = znaky[i] - LOWERCASE;
            } else if (znaky[i] >= 'A' && znaky[i] <= 'Z') {
                noveznaky[j++] = znaky[i];
            }
        }
        return j;
    }
}

void vypis_znakov_nove(char znaky[], int dlzka) {
    if (dlzka == 0) {
        printf("Nie je k dispozicii upravena sprava. \n");
    } else {
        for (int i = 0; i < dlzka; i++) {
            putchar(znaky[i]);
        }
        putchar('\n');
    }
}


void vypis_nebiele_znaky(char znaky[], int dlzka) {
    int k = 0, dlzkacitania = 0;
    scanf("%d", &k);

    if (dlzka == 0) {
        printf("Sprava nie je nacitana. \n");
    } else if
            (k < 1 || k > 100) {
        printf("Bola zadaná nesprávna hodnota, skúste znova v rozmedzí 1 až 100 \n");
        scanf("%d", &k);
    } else {
        for (int i = 0; i < dlzka; i++) {
            dlzkacitania++;
            if ((znaky[i] == ' ' || znaky[i] == '\n') && dlzkacitania != k + 1) {
                dlzkacitania = 0;
            } else if ((znaky[i] == ' ' || znaky[i] == '\n') && dlzkacitania == k + 1) {
                for (int j = i - dlzkacitania + 1; j < i; j++) {
                    putchar(znaky[j]);
                }
                putchar('\n');
            }
        }
        if (dlzkacitania == k) {
            int i = dlzka - 1;
            for (int j = i - dlzkacitania + 1; j < i + 1; j++) {
                putchar(znaky[j]);
            }
            putchar('\n');
        }

    }
}

void vypis_biele_znaky(char znaky[], int dlzka) {
    int k = 0, dlzkacitania = 0;
    scanf("%d", &k);

    if (dlzka == 0) {
        printf("Sprava nie je nacitana. \n");
    } else {
        for (int i = 0; i < dlzka; i++) {
            if (znaky[i] >= 'a' && znaky[i] <= 'z') {
                continue;
            } else {
                putchar(znaky[i]);
            }
        }
        putchar('\n');
    }
}

void histogram(char znaky[], int dlzka) {
    int pocetnosti[ABECEDA] = {0};
    int kontrola = 0;

    for (int i = 0; i < dlzka; i++) {
        char pozicia = znaky[i] - 65;
        pocetnosti[pozicia]++;
    }

    for (char riadok = 10; riadok >= 0; riadok--) {
        for (char znak = 0; znak < ABECEDA; znak++) {
            if (pocetnosti[znak] * 100 / dlzka > riadok * 10) {
                kontrola++;
            }
        }
        if (kontrola != 0) {
            for (char znak = 0; znak < ABECEDA; znak++) {
                if (pocetnosti[znak] * 100 / dlzka > riadok * 10) {
                    putchar('*');
                } else {
                    putchar(' ');
                }
            }
            putchar('\n');
        }
    }
    for (char i = 0; i < ABECEDA; i++) {
        putchar(i + 65);
    }
}

void cezarova_sifra(char znaky[], int dlzka) {
    int n = 0;
    scanf("%d", &n);
    if (dlzka == 0) {
        printf("Neobsahuje nic.");
    } else {
        for (int i = 0; i < dlzka; i++) {
            char znak = znaky[i] - n;
            if (znak < 65) {
                znaky[i] = 'Z' + (znak - 65) + 1;
                putchar(znaky[i]);
            } else {
                znaky[i] -= n;
                putchar(znaky[i]);
            }
        }
    }
}

void hviezda() {
    int i, j, n;
    scanf("%d", &n);
    if (n < 1 || n > 15 || n % 2 == 0) {
        printf("Zly vstup");
        return 0;
    }
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (j == i || (j == n - i + 1)) {
                printf("*");
            } else if (i == n / 2 + 1) {
                for (j = 1; j <= n; j++) {
                    printf("*");
                }
            } else if (j == n / 2 + 1) {
                printf("*");
            } else {
                printf("-");
            }
        }
        printf("\n");
    }
}

void pyramida() {
    int i, j, pocet;
    scanf("%d", &pocet);
    if (pocet < 1 || pocet > 15 || pocet % 2 == 0) {
        printf("Zly vstup");
    }
    for (i = 1; i <= pocet; i++) {
        for (j = 1; j <= pocet; j++) {
            if (i >= j) {
                putchar('*');
            } else {
                putchar(' ');
            }
        }
        putchar('\n');
    }
    for (i = 1; i <= pocet; i++) {
        for (j = pocet; j >= 1; j--) {
            if (i >= j) {
                putchar(' ');
            } else {
                putchar('*');
            }
        }
        putchar('\n');
    }
}
