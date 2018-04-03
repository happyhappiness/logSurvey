	}

	if (get_sha1(rev, sha1))
		die(_("Failed to resolve '%s' as a valid ref."), rev);

	commit = lookup_commit_reference(sha1);
	if (!commit)
		die(_("Could not parse object '%s'."), rev);
	hashcpy(sha1, commit->object.sha1);

	if (patch_mode) {
		if (reset_type != NONE)
			die(_("--patch is incompatible with --{hard,mixed,soft}"));
		return interactive_reset(rev, argv + i, prefix);
	}

