#pragma once
#include <iostream>
#include <string>
#include <fstream>

class Entity {
private:
	std::string baza_klientow;
	std::string baza_raportow;
	std::string baza_zgloszen;
public:
	Entity() {
		baza_klientow = '\0';
		baza_raportow = '\0';
		baza_zgloszen = '\0';
	}
	Entity(std::string bk, std::string br, std::string bz) : baza_klientow(bk), baza_raportow(br), baza_zgloszen(bz) {}

	Entity(Entity& e)
	{
		baza_klientow = e.baza_klientow;
		baza_raportow = e.baza_raportow;
		baza_zgloszen = e.baza_zgloszen;

	}

	void Dodaj(Klient& klient)
	{
		std::ofstream plik;
		plik.open(baza_klientow, std::ios_base::app);
		plik << "Klient: " << klient.get_id() << std::endl;
		plik << "Nazwisko: " << klient.get_nazwisko() << std::endl;
		plik << "Pojazd: ";
		plik << klient.get_pojazd() << std::endl << std::endl;
		plik.close();
	}

	void Dodaj(Raport& raport)
	{
		if (ZnajdzRaport(std::to_string(raport.get_nr()))) {
			return;
		}
		std::ofstream plik;
		plik.open(baza_raportow, std::ios_base::app);
		plik << "Raport " << raport.get_nr() << std::endl;
		plik << "Ze zg³osznia: ";
		plik << raport.get_zgloszenie() << std::endl;
		plik << "Tresc raportu:" << std::endl << raport.get_tresc() << std::endl << "Koniec Raportu.\n" << std::endl;
		plik.close();
	}

	void Dodaj(Zgloszenie& zgloszenie)
	{
		int k;
		std::ofstream plik;
		plik.open(baza_zgloszen, std::ios_base::app);
		plik << "Zgloszenie: ";
		plik << zgloszenie << std::endl;
		plik.close();
	}

	bool SprawdzDane(Klient& klient)
	{
		std::ifstream plik(baza_klientow);
		std::string id;

		while (plik >> id) {
			if (id == std::to_string(klient.get_id())) {
				return true;
			}
		}
		return false;
	}

	bool ZnajdzZgloszenie(std::string nr) {
		std::ifstream plik(baza_zgloszen);
		std::string id;

		while (plik >> id) {
			if (id == nr) {
				return true;
			}
		}
		std::cout << "Zgloszenie nie znaleziono";
		return false;
	}

	bool ZnajdzRaport(std::string nr) {
		std::ifstream plik(baza_raportow);
		std::string linia;

		while (std::getline(plik, linia)) {
			if (linia.find("Raport " + nr) != std::string::npos) {
				return true;
			}
		}
		return false;
	}

	void ZwrocRaport(std::string nr) {
		std::ifstream plik(baza_raportow);
		std::string linia;

		while (std::getline(plik, linia)) {
			if (linia.find("Raport " + nr) != std::string::npos) {
				std::cout << linia << std::endl;

				while (std::getline(plik, linia)) {
					std::cout << linia << std::endl;

					if (linia == "Koniec Raportu.") {
						break;
					}
				}

				return;
			}
		}

		std::cout << "Raportu nie znaleziono" << std::endl;
	}

	bool ZwrocZgloszenie(std::string nr) {
		std::ifstream plik(baza_zgloszen);
		std::string linia;

		while (std::getline(plik, linia)) {
			if (linia.find("Zgloszenie: Id: " + nr) != std::string::npos) {
				std::cout << linia << std::endl;
				return true;
			}
		}
		std::cout << "Zgloszenia nie znaleziono" << std::endl;
		return false;
	}

	void WystawFakture(Faktura& faktura, std::string nazwa_pliku) {
		std::ofstream plik;
		plik.open(nazwa_pliku);
		plik << "Wystawiajacy: ";
		plik << faktura.wystawiajacy << std::endl;
		plik << "Nabywca: ";
		plik << faktura.nabywca << std::endl;
		plik << "\nNazwa us³ugi: " << faktura.nazwa << std::endl;
		plik << "Cenna Netto: " << faktura.cena << " | Stawka Vat: " << faktura.vat << "%" << " | Cena Brutto: " << faktura.SumaBrutto();
		plik.close();
	}
};