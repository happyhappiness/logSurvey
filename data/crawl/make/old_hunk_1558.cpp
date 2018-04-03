int
start_remote_job_p ()
{
  if (Customs_Host (EXPORT_SAME, &permit) != RPC_SUCCESS)
    return 0;

  return !CUSTOMS_FAIL (&permit.addr);
}

/* Start a remote job running the command in ARGV,
   with environment from ENVP.  It gets standard input from STDIN_FD.  On
   failure, return nonzero.  On success, return zero, and set *USED_STDIN
   to nonzero if it will actually use STDIN_FD, zero if not, set *ID_PTR to
   a unique identification, and set *IS_REMOTE to zero if the job is local,
   nonzero if it is remote (meaning *ID_PTR is a process ID).  */

int
start_remote_job (argv, envp, stdin_fd, is_remote, id_ptr, used_stdin)
