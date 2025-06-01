#ifndef LIBFILES_H
#define LIBFILES_H
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


/*
Funkcja otwieraj¹ca zapis do pliku
@param zapis - referencja do obiektu strumienia wyjœciowego pliku
@param nazwaPliku - referencja do nazwy pliku
*/
void f_zapisDoPliku(ofstream& zapis, string& nazwaPliku);

/*
Funkcja otwieraj¹ca zapis do pliku
@param odczyt - referencja do obiektu strumienia wejœciowego pliku
@param nazwaPliku - referencja do nazwy pliku
*/
void f_odczytZpliku(ifstream& odczyt, string& nazwaPliku);

/*
Funkcja zapisuj¹ca zawartoœæ wektora do pliku.
@param zapis - referencja do obiektu strumienia wyjœciowego pliku
@param nazwaPliku - referencja do nazwy pliku, do którego zostan¹ zapisane dane
@param pary - referencja do wektora wartoœci, które zostan¹ zapisane do pliku
*/
void f_wektorDoPliku(ofstream& zapis, string& nazwaPliku, vector<int>& pary);

#endif


