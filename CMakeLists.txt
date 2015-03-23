set ( SOURCES 
	"src/scheduler.cpp"
	"src/interface.cpp"
)

set (HEADERS 
        "include/scheduler.h"
)

include_directories("include")

add_library ( scheduler MODULE ${SOURCES} ${HEADERS})
target_link_libraries(scheduler PRIVATE lms)
