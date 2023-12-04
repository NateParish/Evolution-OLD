#include "gene.h"

Gene::Gene()
{
    geneName = "";
    geneSequence = "";

}

Gene::Gene(std::string inputGeneName, std::string inputSequence)
{
    geneName = inputGeneName;
    geneSequence = inputSequence;

}

Gene::~Gene()
{

}

void Gene::Interpret()
{
    GeneticCalculator geneCalc;

    if (geneName == "ColorRed")
    {
        std::cout << geneName << " Value is:  " << stoi(geneCalc.ConvertToBase10(geneCalc.ConvertBasesToNumbers(geneSequence))) << std::endl;
    }
    else if (geneName == "ColorGreen")
    {
        std::cout << geneName << " Value is:  " << stoi(geneCalc.ConvertToBase10(geneCalc.ConvertBasesToNumbers(geneSequence))) << std::endl;
    }
    else if (geneName == "ColorBlue")
    {
        std::cout << geneName << " Value is:  " << stoi(geneCalc.ConvertToBase10(geneCalc.ConvertBasesToNumbers(geneSequence))) << std::endl;
    }
    else if (geneName == "Width")
    {
        std::cout << geneName << " Value is:  " << stoi(geneCalc.ConvertToBase10(geneCalc.ConvertBasesToNumbers(geneSequence))) << std::endl;
    }
    else if (geneName == "Height")
    {
        std::cout << geneName << " Value is:  " << stoi(geneCalc.ConvertToBase10(geneCalc.ConvertBasesToNumbers(geneSequence))) << std::endl;
    }


}
