#pragma once
#include <string>
#include <fstream>


class Usluga {
public:
	float cena;
	int vat;
	std::string nazwa;

	Usluga() = default;
	Usluga(float c, int v, std::string n) : cena(c), vat(v), nazwa(n) {}

	float SumaBrutto() {
		return cena * (1 + (vat * 0.01));
	}
};

class Faktura : public Usluga {
public:
	std::string wystawiajacy;
	std::string nabywca;

	Faktura(float c, int v, std::string n, std::string w, std::string nb) : Usluga(c, v, n), wystawiajacy(w), nabywca(nb) {}
};

class Zgloszenie {
private:
	int id;
	std::string typ; //naprawa / przeglad
public:
	Zgloszenie(int id_, std::string typ_) : id(id_), typ(typ_) {}

	int get_id() { return id; }
	std::string get_typ() { return typ; }

	friend std::ofstream& operator<<(std::ofstream& ofs, const Zgloszenie& zgloszenie) {
		ofs << "Id: " << zgloszenie.id << " Typ: " << zgloszenie.typ;
		return ofs;
	}
};

class Raport {
private:
	int nr;
	Zgloszenie zgloszenie;
	std::string tresc_raportu;
public:
	Raport() = default;
	Raport(int nr_, Zgloszenie zgloszenie_, std::string tresc_raportu_) : nr(nr_), zgloszenie(zgloszenie_), tresc_raportu(tresc_raportu_) {}

	int get_nr() { return nr; }
	Zgloszenie get_zgloszenie() { return zgloszenie; }
	std::string get_tresc() { return tresc_raportu; }

};