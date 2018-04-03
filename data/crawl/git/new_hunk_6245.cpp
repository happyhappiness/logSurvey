				 o->branch1, o->branch2);

		clean_merge = mfi.clean;
		if (!mfi.clean) {
			if (S_ISGITLINK(mfi.mode))
				reason = "submodule";
			output(o, 1, "CONFLICT (%s): Merge conflict in %s",
					reason, path);
		}
		update_file(o, mfi.clean, mfi.sha, mfi.mode, path);
	} else if (!o_sha && !a_sha && !b_sha) {
		/*
		 * this entry was deleted altogether. a_mode == 0 means
