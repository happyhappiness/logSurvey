	finish_command(process);
}

static int start_multi_file_filter_fn(struct cmd2process *entry)
{
	int err;
	struct string_list cap_list = STRING_LIST_INIT_NODUP;
	char *cap_buf;
	const char *cap_name;
	struct child_process *process = &entry->process;
	const char *cmd = entry->cmd;

	sigchain_push(SIGPIPE, SIG_IGN);

