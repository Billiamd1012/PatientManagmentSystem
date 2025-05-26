#pragma once
#include "AbstractAlert.h"
class ASAlert :
    public AbstractAlert
{
    virtual AlertLevel checkVitals(const Vitals* vitals, const Patient* patient) override;
};

