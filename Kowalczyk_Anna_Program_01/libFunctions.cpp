#include "libFunctions.h"

//Funkcja sprawdzaj�ca, czy podana liczba znajduje si� w okre�lonym zakresie.
bool f_czyWzakresie(int podana, int poczatek, int koniec) {
    return (podana >= poczatek && podana <= koniec);
}

//Funkcja obliczaj�ca najwi�kszy wsp�lny dzielnik dw�ch liczb 
int f_NWD(int a, int b) {
    // Obliczamy NWD iteracyjnie
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Funkcja znajduj�ca najwi�ksz� liczb� wzgl�dnie pierwsz� do podanej.(wyznaczanie C)
int f_wzgledniePierwsze(int b) {
    // Szukamy najwi�kszej liczby mniejszej ni� b, kt�ra ma NWD z b r�wn� 1
    for (int i = b - 1; i > 0; i--) {
        if (f_NWD(i, b) == 1) {
            return i;
        }
    }
    return 0;
}

//Funkcja wy�wietlaj�ca zawarto�� wektora wektor�w.
void wyswietl_macierz(vector<vector<int>>& macierz) {
    for (const auto& wiersz : macierz) {
        for (const auto& element : wiersz) {
            cout << element << " ";
        }
        cout << endl; // Nowa linia po ka�dym wierszu
    }
}

//Funkcja generuj�ca tablic� pot�g dla liczb od 2 do m.
vector<vector<int>> f_tablicaPoteg(int m) {
    vector<vector<int>> mnoznik; // Wektor przechowuj�cy liczby i ich pot�gi

    for (int i = 2; i < m; i++) {
        int potega = 1; // Rozpoczynamy od pierwszej pot�gi
        vector<int> wiersz;

        // Sprawdzenie, czy p�tla jest zabezpieczona przed niesko�czono�ci�
        while ((long long)pow(i, potega) % m != 1) {
            potega++; // Zwi�kszamy pot�g�

            // Dodanie zabezpieczenia przed zbyt d�ug� p�tl�
            if (potega > m * 2) { // Limitowanie ilo�ci iteracji
                break; // Wyj�cie z p�tli, gdy limit zosta� przekroczony
            }
        }

        // Dodajemy do wektora tylko wtedy, gdy nie dosz�o do przerwania
        if (potega <= m * 2) {
            wiersz.push_back(i); // Liczba, kt�rej pot�g� sprawdzamy
            wiersz.push_back(potega); // Ostateczna pot�ga
            mnoznik.push_back(wiersz); // Dodajemy wiersz do tablicy pot�g
        }
    }

    return mnoznik; // Zwracamy wynikowy wektor pot�g
}

// Funkcja znajduje liczby z najwi�ksz� pot�g� z tablicy pot�g.
vector<int> f_znajdz_max_potege(vector<vector<int>>& mnoznik) {
    int max_potega = 0; // Pocz�tkowo najwi�ksza pot�ga to 0
    vector<int> liczby; // Wektor do przechowywania liczb z najwi�ksz� pot�g�

    // Znajdujemy najwi�ksz� pot�g�
    for (auto& wiersz : mnoznik) {
        if (wiersz[1] > max_potega) {
            max_potega = wiersz[1];
        }
    }

    // Zbieramy liczby, kt�re maj� t� najwi�ksz� pot�g�
    for (auto& wiersz : mnoznik) {
        if (wiersz[1] == max_potega) {
            liczby.push_back(wiersz[0]);
        }
    }

    return liczby; // Zwracamy liczby z najwi�ksz� pot�g�
}

//Funkcja zwracaj�ca dzielniki pierwsze liczby m.
vector<int> f_dzielniki_pierwsze(int m) {
    vector<int> dzielniki; // Wektor do przechowywania dzielnik�w pierwszych
    int n = m; // Kopia liczby m do manipulacji

    // Sprawdzamy dzielniki pierwsze od 2 do sqrt(n)
    for (int i = 2; i <= sqrt(n); i++) {
        while (n % i == 0) { // Gdy i jest dzielnikiem
            if (find(dzielniki.begin(), dzielniki.end(), i) == dzielniki.end()) {
                // Je�li i nie jest jeszcze w dzielnikach
                dzielniki.push_back(i); // Dodaj dzielnik pierwszy
            }
            n /= i; // Podzielamy przez dzielnik
        }
    }

    // Je�li po podziale zostanie liczba > 1, to jest to liczba pierwsza
    if (n > 1) {
        dzielniki.push_back(n); // Dodajemy ostatni dzielnik pierwszy
    }

    return dzielniki; // Zwracamy wektor dzielnik�w pierwszych
}

//Funkcja sprawdzaj�ca, czy liczba b jest wielokrotno�ci� dzielnik�w pierwszych m.
bool f_sprawdz_b_wielokrotnosc(int b, int m) {
    // Pobieramy dzielniki pierwsze liczby m
    vector<int> dzielniki_pierwsze = f_dzielniki_pierwsze(m);

    // Sprawdzamy, czy b jest podzielne przez wszystkie dzielniki pierwsze m
    for (int dzielnik : dzielniki_pierwsze) {
        if (b % dzielnik != 0) { // Je�li nie jest podzielne przez dzielnik
            return false; // b nie jest wielokrotno�ci� wszystkich dzielnik�w pierwszych m
        }
    }

    return true; // Je�li b jest podzielne przez wszystkie dzielniki pierwsze m
}


// Funkcja sprawdzaj�ca, czy liczba "b" jest wielokrotno�ci� 4
bool f_sprawdzWielokrotnoscCzworki(int b) {
    return (b % 4 == 0); // Zwraca true, je�li reszta z dzielenia przez 4 jest r�wna 0
}

//Funkcja generuj�ca ci�g liczb na podstawie wzoru kongruencyjnego.
vector<int> f_generuj_ciag(int a, int c, int m, int ziarno, int Y, int dolnyZakres) {
    vector<int> ciag; // Wektor do przechowywania wygenerowanego ci�gu
    int xn = ziarno; // Pocz�tkowa warto��
    for (int i = 0; i < Y; i++) {
        xn = (a * xn + c) % m; // Obliczamy kolejn� warto�� w ci�gu
        if (xn >= dolnyZakres) { // Je�li jest w odpowiednim zakresie
            ciag.push_back(xn); // Dodajemy do ci�gu
        }
    }
    return ciag; // Zwracamy wygenerowany ci�g
}

//Funkcja wy�wietlaj�ca zawarto�� wektora.
void f_wyswietl_wektor(const vector<int>& wektor) {
    for (const int& element : wektor) {
        cout << element << " "; // Wy�wietlamy ka�dy element
    }
    cout << endl; // Nowa linia po zako�czeniu wy�wietlania wektora
}

//Funkcja implementuj�ca algorytm addytywny kongruencyjny.
void f_genAddKon(vector<int>& Y, int m, int n, int& j, int& k) {


    // P�tla przeprowadzaj�ca kroki algorytmu
    for (int i = 1; i < n; ++i) {


        // Obliczamy kolejn� warto�� w ci�gu
        Y[k] = (Y[j - 1] + Y[k - 1]) % m;

        // Zmniejszamy indeksy
        k--;
        j--;

        // Sprawdzamy, czy nie wyszli�my poza zakres
        if (k == 0) {
            k = n-1; // Resetujemy do ko�ca wektora
        }

        if (j == 0) {
            j = n; // Resetujemy do ko�ca wektora
        }
    }

}

//Funkcja znajduj�ca najlepsz� par� z wektora par.
pair<int, int> f_znajdzNajPare(const vector<pair<int, int>>& pary, int n) {
    pair<int, int> najlepszaPara = { 0, 0 }; // Najlepsza para domy�lnie
    int najwiekszaRoznica = -1; // R�nica pocz�tkowo minimalna

    // Iterujemy przez wszystkie pary
    for (auto& para : pary) {
        if (para.second < n) { // Je�li druga warto�� pary jest mniejsza od n
            int roznica = para.second - para.first; // Obliczamy r�nic�

            // Je�li r�nica jest wi�ksza ni� dotychczasowa
            if (roznica > najwiekszaRoznica ||
                (roznica == najwiekszaRoznica && (para.first > najlepszaPara.first || para.second > najlepszaPara.second))) {
                najwiekszaRoznica = roznica; // Aktualizujemy najwi�ksz� r�nic�
                najlepszaPara = para; // Aktualizujemy najlepsz� par�
            }
        }
    }

    return najlepszaPara; // Zwracamy najlepsz� par�
}


