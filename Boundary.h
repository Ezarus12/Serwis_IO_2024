#pragma once
#include <string>
#include <iostream>
#include "Control.h"

class Boundary {
private:
	Control C;
public:
	Boundary() = default;
	Boundary(Control c) : C(c) {};
	void Start() {
		int opcja = 0;
		std::cout << "Wybierz opcje:\n" << "1.Dodaj nowe zgloszenie.\n" << "2.Stworz Raport.\n" << "3.Wystaw Fakture" << std::endl;
		std::cout << "Podaj numer opcji: ";
		while (true) {
			std::cin >> opcja;
			if (std::cin.fail() || (opcja < 1 || opcja > 3)) {
				std::cout << "Nieprawid³owa opcja. Wybierz ponownie." << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			else {
				break;
			}
		}
		switch (opcja)
		{
		case 1:
			NoweZgloszenie();
			break;
		case 2:
			StworzRaport();
			break;
		case 3:
			WystawFakture();
			break;
		default:
			std::cout << "Podana operacja nie moze zostac wykonana." << std::endl;
			break;
		}

	}
	void NoweZgloszenie()
	{
		int id;
		std::string nazwisko;
		std::string marka;
		std::string model;

		std::cout << "Podaj Dane Klienta:\nNazwisko:";
		std::getline(std::cin >> std::ws, nazwisko);
		std::cout << "\nId klienta:";
		std::cin >> id;
		std::cout << "\nMarka pojazdu:";
		std::cin >> marka;
		std::cout << "\nModel pojazdu:";
		std::cin >> model;
		Samochod samochod(marka, model);
		Klient klient(id, nazwisko, samochod);

		C.PrzekazDane(klient);
		std::cout << "\nKlient dodany." << std::endl;

		int nr_zgloszenia;
		std::string typ;
		std::cout << "Podaj nr zgloszenia:" << std::endl;
		std::cin >> nr_zgloszenia;
		std::cout << "Podaj typ zgloszenia (Naprawa/Przeglad):" << std::endl;
		while (true) {
			std::cin >> typ;
			if (typ == "Naprawa" || typ == "Przeglad")
				break;
			std::cout << "Nieprawidlowy typ zgloszenia" << std::endl;
		}
		Zgloszenie zgloszenie(nr_zgloszenia, typ);
		C.PrzekazDane(zgloszenie);
		std::cout << "Zgloszenie dodane.\n" << std::endl;

		Start();
	}

	void StworzRaport() {
		std::string nr;
		while (true) {
			std::cout << "\nPodaj numer zgloszenia:";
			std::cin >> nr;
			if (C.ZnajdzZgloszenie(nr))
				break;
		}

		int nr_raportu;
		std::string typ;
		std::string tresc_raportu;
		std::cout << "\nPodaj numer raportu:" << std::endl;
		std::cin >> nr_raportu;
		std::cout << "Podaj typ zgloszenia (Naprawa/Przeglad):" << std::endl;
		while (true) {
			std::cin >> typ;
			if (typ == "Naprawa" || typ == "Przeglad")
				break;
			std::cout << "Nieprawidlowy typ zgloszenia" << std::endl;
		}
		std::cout << "\nWpisz tresc raportu: ";
		std::getline(std::cin >> std::ws, tresc_raportu);
		Zgloszenie zgloszenie(std::stoi(nr), typ);
		Raport raport(nr_raportu, zgloszenie, tresc_raportu);
		C.PrzekazDane(raport);
		std::cout << "\nRaport dodany\n\n";
		Start();
	}

	void WystawFakture() {
		std::string nazwa_pliku;
		std::string wystawiajacy;
		std::string nabywca;
		std::string nazwa;
		int vat;
		float cena;
		std::cout << "Podaj wystawiajacego: ";
		std::cin >> wystawiajacy;
		std::cout << "\nPodaj nabywce: ";
		std::cin >> nabywca;
		std::cout << "\nPodaj nazwe uslugi (Naprawa/Przeglad): ";
		while (true) {
			std::cin >> nazwa;
			if (nazwa == "Naprawa" || nazwa == "Przeglad")
				break;
			std::cout << "Nieprawidlowa nazwa uslugi" << std::endl;
		}
		std::cout << "\nPodaj cene: ";
		std::cin >> cena;
		std::cout << "\nPodaj stawke Vat: ";
		std::cin >> vat;
		std::cout << "\nPodaj nazwe pliku do zapisu (.txt): ";
		std::cin >> nazwa_pliku;
		Faktura faktura(cena, vat, nazwa, wystawiajacy, nabywca);
		C.PrzekazDane(faktura, nazwa_pliku);
		std::cout << "\nFaktura zapisana w pliku: " << nazwa_pliku;
		Start();
	}
};