	}

	if (finish_command(&pack_objects)) {
		error("git-upload-pack: git-pack-objects died with error.");
		goto fail;
	}
	if (finish_async(&rev_list))
