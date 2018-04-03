
/* common helpers */

#define ARRAY_SIZE(x) (sizeof(x)/sizeof(x[0]))

static void die(const char *err, ...)
{
	char msg[4096];
