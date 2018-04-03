	return (!o->call_depth && o->verbosity >= v) || o->verbosity >= 5;
}

__attribute__((format (printf, 3, 4)))
static void output(struct merge_options *o, int v, const char *fmt, ...)
{
