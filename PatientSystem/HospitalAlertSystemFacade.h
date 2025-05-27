#pragma once

#include "Patient.h"


class HospitalAlertSystemFacade : public PatientSubscriber
{
public:
	HospitalAlertSystemFacade();
	virtual ~HospitalAlertSystemFacade();

	void sendAlertForPatient(Patient* p);

	virtual void stateHasChanged(Patient* patient) override;

};

