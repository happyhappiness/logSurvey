#define DEFAULT_INDENT1 6
#define DEFAULT_INDENT2 9

static void parse_wrap_args(const char *arg, int *in1, int *in2, int *wrap)
{
	arg += 2; /* skip -w */

	*wrap = parse_uint(&arg, ',');
	if (*wrap < 0)
		die(wrap_arg_usage);
	*in1 = parse_uint(&arg, ',');
	if (*in1 < 0)
		die(wrap_arg_usage);
	*in2 = parse_uint(&arg, '\0');
	if (*in2 < 0)
		die(wrap_arg_usage);

	if (!*wrap)
		*wrap = DEFAULT_WRAPLEN;
	if (!*in1)
		*in1 = DEFAULT_INDENT1;
	if (!*in2)
		*in2 = DEFAULT_INDENT2;
	if (*wrap &&
	    ((*in1 && *wrap <= *in1) ||
	     (*in2 && *wrap <= *in2)))
		die(wrap_arg_usage);
}

void shortlog_init(struct shortlog *log)
