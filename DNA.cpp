#pragma once
#include "DNA.h"

#include <iostream>
#include <string>
#include "DNA.h"
#include "geneticcalculator.h"


DNA::DNA()
{
    DNAname = "No Name Assigned";
    DNAsequence = "No Sequence Assigned";

}

DNA::DNA(std::string name = "", std::string sequence = "")
{

    DNAname = name;
    DNAsequence = sequence;

}

DNA::~DNA()
{

}

void DNA::setDNAsequence(std::string inputDNAsequence)
{
    //std::cout << "set DNA sequence: input:" << inputDNAsequence << std::endl;
    DNAsequence = inputDNAsequence;
}

void DNA::CreateGenes()
{
    //std::cout << "Create Genes: DNA Sequence:  " << DNAsequence << std::endl;

    colorRedGene.geneName = "Color Red";
    colorRedGene.geneSequence = DNAsequence.substr(0, 4);

    colorGreenGene.geneName = "Color Green";
    colorGreenGene.geneSequence = DNAsequence.substr(4, 4);

    colorBlueGene.geneName = "Color Blue";
    colorBlueGene.geneSequence = DNAsequence.substr(8, 4);

    foodTypeGene.geneName = "Food Type";
    foodTypeGene.geneSequence = DNAsequence.substr(12, 4);

    typeOfCritterGene.geneName = "Type Of Critter";
    typeOfCritterGene.geneSequence = DNAsequence.substr(16, 4);

    personalityGene.geneName = "Personality";
    personalityGene.geneSequence = DNAsequence.substr(20, 4);

    intelligenceGene.geneName = "Intelligence";
    intelligenceGene.geneSequence = DNAsequence.substr(24, 4);

    canSeeGene.geneName = "Can See";
    canSeeGene.geneSequence = DNAsequence.substr(28, 4);

    visionGene.geneName = "Vision";
    visionGene.geneSequence = DNAsequence.substr(32, 4);

    canSmellGene.geneName = "Can Smell";
    canSmellGene.geneSequence = DNAsequence.substr(36, 4);

    smellGene.geneName = "Smell";
    smellGene.geneSequence = DNAsequence.substr(40, 4);

    canHearGene.geneName = "Can Hear";
    canHearGene.geneSequence = DNAsequence.substr(44, 4);

    HPgene.geneName = "HP";
    HPgene.geneSequence = DNAsequence.substr(48, 4);

    armorGene.geneName = "Armor";
    armorGene.geneSequence = DNAsequence.substr(52, 4);

    attackGene.geneName = "Attack";
    attackGene.geneSequence = DNAsequence.substr(56, 4);

    canMoveGene.geneName = "Can Move";
    canMoveGene.geneSequence = DNAsequence.substr(60, 4);

    maxSpeedGene.geneName = "Type Of Critter";
    maxSpeedGene.geneSequence = DNAsequence.substr(64, 4);




    //widthGene.geneName = "Width";
    //widthGene.geneSequence = DNAsequence.substr(12, 4);

    //heightGene.geneName = "Height";
    //heightGene.geneSequence = DNAsequence.substr(16, 4);


}

std::string DNA::GeneToNumber(std::string inputGene)
{
    // A = 0;
    // G = 1;
    // T = 2;
    // C = 3;

    std::string outputString("");
    char base(' ');
    std::string output = "";



    for (int i = 0; i < inputGene.size(); i++) {

        base = inputGene[i];

        switch (base)
        {
        case 'A':
            outputString += '0';
            break;
        case 'G':
            outputString += '1';
            break;
        case 'T':
            outputString += '2';
            break;
        case 'C':
            outputString += '3';
            break;



        }



    }



    int outputNumber(stoi(outputString));

    //GeneticCalculator newCalc("20331200231131", "10330211303201");


    //newCalc.ConvertToBase10(newCalc.ConvertBasesToNumbers("GAGTC"));


    return outputString;
}






