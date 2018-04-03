		/* fall through */
	default:
		last_errno = errno;
		error("unable to create directory for %s", ref_file);
		goto error_return;
	}

