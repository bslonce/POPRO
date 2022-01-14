#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>

#define MAXKOMENDA 50;
#define MAXNAZWA 20;

/*
1. Wyjście z programu poleceniem exit
2. Dodanie wierzchołka poleceniem a : L, gdzie L jest etykietą dodawanego wierzchołka.
3. Dodanie krawędzi poleceniem a : L1 , L2, gdzie L1 i L2 to etykiety wskazujące wierzchołki, między którymi
ma być utworzona krawędź.
4. Usunięcie wierzchołka poleceniem r : L
5. Usunięcie krawędzi poleceniem r: L1 , L2
6. Zapis do pliku tekstowego o zadanej przez użytkownika nazwie listy sąsiedztwa grafu (polecenie save
nazwa_pliku).
7. Zapis do pliku binarnego o zadanej przez użytkownika nazwie etykiet będących aktualnie w użyciu
(polecenie dump nazwa_pliku).
8. Wypisanie na standardowym wyjściu etykiet będących aktualnie w użyciu w postaci pionowego wektora
(polecenie list).
9. Wywołanie skryptu (plik tekstowy), w którym w kolejnych liniach znajdują się polecenia zdefiniowane w
poprzednich punktach (polecenie run nazwa_skryptu)
*/


struct macierz
{
    char nazwaMacierzy[MAXNAZWA];
    int liczbaKolumn;
    char zawartosc[];
    struct macierz* nastepny;
};

typedef struct macierz macierz;
typedef struct macierz* wskMacierz;

void wynegerujSkrypt()
{
    FILE *fptr;
    if(fptr=fopen("Instrukcja.txt", "r")!=NULL)
    {
        fprintf(stdout, "Plik ze skryptem zostal juz wygenerowany wczesniej\n");
        fclose(fptr);
    }
    else
    {
        if(fptr=fopen("Instrukcja.txt", "w")!=NULL) //zabezpieczenie przed nieprawidlowym otwieraniem pliku
        {
        fprintf(fptr, "Wyjscie z programu poleceniem Exit\n");
        fclose(fptr);
        }
        else
        {
            fprintf(stdout, "Blad!");
        }
    }
}

wskMacierz dodajMacierz (int liczbaElementow)
{
    wskMacierz nowaMacierz = malloc(sizeof(char)*MAXNAZWA+sizeof(wskMacierz)+sizeof(int)+sizeof(char)*liczbaElementow);
    return nowaMacierz;
}

int liczElTabeli (char tab[])
{
    int i=0;
    int liczbaEl=0;
    while(tab[i]!=NULL)
    {
        i++;
        liczbaEl++;
    }
    return liczbaEl;
}

wskMacierz polaczenieSzeregowe (wskMacierz s1, wskMacierz s2, nazwaNowejMacierzy)
{
    int liczbaEl1=liczElTabeli(s1->zawartosc);
    int liczbaEl2=liczElTabeli(s2->zawartosc);
    int liczbaWierszy1=liczbaArg1/(s1->liczbakolumn);
    int liczbaWierszy2=liczbaArg2/(s2->liczbakolumn);
    if(liczbaWierszy1 != liczbaWierszy2)
    {
        fprintf(stdout, "BLAD\nnie da sie polaczyc szeregowo macierzy o dwoch roznych liczbach wierszy\n\n");
    }
    else
    {
        int nowaLiczbaElMacierzy = liczbaEl1+liczbaEl2;
        wskMacierz nowaMacierz=dodajMacierz(nowaLiczbaElMacierzy);
        int nowaMacierz.liczbakolumn = (s1->liczbakolumn) + (s2->liczbakolumn);
        strcpy(nowaMacierz->nazwaMacierzy, nazwaNowejMacierzy);
        for(int i=0; i<liczbaArg1, i++)
        {
            nowaMacierz->zawartosc[i]=s1->zawartosc[i];
        }
        for(int i=0; i<liczbaArg2, i++)
        {
            nowaMacierz->zawartosc[i+liczbaArg1]=s2->zawartosc[i];
        }
        return nowaMacierz;
    }
    
}


int main()
{
    int c = 0;
    int i = 0;

    char kom[MAXKOMENDA];

    while (c != '') //wczytwanie komend
    {
        c = getchar();
        kom[i++] = c;
    }

    if (strcmp(kom, "Run") == 0) // Instrukcja obslugi
    {
        wygenerujSkrypt();
    }

    if (strcmp(kom, "Exit")==0)
    {
        exit(0);
    }
}
