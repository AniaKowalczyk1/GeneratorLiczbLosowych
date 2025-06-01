#include "libFunctions.h"

//Funkcja sprawdzaj¹ca, czy podana liczba znajduje siê w okreœlonym zakresie.
bool f_czyWzakresie(int podana, int poczatek, int koniec) {
    return (podana >= poczatek && podana <= koniec);
}

//Funkcja obliczaj¹ca najwiêkszy wspólny dzielnik dwóch liczb 
int f_NWD(int a, int b) {
    // Obliczamy NWD iteracyjnie
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Funkcja znajduj¹ca najwiêksz¹ liczbê wzglêdnie pierwsz¹ do podanej.(wyznaczanie C)
int f_wzgledniePierwsze(int b) {
    // Szukamy najwiêkszej liczby mniejszej ni¿ b, która ma NWD z b równ¹ 1
    for (int i = b - 1; i > 0; i--) {
        if (f_NWD(i, b) == 1) {
            return i;
        }
    }
    return 0;
}

//Funkcja wyœwietlaj¹ca zawartoœæ wektora wektorów.
void wyswietl_macierz(vector<vector<int>>& macierz) {
    for (const auto& wiersz : macierz) {
        for (const auto& element : wiersz) {
            cout << element << " ";
        }
        cout << endl; // Nowa linia po ka¿dym wierszu
    }
}

//Funkcja generuj¹ca tablicê potêg dla liczb od 2 do m.
vector<vector<int>> f_tablicaPoteg(int m) {
    vector<vector<int>> mnoznik; // Wektor przechowuj¹cy liczby i ich potêgi

    for (int i = 2; i < m; i++) {
        int potega = 1; // Rozpoczynamy od pierwszej potêgi
        vector<int> wiersz;

        // Sprawdzenie, czy pêtla jest zabezpieczona przed nieskoñczonoœci¹
        while ((long long)pow(i, potega) % m != 1) {
            potega++; // Zwiêkszamy potêgê

            // Dodanie zabezpieczenia przed zbyt d³ug¹ pêtl¹
            if (potega > m * 2) { // Limitowanie iloœci iteracji
                break; // Wyjœcie z pêtli, gdy limit zosta³ przekroczony
            }
        }

        // Dodajemy do wektora tylko wtedy, gdy nie dosz³o do przerwania
        if (potega <= m * 2) {
            wiersz.push_back(i); // Liczba, której potêgê sprawdzamy
            wiersz.push_back(potega); // Ostateczna potêga
            mnoznik.push_back(wiersz); // Dodajemy wiersz do tablicy potêg
        }
    }

    return mnoznik; // Zwracamy wynikowy wektor potêg
}

// Funkcja znajduje liczby z najwiêksz¹ potêg¹ z tablicy potêg.
vector<int> f_znajdz_max_potege(vector<vector<int>>& mnoznik) {
    int max_potega = 0; // Pocz¹tkowo najwiêksza potêga to 0
    vector<int> liczby; // Wektor do przechowywania liczb z najwiêksz¹ potêg¹

    // Znajdujemy najwiêksz¹ potêgê
    for (auto& wiersz : mnoznik) {
        if (wiersz[1] > max_potega) {
            max_potega = wiersz[1];
        }
    }

    // Zbieramy liczby, które maj¹ tê najwiêksz¹ potêgê
    for (auto& wiersz : mnoznik) {
        if (wiersz[1] == max_potega) {
            liczby.push_back(wiersz[0]);
        }
    }

    return liczby; // Zwracamy liczby z najwiêksz¹ potêg¹
}

//Funkcja zwracaj¹ca dzielniki pierwsze liczby m.
vector<int> f_dzielniki_pierwsze(int m) {
    vector<int> dzielniki; // Wektor do przechowywania dzielników pierwszych
    int n = m; // Kopia liczby m do manipulacji

    // Sprawdzamy dzielniki pierwsze od 2 do sqrt(n)
    for (int i = 2; i <= sqrt(n); i++) {
        while (n % i == 0) { // Gdy i jest dzielnikiem
            if (find(dzielniki.begin(), dzielniki.end(), i) == dzielniki.end()) {
                // Jeœli i nie jest jeszcze w dzielnikach
                dzielniki.push_back(i); // Dodaj dzielnik pierwszy
            }
            n /= i; // Podzielamy przez dzielnik
        }
    }

    // Jeœli po podziale zostanie liczba > 1, to jest to liczba pierwsza
    if (n > 1) {
        dzielniki.push_back(n); // Dodajemy ostatni dzielnik pierwszy
    }

    return dzielniki; // Zwracamy wektor dzielników pierwszych
}

//Funkcja sprawdzaj¹ca, czy liczba b jest wielokrotnoœci¹ dzielników pierwszych m.
bool f_sprawdz_b_wielokrotnosc(int b, int m) {
    // Pobieramy dzielniki pierwsze liczby m
    vector<int> dzielniki_pierwsze = f_dzielniki_pierwsze(m);

    // Sprawdzamy, czy b jest podzielne przez wszystkie dzielniki pierwsze m
    for (int dzielnik : dzielniki_pierwsze) {
        if (b % dzielnik != 0) { // Jeœli nie jest podzielne przez dzielnik
            return false; // b nie jest wielokrotnoœci¹ wszystkich dzielników pierwszych m
        }
    }

    return true; // Jeœli b jest podzielne przez wszystkie dzielniki pierwsze m
}


// Funkcja sprawdzaj¹ca, czy liczba "b" jest wielokrotnoœci¹ 4
bool f_sprawdzWielokrotnoscCzworki(int b) {
    return (b % 4 == 0); // Zwraca true, jeœli reszta z dzielenia przez 4 jest równa 0
}

//Funkcja generuj¹ca ci¹g liczb na podstawie wzoru kongruencyjnego.
vector<int> f_generuj_ciag(int a, int c, int m, int ziarno, int Y, int dolnyZakres) {
    vector<int> ciag; // Wektor do przechowywania wygenerowanego ci¹gu
    int xn = ziarno; // Pocz¹tkowa wartoœæ
    for (int i = 0; i < Y; i++) {
        xn = (a * xn + c) % m; // Obliczamy kolejn¹ wartoœæ w ci¹gu
        if (xn >= dolnyZakres) { // Jeœli jest w odpowiednim zakresie
            ciag.push_back(xn); // Dodajemy do ci¹gu
        }
    }
    return ciag; // Zwracamy wygenerowany ci¹g
}

//Funkcja wyœwietlaj¹ca zawartoœæ wektora.
void f_wyswietl_wektor(const vector<int>& wektor) {
    for (const int& element : wektor) {
        cout << element << " "; // Wyœwietlamy ka¿dy element
    }
    cout << endl; // Nowa linia po zakoñczeniu wyœwietlania wektora
}

//Funkcja implementuj¹ca algorytm addytywny kongruencyjny.
void f_genAddKon(vector<int>& Y, int m, int n, int& j, int& k) {


    // Pêtla przeprowadzaj¹ca kroki algorytmu
    for (int i = 1; i < n; ++i) {


        // Obliczamy kolejn¹ wartoœæ w ci¹gu
        Y[k] = (Y[j - 1] + Y[k - 1]) % m;

        // Zmniejszamy indeksy
        k--;
        j--;

        // Sprawdzamy, czy nie wyszliœmy poza zakres
        if (k == 0) {
            k = n-1; // Resetujemy do koñca wektora
        }

        if (j == 0) {
            j = n; // Resetujemy do koñca wektora
        }
    }

}

//Funkcja znajduj¹ca najlepsz¹ parê z wektora par.
pair<int, int> f_znajdzNajPare(const vector<pair<int, int>>& pary, int n) {
    pair<int, int> najlepszaPara = { 0, 0 }; // Najlepsza para domyœlnie
    int najwiekszaRoznica = -1; // Ró¿nica pocz¹tkowo minimalna

    // Iterujemy przez wszystkie pary
    for (auto& para : pary) {
        if (para.second < n) { // Jeœli druga wartoœæ pary jest mniejsza od n
            int roznica = para.second - para.first; // Obliczamy ró¿nicê

            // Jeœli ró¿nica jest wiêksza ni¿ dotychczasowa
            if (roznica > najwiekszaRoznica ||
                (roznica == najwiekszaRoznica && (para.first > najlepszaPara.first || para.second > najlepszaPara.second))) {
                najwiekszaRoznica = roznica; // Aktualizujemy najwiêksz¹ ró¿nicê
                najlepszaPara = para; // Aktualizujemy najlepsz¹ parê
            }
        }
    }

    return najlepszaPara; // Zwracamy najlepsz¹ parê
}


