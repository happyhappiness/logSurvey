		if (prev_posn>0) {
			prev_posn = 0;
			lseek(freq->localfile, 0, SEEK_SET);
			ftruncate(freq->localfile, 0);
		}
	}
