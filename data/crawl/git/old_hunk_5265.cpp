	}

	if (freq->localfile < 0) {
		error("Couldn't create temporary file %s for %s: %s",
		      freq->tmpfile, freq->filename, strerror(errno));
		goto abort;
	}

