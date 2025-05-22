#include "PatientFileLoader.h"

#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

#include "Patient.h"
#include "Vitals.h"

using namespace std;


std::vector<Patient*> PatientFileLoader::loadPatientFile(const std::string& file)
{
	vector<Patient*> patients{};

    std::ifstream inFile(file);
    if (inFile.is_open()) {
        // TODO: load your file here
        std::string line;
        while (std::getline(inFile, line)) {
            std::string firstName;
            std::string lastName;
            std::tm birthday;
            std::cout << "Read line: " << line << std::endl;
            // use std::getline to split on the |
            std::stringstream lineStream(line);
            std::string token;
            int patientEditSelector = 0;
            while (std::getline(lineStream, token, '|')) {
                std::cout << "Read info" << token << std::endl;
                //for each part of line add patient info
                switch (patientEditSelector)
                {
                case 0:

                default:
                        break;
                }
                patientEditSelector++;
            }
        }
    }

    return patients;
}
