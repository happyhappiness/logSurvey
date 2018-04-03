	variable is appended more than once within the current target
	context.  Fixes PR/1831.

2000-07-25  Paul D. Smith  <psmith@gnu.org>

	* job.c (construct_command_argv_internal): Add "~" to the list of
