#include "AlertContext.h"

void AlertContext::setStrategy(AbstractAlert alert)
{
	currentStrategy = alert;
}

void AlertContext::runStrategy(const Vitals* vitals, const Patient* patient)
{
	currentStrategy.checkVitals(vitals, patient);
}
