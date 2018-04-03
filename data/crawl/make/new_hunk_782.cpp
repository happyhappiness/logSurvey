2004-05-16  Paul D. Smith  <psmith@gnu.org>

	* remake.c (update_goal_chain): Change the argument specifying
	whether we're rebuilding makefiles to be a global variable,
	REBUILDING_MAKEFILES.
	(complain): Extract the code that complains about no rules to make
	a target into a separate function.
	(update_file_1): If we tried to rebuild a file during the makefile
	rebuild phase and it was dontcare, then no message was printed.
	If we then try to build the same file during the normal build,
	print a message this time.
	(remake_file): Don't complain about un-remake-able files when
	we're rebuilding makefiles.

2004-05-11  Paul D. Smith  <psmith@gnu.org>

	* job.c (construct_command_argv_internal): OS/2 patches from
	Andreas Buening <andreas.buening@nexgo.de>.

2004-05-10  Paul D. Smith  <psmith@gnu.org>

	* remake.c (update_file): Don't walk the double-colon chain unless
	this is a double-colon rule.  Fix suggested by Boris Kolpackov
	<boris@kolpackov.net>.

	* makefile.vms (CFLAGS): Remove glob/globfree (see readme.vms docs)
	* readme.vms: New section describing OpenVMS support and issues.
	* default.c (default_variables): Add support for IA64.
	* job.c (tryToSetupYAst) [VMS]: On VMS running make in batch mode
	without some privilege aborts make with the error
	%SYSTEM-F-NOPRIV. It happens when setting up a handler for
	pressing Ctrl+Y and the input device is no terminal. The change
	catches this error and just continues.

	Patches by Hartmut Becker <Hartmut.Becker@hp.com>

2004-04-25  Paul D. Smith  <psmith@gnu.org>

	* commands.c (set_file_variables): Set $< properly in the face of
	order-only prerequisites.
	Patch from Boris Kolpackov <boris@kolpackov.net>

2004-04-21  Bob Byrnes  <byrnes@curl.com>

	* main.c (main): Notice failures to remake makefiles.

2004-03-28  Paul D. Smith  <psmith@gnu.org>

	Patches for Acorn RISC OS by Peter Naulls <peter@chocky.org>

	* job.c: No default shell for RISC OS.
	(load_too_high): Hard-code the return to 1.
	(construct_command_argv_internal): No sh_chars or sh_cmds.
	* getloadavg.c: Don't set LOAD_AVE_TYPE on RISC OS.

2004-03-20  Paul D. Smith  <psmith@gnu.org>

	* variable.c (do_variable_definition): Don't append from the
