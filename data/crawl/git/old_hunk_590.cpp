						ADD_CACHE_JUST_APPEND);

				add_path(&rdir, rdir_len, dst_path);
				if (ensure_leading_directories(rdir.buf))
					return error("could not create "
						     "directory for '%s'",
						     dst_path);
				add_path(&wtdir, wtdir_len, dst_path);
				if (symlinks) {
					if (symlink(wtdir.buf, rdir.buf)) {
