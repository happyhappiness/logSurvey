	      logprintf (LOG_NOTQUIET,
			 _("\
\n\
The server does not support continued downloads, which conflicts with `-c'.\n\
Refusing to truncate `%s'.\n\n"), u->local);
	      FREE_MAYBE (type);
	      FREE_MAYBE (all_headers);
	      CLOSE_INVALIDATE (sock);
	      return CONTNOTSUPPORTED;
	    }

