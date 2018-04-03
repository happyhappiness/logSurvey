#include "config.h"
#include "Debug.h"
#include "SquidTime.h"

/* for Config */
#include "structs.h"

int Debug::Levels[MAX_DEBUG_SECTIONS];
int Debug::level;
FILE *debug_log = NULL;
static char *debug_log_file = NULL;
static int Ctx_Lock = 0;
