#include "KSAlert.h"
#include "Vitals.h"
#include "Patient.h"

AlertLevel KSAlert::checkVitals(const Vitals* vitals, const Patient* patient) {
	AlertLevel alertLevel = AlertLevel::Green;
	int hr = vitals->HR();
	int age = patient->age();
	if (age >= 12 && hr > 100) {
		alertLevel = AlertLevel::Red;
	}
	if (age < 12 && hr > 120) {
		alertLevel = AlertLevel::Red;
	}
	return alertLevel;
}