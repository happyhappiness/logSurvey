	am_destroy(state);
}

int cmd_am(int argc, const char **argv, const char *prefix)
{
	struct am_state state;

	const char * const usage[] = {
		N_("git am [options] [(<mbox>|<Maildir>)...]"),
		NULL
	};

	struct option options[] = {
		OPT_END()
	};

