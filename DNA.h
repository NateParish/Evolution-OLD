#pragma once
#include <string>
#include "geneticcalculator.h"
#include "gene.h"


class DNA
{


public:

	std::string DNAname;
	std::string DNAsequence;
	void CreateGenes();
	std::string GeneToNumber(std::string inputGene);
	Gene colorRedGene;
	Gene colorGreenGene;
	Gene colorBlueGene;
	Gene widthGene;
	Gene heightGene;

	DNA();
	DNA(std::string name, std::string sequence);
	~DNA();
	void setDNAsequence(std::string inputDNAsequence);
};



