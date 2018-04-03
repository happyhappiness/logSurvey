	finish_command(process);
}

static struct cmd2process *start_multi_file_filter(struct hashmap *hashmap, const char *cmd)
{
	int err;
	struct cmd2process *entry;
	struct child_process *process;
	const char *argv[] = { cmd, NULL };
	struct string_list cap_list = STRING_LIST_INIT_NODUP;
	char *cap_buf;
	const char *cap_name;

	entry = xmalloc(sizeof(*entry));
	entry->cmd = cmd;
	entry->supported_capabilities = 0;
	process = &entry->process;

	child_process_init(process);
	process->argv = argv;
	process->use_shell = 1;
	process->in = -1;
	process->out = -1;
	process->clean_on_exit = 1;
	process->clean_on_exit_handler = stop_multi_file_filter;

	if (start_command(process)) {
		error("cannot fork to run external filter '%s'", cmd);
		return NULL;
	}

	hashmap_entry_init(entry, strhash(cmd));

	sigchain_push(SIGPIPE, SIG_IGN);

