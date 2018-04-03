	/* &state->fn_table is cleared at the end of apply_patch() */
}

int cmd_apply(int argc, const char **argv, const char *prefix)
{
	int i;
	int errs = 0;
	int is_not_gitdir = !startup_info->have_repository;
	int force_apply = 0;
	int options = 0;
	int read_stdin = 1;
