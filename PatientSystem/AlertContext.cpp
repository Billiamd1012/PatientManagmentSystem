#include "AlertContext.h"
#include "ASAlert.h"
#include "CBIAlert.h"
#include "KSAlert.h"

AlertContext::~AlertContext() {
    delete currentStrategy;
}

void AlertContext::setStrategy(std::string alert) {
    delete currentStrategy;
    currentStrategy = nullptr;

    if (alert == "Cordyceps Brain Infection") {
        currentStrategy = new CBIAlert();
    }
    else if (alert == "Kepral’s Syndrome") {
        currentStrategy = new KSAlert();
    }
    else if (alert == "Andromeda Strain") {
        currentStrategy = new ASAlert();
    }
}

AlertLevel AlertContext::runStrategy(const Vitals* vitals, const Patient* patient) {
    if (currentStrategy) {
        return currentStrategy->checkVitals(vitals, patient);
    }
    return AlertLevel::Green;
}