#pragma once
#include <string>
#include "Samochod.h"

class Klient {
private:
	int id;
	std::string nazwisko;
	Samochod pojazd;
public:
	Klient() = default;
	Klient(int id_, std::string nazwisko_, Samochod& pojazd_) : id(id_), nazwisko(nazwisko_), pojazd(pojazd_) {};

	int get_id() { return id; }
	std::string get_nazwisko() { return nazwisko; }
	Samochod get_pojazd() { return pojazd; }
};