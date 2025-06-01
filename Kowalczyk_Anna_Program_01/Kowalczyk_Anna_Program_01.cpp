#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include "libFiles.h"
#include "libFunctions.h"
#include "libExceptions.h" 

using namespace std;
using namespace MyRuntimeExceptions; 

int main() {
    try {
        int metoda = 0;

        // Pytamy użytkownika o metodę
        while (metoda != 1 && metoda != 2) {
            cout << "Wybierz metode: \n (1) Kongruencyjna \n (2) Addytywna kongruencyjna" << endl;
            cin >> metoda;
            if (cin.fail() || (metoda != 1 && metoda != 2)) {
                throw MainException("Niepoprawny wybor metody. Wprowadz 1 lub 2.");
            }
        }

        // Pobieramy ilość liczb do wygenerowania
        int n;
        do {
            cout << "Ile liczb chcesz wygenerowac?" << endl;
            cin >> n;
            if (cin.fail() || n <= 0) {
                throw MainException("Liczba musi być większa od 0.");
            }
        } while (n <= 0);

        if (metoda == 1) { // Metoda kongruencyjna
            int xmin;
            do {
                cout << "Podaj xmin:" << endl;
                cin >> xmin;
                if (cin.fail() || xmin < 0) {
                    throw MainException("xmin musi być nieujemne.");
                }
            } while (xmin < 0);

            int xmax;
            do {
                cout << "Podaj xmax:" << endl;
                cin >> xmax;
                if (cin.fail() || xmax <= 0) {
                    throw MainException("xmax musi być większe od 0.");
                }
            } while (xmax <= 0);

            int m = xmax + 1; // Modulo to xmax + 1

            int ziarno;
            do {
                cout << "Podaj ziarno:" << endl;
                cin >> ziarno;
                if (cin.fail() || !f_czyWzakresie(ziarno, xmin, xmax)) {
                    throw MainException("Ziarno musi być w zakresie xmin i xmax.");
                }
            } while (!f_czyWzakresie(ziarno, xmin, xmax)); // Upewniamy się, że ziarno jest w zakresie

            int c = f_wzgledniePierwsze(m); // Znajdujemy "c" jako największą względnie pierwszą liczbę do "m"

            int a = 0;
            vector<vector<int>> mnoznik = f_tablicaPoteg(m); // Generujemy tablicę potęg

            // Znajdujemy liczby z największą potęgą
            vector<int> liczbyZMaxPot = f_znajdz_max_potege(mnoznik);

            // Sprawdzamy, które liczby mają wartości wielokrotności dzielników pierwszych
            vector<int> sprawdzone;
            for (int i = 0; i < liczbyZMaxPot.size(); i++) {
                int b = liczbyZMaxPot[i] - 1;
                if (f_sprawdz_b_wielokrotnosc(b, m)) {
                    sprawdzone.push_back(liczbyZMaxPot[i]);
                }
            }

            // Wektor do przechowywania liczb spełniających warunek 2 i 3
            vector<int> wynikowe;

            // Sprawdzamy, czy moduł jest wielokrotnością 4 oraz czy wektor "sprawdzone" nie jest pusty
            if (m % 4 == 0 && sprawdzone.size() != 0) {
                // Przeglądamy każdą wartość z listy "sprawdzone"
                for (int i = 0; i < sprawdzone.size(); i++) {
                    // Odejmuje jeden od wartości, aby uzyskać "b = a - 1"
                    int b = sprawdzone[i] - 1;

                    // Sprawdzamy, czy "b" jest wielokrotnością 4
                    if (f_sprawdzWielokrotnoscCzworki(b)) {
                        // Jeśli tak, dodajemy do listy "wynikowe"
                        wynikowe.push_back(sprawdzone[i]);
                    }
                }
            }

            if (wynikowe.size() == 0 && liczbyZMaxPot.size() != 0) {
                a = liczbyZMaxPot.back(); // Używamy ostatniej wartości z listy
            }
            else {
                a = wynikowe.back(); // Używamy ostatniej sprawdzonej wartości
            }

            // Generujemy ciąg kongruencyjny
            vector<int> ciag = f_generuj_ciag(a, c, m, ziarno, n, xmin);

            // Wyświetlamy wygenerowany ciąg
            cout << "Wygenerowany ciag:" << endl;
            f_wyswietl_wektor(ciag);

            string nazwaPliku = "wynik";
            ofstream zapis;
            f_zapisDoPliku(zapis, nazwaPliku);
            f_wektorDoPliku(zapis, nazwaPliku, ciag);
            zapis.close();

        }
        else if (metoda == 2) { // Metoda addytywna kongruencyjna
            vector<pair<int, int>> pary = {
                {1, 2}, {1, 15}, {5, 23}, {7, 31}, {5, 47}, {21, 52}, {18, 65}, {28, 73},
                {2, 93}, {1, 3}, {4, 15}, {9, 23}, {13, 31}, {14, 47}, {24, 55}, {32, 65},
                {31, 73}, {21, 94}, {1, 4}, {7, 15}, {3, 25}, {13, 33}, {20, 47}, {7, 57},
                {9, 68}, {9, 79}, {11, 95}, {2, 5}, {3, 17}, {7, 25}, {2, 35}, {21, 47},
                {22, 57}, {33, 68}, {19, 79}, {17, 95}, {1, 6}, {5, 17}, {3, 28}, {11, 36},
                {9, 49}, {19, 58}, {6, 71}, {4, 81}, {6, 97}, {1, 7}, {6, 17}, {9, 28},
                {4, 39}, {12, 49}, {1, 60}, {9, 71}, {16, 81}, {12, 97}, {3, 7}, {7, 18},
                {13, 28}, {8, 39}, {15, 49}, {11, 60}, {18, 71}, {35, 81}, {33, 97}, {4, 9},
                {3, 20}, {2, 29}, {14, 39}, {22, 49}, {1, 63}, {20, 71}, {13, 84}, {34, 97},
                {3, 10}, {2, 21}, {3, 31}, {3, 41}, {3, 52}, {5, 63}, {35, 71}, {13, 87},
                {11, 98}, {2, 11}, {1, 22}, {6, 31}, {20, 41}, {19, 52}, {31, 63}, {25, 73},
                {38, 89}, {27, 98}
            };

            // Pobieramy modulo
            int m;
            do {
                cout << "Podaj modul:" << endl;
                cin >> m;
                if (cin.fail() || m <= 0) {
                    throw MainException("Modul musi być większy od 0.");
                }
            } while (m <= 0);

            // Pobieramy wartości początkowe do algorytmu
            vector<int> Y;
            int dana;
            cout << "Podaj wartosci poczatkowe:" << endl;
            for (int i = 0; i < n; i++) {
                cin >> dana;
                if (cin.fail()) {
                    throw MainException("Niepoprawna wartość początkowa.");
                }
                Y.push_back(dana); // Dodajemy podaną wartość do wektora
            }

            // Odwracamy wektor, aby algorytm działał poprawnie
            reverse(Y.begin(), Y.end());

            // Znajdujemy najlepszą parę indeksów dla algorytmu addytywnego kongruencyjnego
            pair<int, int> najlepszaPara = f_znajdzNajPare(pary, n);
            int j = najlepszaPara.first;
            int k = najlepszaPara.second;

            // Wykonujemy algorytm
            f_genAddKon(Y, m, n, j, k);

            // Wyświetlamy wygenerowany ciąg
            cout << "Wygenerowany ciag:" << endl;
            f_wyswietl_wektor(Y);

            string nazwaPliku = "wynik";
            ofstream zapis;
            f_zapisDoPliku(zapis, nazwaPliku);
            f_wektorDoPliku(zapis, nazwaPliku, Y);
            zapis.close();

        }
        else {
            throw MainException("Niepoprawny wybór metody.");
        }

    }
    catch (const MainException& e) {
        cerr << "Error: " << e.what() << endl;
    }
    catch (const exception& e) {
        cerr << "Nieoczekiwany error: " << e.what() << endl;
    }

    return 0;
}
