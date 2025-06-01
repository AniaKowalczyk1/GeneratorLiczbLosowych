#ifndef LIBFUNCTIONS_H
#define LIBFUNCTIONS_H
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


/*
 * Funkcja sprawdzaj¹ca, czy podana liczba znajduje siê w okreœlonym zakresie.
 * @param podana - sprawdzana liczba
 * @param poczatek - pocz¹tek zakresu
 * @param koniec - koniec zakresu
 * @return - true, jeœli liczba jest w zakresie, false w przeciwnym wypadku
 */
bool f_czyWzakresie(int podana, int poczatek, int koniec);

/*
 * Funkcja obliczaj¹ca najwiêkszy wspólny dzielnik dwóch liczb przy u¿yciu algorytmu Euklidesa.
 * @param a - pierwsza liczba
 * @param b - druga liczba
 * @return - NWD dwóch liczb
 */
int f_NWD(int a, int b);

/*
 * Funkcja znajduj¹ca najwiêksz¹ liczbê wzglêdnie pierwsz¹ do podanej.
 * @param b - liczba bazowa
 * @return - najwiêksza liczba wzglêdnie pierwsza do b
 */
int f_wzgledniePierwsze(int b);
/*
 * Funkcja wyœwietlaj¹ca zawartoœæ wektora wektorów.
 * @param macierz - wektor wektorów do wyœwietlenia
 */
void wyswietl_macierz(vector<vector<int>>& macierz);

/*
 * Funkcja generuj¹ca tablicê potêg dla liczb od 2 do m.
 * @param m - wartoœæ modu³u
 * @return - wektor wektorów, gdzie ka¿da para oznacza liczbê i jej potêgê
 */
vector<vector<int>> f_tablicaPoteg(int m);

/*
 * Funkcja znajduje liczby z najwiêksz¹ potêg¹ z tablicy potêg.
 * @param mnoznik - tablica potêg
 * @return - wektor liczb z najwiêksz¹ potêg¹
 */
vector<int> f_znajdz_max_potege(vector<vector<int>>& mnoznik);

/*
 * Funkcja zwracaj¹ca dzielniki pierwsze liczby m.
 * @param m - liczba do analizy
 * @return - wektor dzielników pierwszych
 */
vector<int> f_dzielniki_pierwsze(int m);

/*
 * Funkcja sprawdzaj¹ca, czy liczba b jest wielokrotnoœci¹ dzielników pierwszych m.
 * @param b - sprawdzana liczba
 * @param m - liczba, której dzielniki pierwsze analizujemy
 * @return - true, jeœli b jest wielokrotnoœci¹ dzielników pierwszych m
 */
bool f_sprawdz_b_wielokrotnosc(int b, int m);


/*
* Funkcja sprawdzaj¹ca, czy liczba "b" jest wielokrotnoœci¹ 4
* @param b - sprawdzana liczba
* @ return - true je¿eli liczba dzieli siê przez 4
*/
bool f_sprawdzWielokrotnoscCzworki(int b);

/*
 * Funkcja generuj¹ca ci¹g liczb na podstawie wzoru kongruencyjnego.
 * @param a - mno¿nik
 * @param c - przesuniêcie
 * @param m - modulo
 * @param ziarno - pocz¹tkowa wartoœæ
 * @param Y - liczba liczb do wygenerowania
 * @param dolnyZakres - minimalna wartoœæ w ci¹gu
 * @return - wektor wygenerowanego ci¹gu
 */
vector<int> f_generuj_ciag(int a, int c, int m, int ziarno, int Y, int dolnyZakres);

/*
 * Funkcja wyœwietlaj¹ca zawartoœæ wektora.
 * @param wektor - wektor do wyœwietlenia
 */
void f_wyswietl_wektor(const vector<int>& wektor);

/*
 * Funkcja implementuj¹ca algorytm addytywny kongruencyjny.
 * @param Y - wektor do przetwarzania
 * @param m - modulo
 * @param n - liczba kroków algorytmu
 * @param j - indeks pocz¹tkowy
 * @param k - indeks koñcowy
 */
void f_genAddKon(vector<int>& Y, int m, int n, int& j, int& k);

/*
 * Funkcja znajduj¹ca najlepsz¹ parê z wektora par.
 * @param pary - wektor par (indeksów)
 * @param n - liczba porównawcza
 * @return - najlepsza para (indeksów)
 */
pair<int, int> f_znajdzNajPare(const vector<pair<int, int>>& pary, int n);




#endif


