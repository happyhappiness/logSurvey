}

void
jobserver_parse_auth (const char *auth)
{
  jobserver_semaphore = OpenSemaphore (
  SEMAPHORE_ALL_ACCESS,   /* Semaphore access setting */
    FALSE,                  /* Child processes DON'T inherit */
    auth);                   /* Semaphore name */

  if (jobserver_semaphore == NULL)
    {
      DWORD err = GetLastError ();
      const char *estr = map_windows32_error_to_string (err);
      fatal (NILF, strlen (auth) + INTSTR_LENGTH + strlen (estr),
             _("internal error: unable to open jobserver semaphore '%s': (Error %ld: %s)"),
             auth, err, estr);
    }
  DB (DB_JOBS, (_("Jobserver client (semaphore %s)\n"), auth));
}

char *
jobserver_get_auth ()
{
  return xstrdup (jobserver_semaphore_name);
}

unsigned int
