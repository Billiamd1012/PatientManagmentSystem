#pragma once

#include "AbstractAlert.h"
#include <string>

class Vitals;
class Patient;


class AlertContext {
public:
	~AlertContext();
	void setStrategy(std::string alert);
	AlertLevel runStrategy(const Vitals* vitals, const Patient* patient);
private:
	AbstractAlert* currentStrategy;
};