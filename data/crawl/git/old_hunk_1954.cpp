		state->unsafe_paths = 0;
}

int cmd_apply(int argc, const char **argv, const char *prefix)
{
	int i;
	int errs = 0;
	int force_apply = 0;
	int options = 0;
	int read_stdin = 1;
	struct apply_state state;

	struct option builtin_apply_options[] = {
