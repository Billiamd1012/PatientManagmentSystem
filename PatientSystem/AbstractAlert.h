#pragma once
#include "PatientAlertLevels.h"
class Vitals;
class Patient;

class AbstractAlert {
public:
	//checkvitals takes in a patients vitals and outputs an alert level
	virtual AlertLevel checkVitals(const Vitals* vitals, const Patient* patient) = 0;
};