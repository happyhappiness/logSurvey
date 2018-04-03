static int ambiguous;
static struct string_list list;

static int length_callback(const struct option *opt, const char *arg, int unset)
{
	printf("Callback: \"%s\", %d\n",
		(arg ? arg : "not set"), unset);
	if (unset)
		return 1; /* do not support unset */

