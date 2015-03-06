#include <scheduler.h>

extern "C" {
void* getInstance () {
	return new Scheduler();
}
}
