		/* fall through */
	default:
		last_errno = errno;
		strbuf_addf(err, "unable to create directory for %s", ref_file);
		goto error_return;
	}

