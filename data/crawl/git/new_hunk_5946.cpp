static char *string = NULL;
static char *file = NULL;

static int length_callback(const struct option *opt, const char *arg, int unset)
{
	printf("Callback: \"%s\", %d\n",
		(arg ? arg : "not set"), unset);
