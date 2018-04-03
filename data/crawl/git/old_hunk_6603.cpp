	strbuf_release(&two);

	fclose(f);
	if (out)
		fclose(out);
	if (sha1)
		git_SHA1_Final(sha1, &ctx);
	if (hunk != RR_CONTEXT) {
		if (output)
			unlink(output);
		return error("Could not parse conflict hunks in %s", path);
	}
	return hunk_no;
}

