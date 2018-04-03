#include "builtin.h"
#include "utf8.h"
#include "strbuf.h"
#include "mailinfo.h"

static const char mailinfo_usage[] =
	"git mailinfo [-k | -b] [-m | --message-id] [-u | --encoding=<encoding> | -n] [--scissors | --no-scissors] <msg> <patch> < mail >info";
