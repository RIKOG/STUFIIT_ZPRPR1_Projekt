#include <stdio.h>
#include "functions.c"

#define MAXPOLE 1000

int main() {
    char Upravene[MAXPOLE], Povodne[MAXPOLE];
    int Dlzka_Povodne = 0, Dlzka_Upravene = 0;
    char zadanie = 0;
    while (zadanie != 'k') {
        switch (zadanie = getchar()) {
            case 'n':
                Dlzka_Povodne = povodny_text(Povodne);
                break;

            case 'v':
                vypis_znakov(Povodne, Dlzka_Povodne);
                break;

            case 'w':
                vypis_znakov_odzadu(Povodne, Dlzka_Povodne);
                break;

            case 'u':
                Dlzka_Upravene = prepis(Povodne, Upravene, Dlzka_Povodne);
                break;

            case 's':
                vypis_znakov_nove(Upravene, Dlzka_Upravene);
                break;

            case 'd':
                vypis_nebiele_znaky(Povodne, Dlzka_Povodne);
                break;

            case 'f':
                vypis_biele_znaky(Povodne, Dlzka_Povodne);
                break;

            case 'h':
                histogram(Upravene, Dlzka_Upravene);
                break;

            case 'c':
                cezarova_sifra(Upravene, Dlzka_Upravene);
                break;

            case '*':
                hviezda();
                break;

            case '^':
                pyramida();
                break;
        }
    }
    return 0;
}