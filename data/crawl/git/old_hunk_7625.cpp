		mfi = merge_file(&o, &a, &b,
				 branch1, branch2);

		if (mfi.clean)
			update_file(1, mfi.sha, mfi.mode, path);
		else {
			clean_merge = 0;
			output(1, "CONFLICT (%s): Merge conflict in %s",
					reason, path);
