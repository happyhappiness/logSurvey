
	if (!files) {
		assert(insertions == 0 && deletions == 0);
		return fprintf(fp, "%s\n", _(" 0 files changed"));
	}

	strbuf_addf(&sb,
		    Q_(" %d file changed", " %d files changed", files),
		    files);

	/*
