		exit(128);
}

static const char checkout_cache_usage[] =
"git checkout-index [-u] [-q] [-a] [-f] [-n] [--stage=[123]|all] [--prefix=<string>] [--temp] [--] <file>...";

static struct lock_file lock_file;

int cmd_checkout_index(int argc, const char **argv, const char *prefix)
{
	int i;
	int newfd = -1;
	int all = 0;
	int read_from_stdin = 0;
	int prefix_length;

	git_config(git_default_config, NULL);
	state.base_dir = "";
