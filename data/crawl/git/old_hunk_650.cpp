#ifndef GIT_WINDOWS_NATIVE
{
	int notify_pipe[2];
	char **childenv;
	struct argv_array argv = ARGV_ARRAY_INIT;

	if (pipe(notify_pipe))
		notify_pipe[0] = notify_pipe[1] = -1;

	prepare_cmd(&argv, cmd);
	childenv = prep_childenv(cmd->env);

