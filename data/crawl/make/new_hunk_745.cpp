2005-05-07  Paul D. Smith  <psmith@gnu.org>

	* main.c (die): If we're dying with a fatal error (not that a
	command has failed), write back any leftover tokens before we go.

	* job.c (set_child_handler_action_flags): If there are jobs
	waiting for the load to go down, set an alarm to go off in 1
	second.  This allows us to wake up from a potentially long-lasting
	read() and start a new job if the load has gone down.  Turn it off
	after the read.
	(job_noop): Dummy signal handler function.
	(new_job): Invoke it with the new semantics.

	* docs/make.texi: Document secondary expansion.  Various cleanups
	and random work.

2005-05-03  Paul D. Smith  <psmith@gnu.org>

	Rename .DEFAULT_TARGET to .DEFAULT_GOAL: in GNU make terminology
