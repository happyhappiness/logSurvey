		get_patch_ids(&rev, &ids);
	}

	if (prepare_revision_walk(&rev))
		die(_("revision walk setup failed"));
	rev.boundary = 1;
