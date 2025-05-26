#include "ASAlert.h"
#include "Vitals.h"

AlertLevel ASAlert::checkVitals(const Vitals* vitals, const Patient* patient) {
	AlertLevel alertLevel = AlertLevel::Green;
	int bp = vitals->BP();
	if (bp > 110) {
		alertLevel = AlertLevel::Yellow;
	}
	if (bp > 130) {
		alertLevel = AlertLevel::Orange;
	}
	if (bp > 140) {
		alertLevel = AlertLevel::Red;
	}
	return alertLevel;
}