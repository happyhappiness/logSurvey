sig_handler_t mingw_signal(int sig, sig_handler_t handler)
{
	sig_handler_t old = timer_fn;

	switch (sig) {
	case SIGALRM:
		timer_fn = handler;
		break;

	case SIGINT:
		sigint_fn = handler;
		break;

	default:
		return signal(sig, handler);
	}

	return old;
}

#undef raise
int mingw_raise(int sig)
{
	switch (sig) {
	case SIGALRM:
		if (timer_fn == SIG_DFL) {
			if (isatty(STDERR_FILENO))
				fputs("Alarm clock\n", stderr);
			exit(128 + SIGALRM);
		} else if (timer_fn != SIG_IGN)
			timer_fn(SIGALRM);
		return 0;

	case SIGINT:
		if (sigint_fn == SIG_DFL)
			exit(128 + SIGINT);
		else if (sigint_fn != SIG_IGN)
			sigint_fn(SIGINT);
		return 0;

	default:
		return raise(sig);
	}
}


static const char *make_backslash_path(const char *path)
{
	static char buf[PATH_MAX + 1];
