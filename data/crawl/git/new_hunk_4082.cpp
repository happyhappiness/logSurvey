
	if (!files) {
		assert(insertions == 0 && deletions == 0);
		return fprintf(fp, "%s\n", " 0 files changed");
	}

	strbuf_addf(&sb,
		    (files == 1) ? " %d file changed" : " %d files changed",
		    files);

	/*
