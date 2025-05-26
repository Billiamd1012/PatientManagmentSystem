#pragma once

#include "AbstractAlert.h"
#include "Vitals.h"
#include "Patient.h"


class AlertContext {
public:
	void setStrategy(AbstractAlert alert);
	void runStrategy(const Vitals* vitals, const Patient* patient);
private:
	AbstractAlert currentStrategy;
};