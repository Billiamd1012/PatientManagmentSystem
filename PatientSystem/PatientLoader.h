#pragma once
#include "AbstractPatientDatabaseLoader.h"
#include <memory>

class Patient;

class PatientLoader {
public:
	PatientLoader();
	void loadPatients(std::vector<Patient*>& patientIn);
	void addLoader(std::shared_ptr<AbstractPatientDatabaseLoader> loader);
	void removeLoader(std::shared_ptr<AbstractPatientDatabaseLoader> loader);
protected:
	std::vector<std::shared_ptr<AbstractPatientDatabaseLoader>> _dataLoaders;
};