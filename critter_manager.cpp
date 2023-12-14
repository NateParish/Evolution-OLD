#include "critter_manager.h"


CritterManager::CritterManager()
{
	listOfAllCritters = new std::vector<Critter*>();
	livingCritters = new std::vector<Critter*>();
	listOfNewCritters = new std::vector<Critter*>();
	listOfFirstNames = new std::vector<std::string>();
	listOfLastNames = new std::vector<std::string>();
	 

	//listOfFirstNames;
	//listOfLastNames;


}

CritterManager::~CritterManager()
{
	

	for (Critter* critter : *listOfAllCritters) {
		delete critter;
	}

	delete listOfFirstNames;
	delete listOfLastNames;
	delete listOfAllCritters;
	delete listOfNewCritters;
	delete livingCritters;
}

void CritterManager::SpawnFirstCritter()
{

	Critter* critter = new Critter(350,350, "CCCCCCCCCCCCAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAC");
	critter->generateBody();
	GenerateName(critter);
	listOfAllCritters->push_back(critter);
	livingCritters->push_back(critter);
}

void CritterManager::PopulateNameGenerator()
{
	std::string firstName;
	std::string lastName;

	std::ifstream firstNameCSVFile("First Name List.csv");
	if (!firstNameCSVFile.is_open()) {
		std::cerr << "Error opening file." << std::endl;
	}
	while (std::getline(firstNameCSVFile, firstName)) {
		// Assuming the CSV uses a comma as a delimiter
		listOfFirstNames->push_back(firstName);
	}

	firstNameCSVFile.close();

	std::ifstream lastNameCSVFile("Last Name List.csv");
	if (!lastNameCSVFile.is_open()) {
		std::cerr << "Error opening file." << std::endl;
	}
	while (std::getline(lastNameCSVFile, lastName)) {
		// Assuming the CSV uses a comma as a delimiter
		listOfLastNames->push_back(lastName);
	}

	lastNameCSVFile.close();

}

void CritterManager::GenerateName(Critter* targetCritter)
{

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> distrib(0, listOfFirstNames->size());
	std::uniform_int_distribution<int> distrib2(0, listOfLastNames->size());

	int randomNumber = distrib(gen);
	int randomNumber2 = distrib2(gen);


	//std::srand(static_cast<unsigned int>(std::time(nullptr)));
	//size_t randomIndex1 = std::rand() % listOfFirstNames->size();
	//size_t randomIndex2 = std::rand() % listOfLastNames->size();
	std::string firstName;
	std::string lastName;



	if (!listOfFirstNames->empty()) 
	{
		firstName = (*listOfFirstNames)[randomNumber];
		//firstName = listOfFirstNames[randomIndex1];		
	}
	else 
	{
		std::cerr << "No First names found in the file." << std::endl;
	}

	if (!listOfLastNames->empty()) 
	{
		lastName = (*listOfLastNames)[randomNumber2];
		//lastName = listOfLastNames[randomIndex2];
	}
	else 
	{
		std::cerr << "No Last names found in the file." << std::endl;
	}


	targetCritter->firstName = firstName;
	targetCritter->lastName = lastName;

}

void CritterManager::SpawnNewCritter(Critter* parent)
{
	
	//std::string newDNA = parent->DNAsequence;

	parent->CreateNewMutatedDNA();
	Critter* critter = new Critter(parent->x + parent->width*2, parent->y, parent->CreateNewMutatedDNA());
	//critter->DNArandomMutate();
	//std::cout << critter->DNAsequence << std::endl;
	critter->generateBody();
	critter->RandomReproductionRate();
	GenerateName(critter);
	listOfAllCritters->push_back(critter);
	livingCritters->push_back(critter);
	listOfNewCritters->push_back(critter);

}
