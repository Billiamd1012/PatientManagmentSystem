#include "PatientFileLoaderAdapter.h"

void PatientFileLoaderAdapter::initialiseConnection()
{
}

void PatientFileLoaderAdapter::loadPatients(std::vector<Patient*>& patientIn)
{
    //now load patients from the patients.txt file
    std::vector<Patient*> patientsFromFile = _pfl.loadPatientFile("patients.txt");

    for (int i = 0; i < patientsFromFile.size(); i++) {
        patientIn.push_back(patientsFromFile[i]);
    }

}

void PatientFileLoaderAdapter::closeConnection()
{
}
