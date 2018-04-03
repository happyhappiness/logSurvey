		git_SHA1_Final(sha1, &ctx);
	if (hunk != RR_CONTEXT) {
		if (output)
			unlink(output);
		return error("Could not parse conflict hunks in %s", path);
	}
	if (wrerror)
