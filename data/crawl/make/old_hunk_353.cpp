     job, put a token back into the pipe for it.  */

#ifdef WINDOWS32
  if (has_jobserver_semaphore() && jobserver_tokens > 1)
    {
      if (! release_jobserver_semaphore())
        {
          DWORD err = GetLastError();
          fatal (NILF, _("release jobserver semaphore: (Error %ld: %s)"),
                 err, map_windows32_error_to_string(err));
        }

      DB (DB_JOBS, (_("Released token for child %p (%s).\n"), child, child->file->name));
