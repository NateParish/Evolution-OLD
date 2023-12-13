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

    colorRedGene.geneName = "ColorRed";
    colorRedGene.geneSequence = DNAsequence.substr(0, 4);

    colorGreenGene.geneName = "ColorGreen";
    colorGreenGene.geneSequence = DNAsequence.substr(4, 4);

    colorBlueGene.geneName = "ColorBlue";
    colorBlueGene.geneSequence = DNAsequence.substr(8, 4);

    widthGene.geneName = "Width";
    widthGene.geneSequence = DNAsequence.substr(12, 4);

    heightGene.geneName = "Height";
    heightGene.geneSequence = DNAsequence.substr(16, 4);


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






