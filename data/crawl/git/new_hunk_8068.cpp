		if (0 < patch->is_new)
			sha1_ptr = null_sha1;
		else if (get_sha1(patch->old_sha1_prefix, sha1))
			/* git diff has no index line for mode/type changes */
			if (!patch->lines_added && !patch->lines_deleted) {
				if (get_current_sha1(patch->new_name, sha1) ||
				    get_current_sha1(patch->old_name, sha1))
					die("mode change for %s, which is not "
						"in current HEAD", name);
				sha1_ptr = sha1;
			} else
				die("sha1 information is lacking or useless "
					"(%s).", name);
		else
			sha1_ptr = sha1;

