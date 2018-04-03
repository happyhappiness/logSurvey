	}

	if (freq->localfile < 0) {
		error("Couldn't create temporary file %s: %s",
		      freq->tmpfile, strerror(errno));
		goto abort;
	}

