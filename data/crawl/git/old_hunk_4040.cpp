	fflush(stdout);
}

static int cmd_import(const char *line)
{
	int code;
	int dumpin_fd;
	unsigned int startrev = 0;
	struct argv_array svndump_argv = ARGV_ARRAY_INIT;
	struct child_process svndump_proc;

	if (dump_from_file) {
		dumpin_fd = open(url, O_RDONLY);
		if(dumpin_fd < 0)
