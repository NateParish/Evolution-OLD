#pragma once
#include <iostream>


class GeneticCalculator
{

public:

	GeneticCalculator();
	~GeneticCalculator();


	std::string geneSequence;
	std::string number1;
	std::string number2;

	std::string ConvertBasesToNumbers(std::string geneticCode);
	std::string AddNumbers();
	std::string ConvertToBase10(std::string base4number);

};

