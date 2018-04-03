	if (push_verbosely)
		fprintf(stderr, "Getting index for pack %s\n", hex);

	sprintf(url, "%sobjects/pack/pack-%s.idx", repo->url, hex);

	filename = sha1_pack_index_name(sha1);
	snprintf(tmpfile, sizeof(tmpfile), "%s.temp", filename);
