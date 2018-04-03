	unlink_or_warn(tmpfile);
	if (ret) {
		if (ret != EEXIST) {
			return error("unable to write sha1 filename %s: %s", filename, strerror(ret));
		}
		/* FIXME!!! Collision check here ? */
	}
