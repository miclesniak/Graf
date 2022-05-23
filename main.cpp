#include "graf.h"
#include <chrono>

void menu() {
    cout << endl << "Znajdowanie najkrotszej drogi w Grafie za pomoca algorytmu Dijkstry" << endl;
    cout << "1 - wygeneruj graf" << endl;
	cout << "2 - wczytaj graf" << endl;
	cout << "3 - wyswietl graf" << endl;
	cout << "4 - algorytm Dijkstra na macierzy sasiedztwa" << endl;
	cout << "5 - algorytm Dijkstra na liscie sasiedztwa" << endl;
	cout << "0 - koniec dzialania programu" << endl;
	cout << "Twoj wybor: ";
}

int main() {

    int wybor;
	bool flaga = true;
	Graf* graf;
	Dijkstra* arr;

	using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;

	while (flaga) {
		menu();
		cin >> wybor;
		switch (wybor) {
			case 1: {
				generujGraf();
				break;
			}
			case 2: {
				wczytajGraf(graf);
				break;
			}
			case 3: {
				graf->wyswietlMacierz();
				graf->wyswietlListe();
				break;
			}
			case 4: {
				auto t1 = high_resolution_clock::now();
				for (int i = 0; i < 100; i++) {
					arr = graf->dijkstraMacierz();
				}
				auto t2 = high_resolution_clock::now();
				duration<double, std::milli> ms_double = t2 - t1;
				cout << endl << "Czas dzialania algorytmu: " << ms_double.count() << " ms." << endl;
				graf->zapisz(arr);
				break;
			}
			case 5: {
				auto t1 = high_resolution_clock::now();
				for (int i = 0; i < 100; i++) {
					arr = graf->dijkstraLista();
				}
				auto t2 = high_resolution_clock::now();
				duration<double, std::milli> ms_double = t2 - t1;
				cout << endl << "Czas dzialania algorytmu: " << ms_double.count() << " ms." << endl;
				graf->zapisz(arr);
				break;
			}
			case 0: {
				flaga = false;
				break;
			}
			default: {
				cout << "Bledny wybor. Sprobuj jeszcze raz" << endl;
				break;
			}
		}
	}
	return 0;
}