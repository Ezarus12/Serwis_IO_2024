#pragma once
#include <string>
#include <iostream>
#include "Entity.h"

class Control {
private:
	Entity baza;
public:
	Control() = default;
	Control(Entity& b) : baza(b) {}

	void PrzekazDane(Klient& klient)
	{
		if (!baza.SprawdzDane(klient)) {
			baza.Dodaj(klient);
		}
	}

	void PrzekazDane(Raport& raport) {
		baza.Dodaj(raport);
	}
	void PrzekazDane(Faktura& faktura, std::string nazwa_pliku) {
		baza.WystawFakture(faktura, nazwa_pliku);
	}

	void PrzekazDane(Zgloszenie& zgloszenie) {
		baza.Dodaj(zgloszenie);
	}

	bool ZnajdzZgloszenie(std::string nr) {
		if (baza.ZwrocZgloszenie(nr))
			return true;
		else
			return false;
	}

	void ZnajdzRaport(std::string nr) {
		if (baza.ZnajdzRaport(nr))
		{
			baza.ZwrocRaport(nr);
		}
	}
};