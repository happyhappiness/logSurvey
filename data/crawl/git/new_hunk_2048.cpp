	}

	if (freq->localfile < 0) {
		error_errno("Couldn't create temporary file %s", freq->tmpfile);
		goto abort;
	}

