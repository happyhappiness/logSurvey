	  /* try without certfile */
	  logprintf (LOG_NOTQUIET,
		     _("Failed to load certificates from %s\n"),
		     opt.cert_file);
	  logprintf (LOG_NOTQUIET,
		     _("Trying without the specified certificate\n"));
	  break;
	case SSLERRCERTKEY:
	  logprintf (LOG_NOTQUIET,
		     _("Failed to get certificate key from %s\n"),
		     opt.cert_key);
	  logprintf (LOG_NOTQUIET,
		     _("Trying without the specified certificate\n"));
	  break;
