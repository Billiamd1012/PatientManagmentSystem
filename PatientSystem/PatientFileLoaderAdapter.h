#pragma once
#include "AbstractPatientDatabaseLoader.h"
#include "PatientFileLoader.h"

class PatientFileLoaderAdapter : public AbstractPatientDatabaseLoader {
public:
	// Inherited via AbstractPatientDatabaseLoader
	void initialiseConnection() override;

	void loadPatients(std::vector<Patient*>& patientIn) override;

	void closeConnection() override;
protected:
	PatientFileLoader _pfl;
};