		mfi = merge_file(&o, &a, &b,
				 branch1, branch2);

		clean_merge = mfi.clean;
		if (mfi.clean)
			update_file(1, mfi.sha, mfi.mode, path);
		else if (S_ISGITLINK(mfi.mode))
			output(1, "CONFLICT (submodule): Merge conflict in %s "
			       "- needs %s", path, sha1_to_hex(b.sha1));
		else {
			output(1, "CONFLICT (%s): Merge conflict in %s",
					reason, path);
