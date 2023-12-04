#pragma once
#include "geneticcalculator.h"
#include <iostream>
#include <string>


GeneticCalculator::GeneticCalculator()
{
    geneSequence = "GENE SEQUENCE";

    // Additional initialization code can go here if needed

}

GeneticCalculator::~GeneticCalculator()
{

}

std::string GeneticCalculator::ConvertBasesToNumbers(std::string geneticCode)
{
    // A = 0;
    // G = 1;
    // T = 2;
    // C = 3;

    std::string outputString("");
    char base(' ');
    std::string output = "";



    for (int i = 0; i < geneticCode.size(); i++) {

        base = geneticCode[i];

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

    return(outputString);
}

std::string GeneticCalculator::AddNumbers()
{

    std::string digit1string("");
    std::string digit2string("");
    std::string output("");
    int digit1(0);
    int digit2(0);
    int addedResult(0);
    int outputDigit(0);
    int carry(0);
    int carryLast(0);
    int k(number1.size() - 1);
    std::string character("0");

    for (int i = 0; i < number1.size(); i++)
    {


        digit1string = number1[k];
        digit2string = number2[k];

        digit1 = stoi(digit1string);
        digit2 = stoi(digit2string);

        addedResult = carryLast + digit1 + digit2;
        outputDigit = (addedResult) % 4;

        if (addedResult > 3)
        {
            carry = 1;
        }
        else
        {
            carry = 0;
        }

        output = std::to_string(outputDigit) + output;

        digit1 = stoi(digit1string);

        carryLast = carry;
        carry = 0;

        k--;

    }


    return output;
}

std::string GeneticCalculator::ConvertToBase10(std::string base4number)
{

    double base10number = 0;
    int power = 1;

    for (int i = base4number.length() - 1; i >= 0; --i) {
        double digit = base4number[i] - '0'; // Convert character to integer


        base10number += digit * power;

        // Move to the next power of 4
        power *= 4;
    }


    return std::to_string(base10number);

}