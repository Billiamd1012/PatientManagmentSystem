#include "PatientLoader.h"

PatientLoader::PatientLoader()
{

}

void PatientLoader::loadPatients(std::vector<Patient*>& patientIn)
{
    for (const auto& loader : _dataLoaders) {
        loader->loadPatients(patientIn);
    }
}

void PatientLoader::addLoader(std::shared_ptr<AbstractPatientDatabaseLoader> loader)
{
	_dataLoaders.push_back(loader);
    loader->initialiseConnection();
}

void PatientLoader::removeLoader(std::shared_ptr<AbstractPatientDatabaseLoader> loader)
{
    loader->closeConnection();
    _dataLoaders.erase(
        std::remove_if(_dataLoaders.begin(), _dataLoaders.end(),
            [loader](const std::shared_ptr<AbstractPatientDatabaseLoader>& existingLoader) {
                return existingLoader.get() == loader.get();
            }),
        _dataLoaders.end());
}
