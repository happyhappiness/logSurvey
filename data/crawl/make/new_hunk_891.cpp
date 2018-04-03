	variable is appended more than once within the current target
	context.  Fixes PR/1831.

2000-08-16  Paul D. Smith  <psmith@gnu.org>

	* function.c (func_shell): Nul-terminate the buffer before
	printing an exec error message (just in case it's not!).
	Fixes PR/1860, reported by Joey Hess <joey@valinux.com>.

2000-07-25  Paul D. Smith  <psmith@gnu.org>

	* job.c (construct_command_argv_internal): Add "~" to the list of
