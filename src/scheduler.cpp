#include <scheduler.h>
#include <lms/executionmanager.h>
#include <lms/type/static_image.h>
#include <stdio.h>
#include <unistd.h>

// TODO umbenennen, name irreführend

bool Scheduler::initialize() {
    using lms::extra::PrecisionTime;

    logger.debug() << "Init: scheduler";

    configLooptime = PrecisionTime::fromMillis(10);
    configWarnTolerance = PrecisionTime::fromMillis(3);

    last = PrecisionTime::now();

	return true;
}

bool Scheduler::deinitialize() {
    return true;
}

bool Scheduler::cycle () {
    using lms::extra::PrecisionTime;

    PrecisionTime delta = PrecisionTime::now() - last;

    PrecisionTime sleep = configLooptime - delta;
    if (sleep.micros() > 0) {
        logger.info() << "Scheduler sleeps for " << sleep <<
                         ". Cycle rate of "<< (1.0/(delta + sleep).micros() * 1e6) << "Hz";

        PrecisionTime beforeSleep = PrecisionTime::now();
        usleep(sleep.micros());
        PrecisionTime afterSleep = PrecisionTime::now();

        logger.info("sleep") << (afterSleep - beforeSleep) << ", tried " << sleep;
    }
    /// Zeitmessung Zykluszeit
    PrecisionTime cycletimeMicros = PrecisionTime::now() - cycleTimeStart;
    cycleTimeStart = PrecisionTime::now();
    logger.info() << "Cycletime: " << cycletimeMicros << " micros";

    /// Zeitmessung Scheduler
    last = PrecisionTime::now();

    if (delta > configLooptime + configWarnTolerance) {
        logger.warn() << "CYCLING TOO SLOW: " << delta << " per Loop";
    }
	return true;
}
