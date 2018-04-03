				 strcmp(options->single_follow, p->two->path))
				continue; /* not interested */
			else if (!DIFF_OPT_TST(options, RENAME_EMPTY) &&
				 is_empty_blob_sha1(p->two->oid.hash))
				continue;
			else if (add_rename_dst(p->two) < 0) {
				warning("skipping rename detection, detected"
