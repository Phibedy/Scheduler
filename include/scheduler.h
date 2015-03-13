#ifndef IMPORTER_SCHEDULER_IMPORTER_H
#define IMPORTER_SCHEDULER_IMPORTER_H

#include <lms/module.h>
#include <lms/datamanager.h>
#include <lms/extra/time.h>

class Scheduler : public lms::Module {

public:

    bool initialize();
	bool deinitialize();

	bool cycle();

protected:
    lms::extra::PrecisionTime configLooptime;
    lms::extra::PrecisionTime configWarnTolerance;

    lms::extra::PrecisionTime last;
    lms::extra::PrecisionTime cycleTimeStart;
};

#endif
