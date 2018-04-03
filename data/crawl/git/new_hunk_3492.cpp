	return sz;
}

static void create_pack_file(void)
{
	struct child_process pack_objects;
	char data[8193], progress[128];
	char abort_msg[] = "aborting due to possible repository "
		"corruption on the remote side.";
	int buffered = -1;
	ssize_t sz;
	const char *argv[12];
	int i, arg = 0;
	FILE *pipe_fd;
	char *shallow_file = NULL;

	if (shallow_nr) {
		shallow_file = setup_temporary_shallow();
		argv[arg++] = "--shallow-file";
		argv[arg++] = shallow_file;
	}
	argv[arg++] = "pack-objects";
	argv[arg++] = "--revs";
	if (use_thin_pack)
		argv[arg++] = "--thin";

	argv[arg++] = "--stdout";
	if (!no_progress)
