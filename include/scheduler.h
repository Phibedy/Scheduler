#ifndef IMPORTER_SCHEDULER_IMPORTER_H
#define IMPORTER_SCHEDULER_IMPORTER_H

#include <lms/datamanager.h>

#include <lms/module.h>
#include <lms/datamanager.h>
#include <lms/datamanager.h>
#include <time.h>
#include <sys/time.h>

class Scheduler : public lms::Module {

public:

    bool initialize();
	bool deinitialize();

	bool cycle();

protected:
    double looptime;
    double warn_tolerance;
    double cycletime;

    timeval last;
    timeval cycleTimeStart;
    timeval cycleTimeEnd;
};

#endif
