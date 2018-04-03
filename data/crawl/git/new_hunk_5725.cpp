		if (prev_posn>0) {
			prev_posn = 0;
			lseek(freq->localfile, 0, SEEK_SET);
			if (ftruncate(freq->localfile, 0) < 0) {
				error("Couldn't truncate temporary file %s for %s: %s",
					  freq->tmpfile, freq->filename, strerror(errno));
				goto abort;
			}
		}
	}
