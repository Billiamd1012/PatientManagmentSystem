#pragma once

class Patient;

class PatientSubscriber {
public:
	virtual void stateHasChanged(Patient* patient) = 0;
};