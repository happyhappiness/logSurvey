		error("git upload-pack: git-pack-objects died with error.");
		goto fail;
	}
	if (shallow_nr && finish_async(&rev_list))
		goto fail;	/* error was already reported */

	/* flush the data */
	if (0 <= buffered) {