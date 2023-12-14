#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <random>
#include <string>
#include <cstdlib>
#include "critter.h"

class CritterManager
{

public:

	std::vector<Critter*>* listOfAllCritters;
	std::vector<Critter*>* livingCritters;
	std::vector<Critter*>* listOfNewCritters;

	std::vector<std::string>* listOfFirstNames;
	std::vector<std::string>* listOfLastNames;
	//std::vector<std::string>* listOfFirstNames;
	//std::vector<std::string>* listOfLastNames;


	CritterManager();
	~CritterManager();
	void SpawnFirstCritter();
	void PopulateNameGenerator();
	void GenerateName(Critter* targetCritter);
	void SpawnNewCritter(Critter* parent);
	



};

