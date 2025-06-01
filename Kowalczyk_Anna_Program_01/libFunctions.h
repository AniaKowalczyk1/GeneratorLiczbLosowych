#ifndef LIBFUNCTIONS_H
#define LIBFUNCTIONS_H
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


/*
 * Funkcja sprawdzaj�ca, czy podana liczba znajduje si� w okre�lonym zakresie.
 * @param podana - sprawdzana liczba
 * @param poczatek - pocz�tek zakresu
 * @param koniec - koniec zakresu
 * @return - true, je�li liczba jest w zakresie, false w przeciwnym wypadku
 */
bool f_czyWzakresie(int podana, int poczatek, int koniec);

/*
 * Funkcja obliczaj�ca najwi�kszy wsp�lny dzielnik dw�ch liczb przy u�yciu algorytmu Euklidesa.
 * @param a - pierwsza liczba
 * @param b - druga liczba
 * @return - NWD dw�ch liczb
 */
int f_NWD(int a, int b);

/*
 * Funkcja znajduj�ca najwi�ksz� liczb� wzgl�dnie pierwsz� do podanej.
 * @param b - liczba bazowa
 * @return - najwi�ksza liczba wzgl�dnie pierwsza do b
 */
int f_wzgledniePierwsze(int b);
/*
 * Funkcja wy�wietlaj�ca zawarto�� wektora wektor�w.
 * @param macierz - wektor wektor�w do wy�wietlenia
 */
void wyswietl_macierz(vector<vector<int>>& macierz);

/*
 * Funkcja generuj�ca tablic� pot�g dla liczb od 2 do m.
 * @param m - warto�� modu�u
 * @return - wektor wektor�w, gdzie ka�da para oznacza liczb� i jej pot�g�
 */
vector<vector<int>> f_tablicaPoteg(int m);

/*
 * Funkcja znajduje liczby z najwi�ksz� pot�g� z tablicy pot�g.
 * @param mnoznik - tablica pot�g
 * @return - wektor liczb z najwi�ksz� pot�g�
 */
vector<int> f_znajdz_max_potege(vector<vector<int>>& mnoznik);

/*
 * Funkcja zwracaj�ca dzielniki pierwsze liczby m.
 * @param m - liczba do analizy
 * @return - wektor dzielnik�w pierwszych
 */
vector<int> f_dzielniki_pierwsze(int m);

/*
 * Funkcja sprawdzaj�ca, czy liczba b jest wielokrotno�ci� dzielnik�w pierwszych m.
 * @param b - sprawdzana liczba
 * @param m - liczba, kt�rej dzielniki pierwsze analizujemy
 * @return - true, je�li b jest wielokrotno�ci� dzielnik�w pierwszych m
 */
bool f_sprawdz_b_wielokrotnosc(int b, int m);


/*
* Funkcja sprawdzaj�ca, czy liczba "b" jest wielokrotno�ci� 4
* @param b - sprawdzana liczba
* @ return - true je�eli liczba dzieli si� przez 4
*/
bool f_sprawdzWielokrotnoscCzworki(int b);

/*
 * Funkcja generuj�ca ci�g liczb na podstawie wzoru kongruencyjnego.
 * @param a - mno�nik
 * @param c - przesuni�cie
 * @param m - modulo
 * @param ziarno - pocz�tkowa warto��
 * @param Y - liczba liczb do wygenerowania
 * @param dolnyZakres - minimalna warto�� w ci�gu
 * @return - wektor wygenerowanego ci�gu
 */
vector<int> f_generuj_ciag(int a, int c, int m, int ziarno, int Y, int dolnyZakres);

/*
 * Funkcja wy�wietlaj�ca zawarto�� wektora.
 * @param wektor - wektor do wy�wietlenia
 */
void f_wyswietl_wektor(const vector<int>& wektor);

/*
 * Funkcja implementuj�ca algorytm addytywny kongruencyjny.
 * @param Y - wektor do przetwarzania
 * @param m - modulo
 * @param n - liczba krok�w algorytmu
 * @param j - indeks pocz�tkowy
 * @param k - indeks ko�cowy
 */
void f_genAddKon(vector<int>& Y, int m, int n, int& j, int& k);

/*
 * Funkcja znajduj�ca najlepsz� par� z wektora par.
 * @param pary - wektor par (indeks�w)
 * @param n - liczba por�wnawcza
 * @return - najlepsza para (indeks�w)
 */
pair<int, int> f_znajdzNajPare(const vector<pair<int, int>>& pary, int n);




#endif


