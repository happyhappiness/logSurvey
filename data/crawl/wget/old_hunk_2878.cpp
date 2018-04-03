      logprintf (LOG_NOTQUIET, _("%s: No certificate presented by %s.\n"),
		 severity, escnonprint (host));
      success = 0;
      goto out;
    }

#ifdef ENABLE_DEBUG
