				 o->branch1, o->branch2);

		clean_merge = mfi.clean;
		if (mfi.clean)
			update_file(o, 1, mfi.sha, mfi.mode, path);
		else if (S_ISGITLINK(mfi.mode))
			output(o, 1, "CONFLICT (submodule): Merge conflict in %s "
			       "- needs %s", path, sha1_to_hex(b.sha1));
		else {
			output(o, 1, "CONFLICT (%s): Merge conflict in %s",
					reason, path);

			if (o->call_depth)
				update_file(o, 0, mfi.sha, mfi.mode, path);
			else
				update_file_flags(o, mfi.sha, mfi.mode, path,
					      0 /* update_cache */, 1 /* update_working_directory */);
		}
	} else if (!o_sha && !a_sha && !b_sha) {
		/*
		 * this entry was deleted altogether. a_mode == 0 means