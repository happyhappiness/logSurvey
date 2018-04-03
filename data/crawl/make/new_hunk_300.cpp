2013-09-12  Paul Smith  <psmith@gnu.org>

	Rework output to handle synchronization and directory logging more
	reliably.

	* output.c: New file.  Implement lazy synchronization and
	directory logging so that we manage them "just in time", and the
	destination of the output is set via a global state variable.
	* output.h: New file.
	* function.c (func_shell_base): Ensure the output is set up before
	running a shell command, in case it writes to stderr.
	(func_error): Use outputs() to generate output.
	* job.h (struct child): Add struct output to track the child's output.
	* job.c: Use struct output in the child structure to track output.
	(child_out, sync_init, assign_child_tempfiles, pump_from_tmp)
	(acquire_semaphore, release_semaphore, sync_output): Move most of
	the output_sync handling to output.c.
	(child_error): Set output, then use simple message() and error()
	not _s versions.
	* main.c (log_working_directory): Moved to output.c
	(trace_option, decode_trace_flags) Remove.  Remove support for
	different trace modes; we don't use it anymore.
	(die) Invoke output_close() before we exit.
	* misc.c (message_s, error_s): Removed; no longer needed.
	(message, error, fatal, perror_with_name, pfatal_with_name): Moved
	to output.c.
	* makeint.h: Remove message_s(), error_s(), and
	log_working_directory().  Remove the TRACE_* macros.
	* doc/make.texi: Enhance documentation for output sync, and remove
	MODE assignment for --trace.
	* make.1: Remove MODE assignment for --trace.
	* Makefile.am: Add new files.
	* NMakefile.template: Ditto.
	* SMakefile.template: Ditto.
	* build_w32.bat: Ditto.
	* dosbuild.bat: Ditto.
	* make.lnk: Ditto.
	* make_nsvc_net2003.vcproj: Ditto.
	* makefile.vms: Ditto.
	* po/POTFILES.in: Ditto.

2013-07-22  Paul Smith  <psmith@gnu.org>

	* implicit.c (pattern_search): Use PARSE_SIMPLE_SEQ() even for
