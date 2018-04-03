}

void
jobserver_parse_arg (const char* arg)
{
  jobserver_semaphore = OpenSemaphore (
  SEMAPHORE_ALL_ACCESS,   /* Semaphore access setting */
    FALSE,                  /* Child processes DON'T inherit */
    arg);                   /* Semaphore name */

  if (jobserver_semaphore == NULL)
    {
      DWORD err = GetLastError ();
      const char *estr = map_windows32_error_to_string (err);
      fatal (NILF, strlen (arg) + INTSTR_LENGTH + strlen (estr),
             _("internal error: unable to open jobserver semaphore '%s': (Error %ld: %s)"),
             arg, err, estr);
    }
  DB (DB_JOBS, (_("Jobserver client (semaphore %s)\n"), arg));
}

char *
jobserver_get_arg ()
{
  char *fds = xmalloc (MAX_PATH + 1);
  strcpy (fds, jobserver_semaphore_name);
  return fds;
}

unsigned int
