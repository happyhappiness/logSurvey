		error("git upload-pack: git-pack-objects died with error.");
		goto fail;
	}
	/* flush the data */
	if (0 <= buffered) {
		data[0] = buffered;