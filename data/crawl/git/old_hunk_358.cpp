		delete_tempfile(&temporary_sharedindex);
		return ret;
	}
	ret = rename_tempfile(&temporary_sharedindex,
			      git_path("sharedindex.%s", sha1_to_hex(si->base->sha1)));
	if (!ret) {