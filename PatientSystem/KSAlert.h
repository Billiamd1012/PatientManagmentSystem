#pragma once
#include "AbstractAlert.h"

class KSAlert : public AbstractAlert {
public:
	virtual AlertLevel checkVitals(const Vitals* vitals, const Patient* patient) override;
};