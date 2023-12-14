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
	Gene foodTypeGene;
	Gene typeOfCritterGene;
	Gene personalityGene;
	Gene intelligenceGene;
	Gene canSeeGene;
	Gene visionGene;
	Gene canSmellGene;
	Gene smellGene;
	Gene canHearGene;
	Gene HPgene;
	Gene armorGene;
	Gene attackGene;
	Gene canMoveGene;
	Gene maxSpeedGene;

	//Gene widthGene;
	//Gene heightGene;

	DNA();
	DNA(std::string name, std::string sequence);
	~DNA();
	void setDNAsequence(std::string inputDNAsequence);
};



