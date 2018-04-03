static const char pre_receive_hook[] = "hooks/pre-receive";
static const char post_receive_hook[] = "hooks/post-receive";

static int hook_status(int code, const char *hook_name)
{
	switch (code) {
	case 0:
		return 0;
	case -ERR_RUN_COMMAND_FORK:
		return error("hook fork failed");
	case -ERR_RUN_COMMAND_EXEC:
		return error("hook execute failed");
	case -ERR_RUN_COMMAND_PIPE:
		return error("hook pipe failed");
	case -ERR_RUN_COMMAND_WAITPID:
		return error("waitpid failed");
	case -ERR_RUN_COMMAND_WAITPID_WRONG_PID:
		return error("waitpid is confused");
	case -ERR_RUN_COMMAND_WAITPID_SIGNAL:
		return error("%s died of signal", hook_name);
	case -ERR_RUN_COMMAND_WAITPID_NOEXIT:
		return error("%s died strangely", hook_name);
	default:
		error("%s exited with error code %d", hook_name, -code);
		return -code;
	}
}
