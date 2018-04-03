  child->efn = 0;
  while (child->efn < 32 || child->efn > 63)
    {
      status = lib$get_ef ((unsigned long *)&child->efn);
      if (!(status & 1))
	return 0;
    }

  sys$clref (child->efn);

  vms_jobsefnmask |= (1 << (child->efn - 32));

/*
             LIB$SPAWN  [command-string]
			[,input-file]
			[,output-file]
			[,flags]
			[,process-name]
			[,process-id] [,completion-status-address] [,byte-integer-event-flag-num]
			[,AST-address] [,varying-AST-argument]
			[,prompt-string] [,cli] [,table]
*/

#ifndef DONTWAITFORCHILD
/*
 *	Code to make ctrl+c and ctrl+y working.
 *	The problem starts with the synchronous case where after lib$spawn is
 *	called any input will go to the child. But with input re-directed,
 *	both control characters won't make it to any of the programs, neither
 *	the spawning nor to the spawned one. Hence the caller needs to spawn
 *	with CLI$M_NOWAIT to NOT give up the input focus. A sys$waitfr
 *	has to follow to simulate the wanted synchronous behaviour.
 *	The next problem is ctrl+y which isn't caught by the crtl and
 *	therefore isn't converted to SIGQUIT (for a signal handler which is
 *	already established). The only way to catch ctrl+y, is an AST
 *	assigned to the input channel. But ctrl+y handling of DCL needs to be
 *	disabled, otherwise it will handle it. Not to mention the previous
 *	ctrl+y handling of DCL needs to be re-established before make exits.
 *	One more: At the time of LIB$SPAWN signals are blocked. SIGQUIT will
 *	make it to the signal handler after the child "normally" terminates.
 *	This isn't enough. It seems reasonable for simple command lines like
 *	a 'cc foobar.c' spawned in a subprocess but it is unacceptable for
 *	spawning make. Therefore we need to abort the process in the AST.
 *
 *	Prior to the spawn it is checked if an AST is already set up for
 *	ctrl+y, if not one is set up for a channel to SYS$COMMAND. In general
 *	this will work except if make is run in a batch environment, but there
 *	nobody can press ctrl+y. During the setup the DCL handling of ctrl+y
 *	is disabled and an exit handler is established to re-enable it.
 *	If the user interrupts with ctrl+y, the assigned AST will fire, force
 *	an abort to the subprocess and signal SIGQUIT, which will be caught by
 *	the already established handler and will bring us back to common code.
 *	After the spawn (now /nowait) a sys$waitfr simulates the /wait and
 *	enables the ctrl+y be delivered to this code. And the ctrl+c too,
 *	which the crtl converts to SIGINT and which is caught by the common
 *	signal handler. Because signals were blocked before entering this code
 *	sys$waitfr will always complete and the SIGQUIT will be processed after
 *	it (after termination of the current block, somewhere in common code).
 *	And SIGINT too will be delayed. That is ctrl+c can only abort when the
 *	current command completes. Anyway it's better than nothing :-)
 */

  if (!setupYAstTried)
    tryToSetupYAst();
  status = lib$spawn (&cmddsc,					/* cmd-string  */
		      (ifiledsc.dsc$w_length == 0)?0:&ifiledsc, /* input-file  */
		      (ofiledsc.dsc$w_length == 0)?0:&ofiledsc, /* output-file */
		      &spflags,					/* flags  */
		      &pnamedsc,				/* proc name  */
		      &child->pid, &child->cstatus, &child->efn,
		      0, 0,
		      0, 0, 0);
  pidToAbort= child->pid;
  status= sys$waitfr (child->efn);
  pidToAbort= 0;
  vmsHandleChildTerm(child);
#else
  status = lib$spawn (&cmddsc,
		      (ifiledsc.dsc$w_length == 0)?0:&ifiledsc,
		      (ofiledsc.dsc$w_length == 0)?0:&ofiledsc,
		      &spflags,
		      &pnamedsc,
		      &child->pid, &child->cstatus, &child->efn,
		      vmsHandleChildTerm, child,
		      0, 0, 0);
#endif

  if (!(status & 1))
    {
      printf ("Error spawning, %d\n",status);
      fflush (stdout);
    }

  if (comname[0] && !ISDB (DB_JOBS)))
    unlink (comname);

  return (status & 1);
}
