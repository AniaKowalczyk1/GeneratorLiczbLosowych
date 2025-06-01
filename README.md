Program generuje ciąg liczb pseudolosowych, korzystając z jednej z dwóch metod wyboru użytkownika:

Metoda kongruencyjna (metoda 1):

Użytkownik podaje zakres wartości (xmin, xmax), ziarno startowe oraz liczbę liczb do wygenerowania.

Program dobiera parametry algorytmu (współczynniki a, c, modulo m) zgodnie z określonymi warunkami matematycznymi (względna pierwszość, wielokrotności itp.).

Następnie generuje ciąg liczb pseudolosowych zgodnie z klasycznym wzorem kongruencyjnym:
X_{n+1} = (a * X_n + c) mod m.

Wygenerowany ciąg jest wyświetlany i zapisywany do pliku.

Metoda addytywna kongruencyjna (metoda 2):

Użytkownik podaje moduł m, liczbę generowanych liczb oraz wartości początkowe (wektor startowy).

Program znajduje optymalną parę indeksów (j, k) z przygotowanej listy par, odpowiednią do długości ciągu.

Następnie generuje ciąg liczb pseudolosowych według algorytmu addytywnego kongruencyjnego, który polega na sumowaniu dwóch wybranych elementów z poprzednich wartości ciągu i redukcji modulo m.

Wynikowy ciąg jest wyświetlany i zapisywany do pliku.

Dodatkowo program posiada obsługę wyjątków i walidację danych wejściowych, zapewniając poprawność podawanych wartości oraz stabilność działania.
