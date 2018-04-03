	}

	if (res) {
		fprintf(stderr, "Automatic %s failed.%s\n",
			mebuf.buf, help_msg());
		rerere(allow_rerere_auto);
	} else {
		if (!no_commit)