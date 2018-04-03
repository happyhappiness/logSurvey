
static enum wt_status_format status_format = STATUS_FORMAT_UNSPECIFIED;

static int opt_parse_m(const struct option *opt, const char *arg, int unset)
{
	struct strbuf *buf = opt->value;
