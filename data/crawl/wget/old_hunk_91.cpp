          }
    }

  if (qop != NULL && strcmp(qop,"auth"))
    {
      logprintf (LOG_NOTQUIET, _("Unsupported quality of protection '%s'.\n"), qop);
      xfree (qop); /* force freeing mem and return */
