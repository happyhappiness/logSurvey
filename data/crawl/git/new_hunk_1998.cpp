			break;
	}

	if (id->collection->status_nr <= id->variant) {
		error("no remembered resolution for '%s'", path);
		goto fail_exit;
	}

	filename = rerere_path(id, "postimage");
	if (unlink(filename)) {
		if (errno == ENOENT)
			error("no remembered resolution for %s", path);
		else
			error("cannot unlink %s: %s", filename, strerror(errno));
		goto fail_exit;
	};

	/*
	 * Update the preimage so that the user can resolve the
