
      /* Try to start that job.  We break out of the loop as soon
	 as start_waiting_job puts one back on the waiting list.  */
    }
  while (start_waiting_job (job) && waiting_jobs != 0);

  return;
}

#ifdef VMS
#include <descrip.h>
#include <clidef.h>

/* This is called as an AST when a child process dies (it won't get
   interrupted by anything except a higher level AST).
*/
int vmsHandleChildTerm(struct child *child)
{
    int status;
    register struct child *lastc, *c;
    int child_failed;

    vms_jobsefnmask &= ~(1 << (child->efn - 32));

    lib$free_ef(&child->efn);

    (void) sigblock (fatal_signal_mask);

    child_failed = !(child->cstatus & 1 || ((child->cstatus & 7) == 0));

    /* Search for a child matching the deceased one.  */
    lastc = 0;
#if defined(RECURSIVEJOBS) /* I've had problems with recursive stuff and process handling */
    for (c = children; c != 0 && c != child; lastc = c, c = c->next);
#else
    c = child;
#endif

    if (child_failed && !c->noerror && !ignore_errors_flag)
      {
	/* The commands failed.  Write an error message,
	   delete non-precious targets, and abort.  */
	child_error (c->file->name, c->cstatus, 0, 0, 0);
	c->file->update_status = 1;
	delete_child_targets (c);
      }
    else
      {
	if (child_failed)
	  {
	    /* The commands failed, but we don't care.  */
	    child_error (c->file->name, c->cstatus, 0, 0, 1);
	    child_failed = 0;
	  }

#if defined(RECURSIVEJOBS) /* I've had problems with recursive stuff and process handling */
	/* If there are more commands to run, try to start them.  */
	start_job (c);

	switch (c->file->command_state)
	  {
	  case cs_running:
	    /* Successfully started.  */
	    break;

	  case cs_finished:
	    if (c->file->update_status != 0) {
		/* We failed to start the commands.  */
		delete_child_targets (c);
	    }
	    break;

	  default:
	    error ("internal error: `%s' command_state \
%d in child_handler", c->file->name);
	    abort ();
	    break;
	  }
#endif /* RECURSIVEJOBS */
      }

    /* Set the state flag to say the commands have finished.  */
    c->file->command_state = cs_finished;
    notice_finished_file (c->file);

#if defined(RECURSIVEJOBS) /* I've had problems with recursive stuff and process handling */
    /* Remove the child from the chain and free it.  */
    if (lastc == 0)
      children = c->next;
    else
      lastc->next = c->next;
    free_child (c);
#endif /* RECURSIVEJOBS */

    /* There is now another slot open.  */
    if (job_slots_used > 0)
      --job_slots_used;

    /* If the job failed, and the -k flag was not given, die.  */
    if (child_failed && !keep_going_flag)
      die (EXIT_FAILURE);

    (void) sigsetmask (sigblock (0) & ~(fatal_signal_mask));

    return 1;
}

/* VMS:
   Spawn a process executing the command in ARGV and return its pid. */

#define MAXCMDLEN 200

int
child_execute_job (argv, child)
     char *argv;
     struct child *child;
{
  int i;
  static struct dsc$descriptor_s cmddsc;
#ifndef DONTWAITFORCHILD
  int spflags = 0;
#else
  int spflags = CLI$M_NOWAIT;
#endif
  int status;
  char cmd[4096],*p,*c;
  char comname[50];

/* Remove backslashes */
  for (p = argv, c = cmd; *p; p++,c++)
    {
      if (*p == '\\') p++;
	*c = *p;
    }
  *c = *p;

  /* check for maximum dcl length and create *.com file if neccesary */

  comname[0] = '\0';

  if (strlen (cmd) > MAXCMDLEN)
    {
      FILE *outfile;
      char tmp;

      strcpy (comname, "sys$scratch:CMDXXXXXX.COM");
      (void) mktemp (comname);

      outfile = fopen (comname, "w");
      if (outfile == 0)
	pfatal_with_name (comname);

      fprintf (outfile, "$ ");
      c = cmd;

      while (c)
	{
	  p = strchr (c, ',');
	  if ((p == NULL) || (p-c > MAXCMDLEN))
	    p = strchr (c, ' ');
	  if (p != NULL)
	    {
	      p++;
	      tmp = *p;
	      *p = '\0';
	    }
	  else
	    tmp = '\0';
	  fprintf (outfile, "%s%s\n", c, (tmp == '\0')?"":" -");
	  if (p != NULL)
	    *p = tmp;
	  c = p;
	}

      fclose (outfile);

      sprintf (cmd, "$ @%s", comname);

      if (debug_flag)
	printf ("Executing %s instead\n", cmd);
    }

  cmddsc.dsc$w_length = strlen(cmd);
  cmddsc.dsc$a_pointer = cmd;
  cmddsc.dsc$b_dtype = DSC$K_DTYPE_T;
  cmddsc.dsc$b_class = DSC$K_CLASS_S;

  child->efn = 0;
  while (child->efn < 32 || child->efn > 63)
    {
      status = lib$get_ef(&child->efn);
      if (!(status & 1))
	return 0;
    }

  sys$clref(child->efn);

  vms_jobsefnmask |= (1 << (child->efn - 32));

#ifndef DONTWAITFORCHILD
  status = lib$spawn(&cmddsc,0,0,&spflags,0,&child->pid,&child->cstatus,
		       &child->efn,0,0);
  vmsHandleChildTerm(child);
#else
  status = lib$spawn(&cmddsc,0,0,&spflags,0,&child->pid,&child->cstatus,
		       &child->efn,vmsHandleChildTerm,child);
#endif

  if (!(status & 1))
    {
      printf("Error spawning, %d\n",status);
      fflush(stdout);
    }

  unlink (comname);

  return (status & 1);
}

#else /* !VMS */

/* UNIX:
   Replace the current process with one executing the command in ARGV.
   STDIN_FD and STDOUT_FD are used as the process's stdin and stdout; ENVP is
   the environment of the new program.  This function does not return.  */

