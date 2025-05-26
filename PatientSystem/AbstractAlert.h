#pragma once
#include "PatientAlertLevels.h"
#include "Vitals.h"
#include "Patient.h"

class AbstractAlert {
public:
	//checkvitals takes in a patients vitals and outputs an alert level
	virtual AlertLevel checkVitals(const Vitals* vitals, const Patient* patient);
};