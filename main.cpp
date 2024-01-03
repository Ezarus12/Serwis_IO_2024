#include <iostream>
#include <string>
#include <fstream>
#include "Biblioteki.h"


int main() {
	Entity Baza("baza_klientow.txt", "baza_raportow.txt", "baza_zgloszen.txt");
	Control C(Baza);
	Boundary B(C);

	B.Start();
	return 0;
}