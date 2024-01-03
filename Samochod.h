#pragma once
#include <string>
#include <iostream>
#include <fstream>

class Samochod {
private:
	std::string marka;
	std::string model;
public:
	Samochod() = default;
	Samochod(std::string marka_, std::string model_) : marka(marka_), model(model_) {}
	Samochod(Samochod& s) {
		marka = s.marka;
		model = s.model;
	}

	friend std::ofstream& operator<<(std::ofstream& ofs, const Samochod& samochod) {
		ofs << std::endl << "Marka: " << samochod.marka << " Model: " << samochod.model;
		return ofs;
	}
};