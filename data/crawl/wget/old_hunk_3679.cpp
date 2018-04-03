	      logprintf (LOG_NOTQUIET,
			 _("\
\n\
    The server does not support continued download;\n\
    refusing to truncate `%s'.\n\n"), u->local);
	      return CONTNOTSUPPORTED;
	    }

