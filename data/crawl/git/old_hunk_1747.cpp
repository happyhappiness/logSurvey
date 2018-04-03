			entry->processed = 0;
			break;
		}
	} else if (o_sha && (!a_sha || !b_sha)) {
		/* Case A: Deleted in one */
		if ((!a_sha && !b_sha) ||
		    (!b_sha && blob_unchanged(o_sha, o_mode, a_sha, a_mode, normalize, path)) ||
		    (!a_sha && blob_unchanged(o_sha, o_mode, b_sha, b_mode, normalize, path))) {
			/* Deleted in both or deleted in one and
			 * unchanged in the other */
			if (a_sha)
				output(o, 2, _("Removing %s"), path);
			/* do not touch working file if it did not exist */
			remove_file(o, 1, path, !a_sha);
		} else {
			/* Modify/delete; deleted side may have put a directory in the way */
			clean_merge = 0;
			handle_modify_delete(o, path, o_sha, o_mode,
					     a_sha, a_mode, b_sha, b_mode);
		}
	} else if ((!o_sha && a_sha && !b_sha) ||
		   (!o_sha && !a_sha && b_sha)) {
		/* Case B: Added in one. */
		/* [nothing|directory] -> ([nothing|directory], file) */

		const char *add_branch;
		const char *other_branch;
		unsigned mode;
		const unsigned char *sha;
		const char *conf;

		if (a_sha) {
			add_branch = o->branch1;
			other_branch = o->branch2;
			mode = a_mode;
			sha = a_sha;
			conf = _("file/directory");
		} else {
			add_branch = o->branch2;
			other_branch = o->branch1;
			mode = b_mode;
			sha = b_sha;
			conf = _("directory/file");
		}
		if (dir_in_way(path, !o->call_depth)) {