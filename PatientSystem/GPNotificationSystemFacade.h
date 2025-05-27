#pragma once

#include "Patient.h"


class GPNotificationSystemFacade : public PatientSubscriber {
public:
	GPNotificationSystemFacade();
	virtual ~GPNotificationSystemFacade();

	void sendGPNotificationForPatient(Patient* p);

	virtual void stateHasChanged(Patient* patient) override;
};

