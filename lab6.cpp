#include <iostream>
#include <stdlib.h>

struct Towar {
    char nazwa[20];
    float cena;
    int ilosc;
};

void createNewTab(Towar*& tab, int& rozmiar) {
    delete[] tab;
    tab = new Towar[rozmiar];
    for (int i = 0; i < rozmiar; i++) {
        std::cout << "Podaj nazwe towaru: ";
        std::cin >> tab[i].nazwa;
        std::cout << "Podaj cene towaru: ";
        std::cin >> tab[i].cena;
        std::cout << "Podaj ilosc towaru: ";
        std::cin >> tab[i].ilosc;
    }
}

void printTab(Towar* tab, int rozmiar) {
    if (tab == nullptr) {
        std::cout << "Tablica jest pusta" << std::endl;
        return;
    };
    for (int i = 0; i < rozmiar; i++) {
        std::cout << "Nazwa: " << tab[i].nazwa << "\t";
        std::cout << "Cena: " << tab[i].cena << "\t";
        std::cout << "Ilosc: " << tab[i].ilosc << "\n";
    }
    std::cout << std::endl;
}

void addItem(Towar newItem, Towar* tab, int rozmiar) {
    Towar* newTab = new Towar[rozmiar + 1];
    for (int i = 0; i < rozmiar; i++) {
        newTab[i] = tab[i];
    }
    newTab[rozmiar] = newItem;
    delete[] tab;
    tab = newTab;
}

void deleteItem(Towar* tab, int rozmiar, int idx) {
    Towar* newTab = new Towar[rozmiar - 1];
    for (int i = 0; i < idx; i++) {
        newTab[i] = tab[i];
    }
    for (int i = idx + 1; i < rozmiar; i++) {
        newTab[i - 1] = tab[i];
    }
    delete[] tab;
    tab = newTab;
}

void deleteTab(Towar*& tab, int& rozmiar) {
    delete[] tab;
    rozmiar = 0;
    tab = nullptr;
}

int main() {
    std::cout << "Mikolaj Bien\npon 11:15\n24.10.2022 / 25.10.2022\nnumer albumu: 272950\n\n";


    Towar* tab = nullptr;
    int rozmiar = 0;

    int opcja = 0;

    std::cout << "Witaj w programie do zarzadzania towarami" << "\n\n";
    while (true) {
        std::cout << "1. Utworz nowa tablice" << std::endl;
        std::cout << "2. Wyswietl tablice" << std::endl;
        std::cout << "3. Dodaj nowy element" << std::endl;
        std::cout << "4. Usun element" << std::endl;
        std::cout << "5. Usun tablice" << std::endl;
        std::cout << "6. Zakoncz program" << std::endl;
        std::cout << "Wybierz opcje: ";

        if (opcja == 0) {
            opcja = 1;
        }
        else {
            std::cin >> opcja;
        }

        switch (opcja) {
        case 1:
            std::cout << "Podaj rozmiar tablicy: ";
            std::cin >> rozmiar;
            createNewTab(tab, rozmiar);
            break;
        case 2:
            printTab(tab, rozmiar);
            break;
        case 3:
            Towar newItem;
            std::cout << "Podaj nazwe towaru: ";
            std::cin >> newItem.nazwa;
            std::cout << "Podaj cene towaru: ";
            std::cin >> newItem.cena;
            std::cout << "Podaj ilosc towaru: ";
            std::cin >> newItem.ilosc;
            addItem(newItem, tab, rozmiar);
            rozmiar++;
            break;
        case 4:
            std::cout << "Podaj indeks elementu do usuniecia: ";
            int idx;
            std::cin >> idx;
            deleteItem(tab, rozmiar, idx);
            rozmiar--;
            break;
        case 5:
            deleteTab(tab, rozmiar);
            break;
        case 6:
            deleteTab(tab, rozmiar);
            exit(0);
        default:
            std::cout << "Nie ma takiej opcji" << std::endl;
            break;
        }

        return 0;
    }
}