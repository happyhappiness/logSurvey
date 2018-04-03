			output(o, 1, _("CONFLICT (%s): There is a directory with name %s in %s. "
			       "Adding %s as %s"),
			       conf, path, other_branch, path, new_path);
			if (update_file(o, 0, oid, mode, new_path))
				clean_merge = -1;
			else if (o->call_depth)
				remove_file_from_cache(path);
			free(new_path);
		} else {
			output(o, 2, _("Adding %s"), path);
			/* do not overwrite file if already present */
			if (update_file_flags(o, oid, mode, path, 1, !a_oid))
				clean_merge = -1;
		}
	} else if (a_oid && b_oid) {
		/* Case C: Added in both (check for same permissions) and */
		/* case D: Modified in both, but differently. */
		clean_merge = merge_content(o, path,
					    o_oid, o_mode, a_oid, a_mode, b_oid, b_mode,
					    NULL);
	} else if (!o_oid && !a_oid && !b_oid) {
		/*
		 * this entry was deleted altogether. a_mode == 0 means
		 * we had that path and want to actively remove it.
		 */
		remove_file(o, 1, path, !a_mode);
	} else
		die("BUG: fatal merge failure, shouldn't happen.");

	return clean_merge;
}
