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
            int loc;
            std::cout << "Read line: " << line << std::endl;
            // use std::getline to split on the |
            std::stringstream lineStream(line);
            std::string token;
            int patientEditSelector = 0;
            while (std::getline(lineStream, token, '|')) {
                //for each part of line add patient info
                switch (patientEditSelector)
                {
                case 1:
                    //get the patient first and last name
                    //get the location of the , delimiter
                    loc = token.find(',');
                    firstName = token.substr(0, loc);
                    lastName = token.substr(loc+1, token.size());
                default:
                        break;
                }
                patientEditSelector++;
            }
        }
    }

    return patients;
}
