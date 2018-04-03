      logprintf (LOG_NOTQUIET, _("\
%s: certificate common name `%s' doesn't match requested host name `%s'.\n"),
		 severity, escnonprint (common_name), escnonprint (host));
      success = 0;
    }

  if (success)
