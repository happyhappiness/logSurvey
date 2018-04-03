	 */
	xwrite(child_notifier, "", 1);
}

static void prepare_cmd(struct argv_array *out, const struct child_process *cmd)
{
	if (!cmd->argv[0])
		die("BUG: command is empty");

	if (cmd->git_cmd) {
		argv_array_push(out, "git");
		argv_array_pushv(out, cmd->argv);
	} else if (cmd->use_shell) {
		prepare_shell_cmd(out, cmd->argv);
	} else {
		argv_array_pushv(out, cmd->argv);
	}
}
#endif

static inline void set_cloexec(int fd)
