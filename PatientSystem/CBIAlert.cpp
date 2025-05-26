#include "CBIAlert.h";

AlertLevel CBIAlert::checkVitals(const Vitals* vitals, const Patient* patient) {
	AlertLevel alertLevel = AlertLevel::Green;
	int rr = vitals->RR();
	if (rr > 20) {
		alertLevel = AlertLevel::Yellow;
	}
	if (rr > 30) {
		alertLevel = AlertLevel::Orange;
	}
	if (rr > 40) {
		alertLevel = AlertLevel::Red;
	}
	return alertLevel;
}