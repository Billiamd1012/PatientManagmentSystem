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
	vector<std::unique_ptr<Patient>> patients{};

    std::ifstream inFile(file);
    if (inFile.is_open()) {
        // TODO: load your file here
        std::string line;
        while (std::getline(inFile, line)) {
            std::string firstName;
            std::string lastName;
            std::tm birthday;
            int loc = 0;
            std::istringstream birthdayStream;
            std::unique_ptr<Patient> currentPatient = nullptr;
            std::unique_ptr<Vitals> newVital = nullptr;
            std::string vital;

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
                    loc = token.find(',');
                    firstName = token.substr(0, loc);
                    lastName = token.substr(loc+1, token.size());
                    break;
                case 2:
                    //get the patient birthday and add a new patient
                    birthdayStream.str(token);
                    birthdayStream.clear();
                    if (!(birthdayStream >> std::get_time(&birthday, "%d-%m-%Y"))) {
                        std::cerr << "Error parsing birthday: " << token << std::endl;
                    }
                    currentPatient = std::make_unique<Patient>(firstName, lastName, birthday);
                    patients.push_back(currentPatient);
                    currentPatient = nullptr;
                    break;
                case 3:
                    //if there is a current diagnosis then add it
                    currentPatient->addDiagnosis(token);
                    break;
                case 4:
                {
                    std::stringstream tokenstream(token);
                    //if there are current vitals then for each vital reading add a new vital reading
                    //iterate over each vital
                    while (std::getline(tokenstream, vital, ';')) {
                        //iterate over each reading in vital
                        std::string reading;
                        std::stringstream vitalstream(vital);
                        int readingEditSelector = 0;
                        float bodyTemperature = 0.0f;
                        int bloodPressure = 0;
                        int heartRate = 0;
                        int respiratoryRate = 0;
                        while (std::getline(vitalstream, reading, ',')) {
                            switch (readingEditSelector)
                            {
                            case 0:
                                bodyTemperature = std::stof(reading);
                                break;
                            case 1:
                                bloodPressure = std::stoi(reading);
                                break;
                            case 2:
                                heartRate = std::stoi(reading);
                                break;
                            case 3:
                                respiratoryRate = std::stoi(reading);
                                break;
                            default:
                                break;
                            }
                            readingEditSelector++;
                        }
                        newVital = new Vitals(bodyTemperature, bloodPressure, heartRate, respiratoryRate);
                        if (heartRate != 0) {
                            currentPatient->addVitals(newVital);
                        }
                    }
                    break;
                }
                default:
                        break;
                }
                patientEditSelector++;
            }


        }
    }

    return patients;
}
