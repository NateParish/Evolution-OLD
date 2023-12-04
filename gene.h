#pragma once
#include <string>
#include <iostream>
#include "geneticcalculator.h"

class Gene
{

public:

	Gene();
	Gene(std::string inputGeneName, std::string inputSequence);
	~Gene();

	void Interpret();

	std::string geneName;
	std::string geneSequence;

};



