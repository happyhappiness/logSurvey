sig_handler_t mingw_signal(int sig, sig_handler_t handler)
{
	sig_handler_t old = timer_fn;
	if (sig != SIGALRM)
		return signal(sig, handler);
	timer_fn = handler;
	return old;
}

static const char *make_backslash_path(const char *path)
{
	static char buf[PATH_MAX + 1];
