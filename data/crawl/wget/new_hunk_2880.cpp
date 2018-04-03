	logprintf (LOG_VERBOSE, _(", %s remaining"),
		   with_thousand_seps (size - start));
    }
  logputs (LOG_VERBOSE, !authoritative ? _(" (unauthoritative)\n") : "\n");
}

/* Retrieves a file with denoted parameters through opening an FTP
