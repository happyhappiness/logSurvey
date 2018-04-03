	am_destroy(state);
}

/**
 * parse_options() callback that validates and sets opt->value to the
 * PATCH_FORMAT_* enum value corresponding to `arg`.
 */
static int parse_opt_patchformat(const struct option *opt, const char *arg, int unset)
{
	int *opt_value = opt->value;

	if (!strcmp(arg, "mbox"))
		*opt_value = PATCH_FORMAT_MBOX;
	else
		return error(_("Invalid value for --patch-format: %s"), arg);
	return 0;
}

int cmd_am(int argc, const char **argv, const char *prefix)
{
	struct am_state state;
	int patch_format = PATCH_FORMAT_UNKNOWN;

	const char * const usage[] = {
		N_("git am [options] [(<mbox>|<Maildir>)...]"),
		NULL
	};

	struct option options[] = {
		OPT_CALLBACK(0, "patch-format", &patch_format, N_("format"),
			N_("format the patch(es) are in"),
			parse_opt_patchformat),
		OPT_END()
	};

