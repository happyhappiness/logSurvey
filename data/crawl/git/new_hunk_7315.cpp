			if (rename(pack_tmp_name, tmpname))
				die("unable to rename temporary pack file: %s",
				    strerror(errno));

			/*
			 * Packs are runtime accessed in their mtime
			 * order since newer packs are more likely to contain
			 * younger objects.  So if we are creating multiple
			 * packs then we should modify the mtime of later ones
			 * to preserve this property.
			 */
			if (stat(tmpname, &st) < 0) {
				warning("failed to stat %s: %s",
					tmpname, strerror(errno));
			} else if (!last_mtime) {
				last_mtime = st.st_mtime;
			} else {
				struct utimbuf utb;
				utb.actime = st.st_atime;
				utb.modtime = --last_mtime;
				if (utime(tmpname, &utb) < 0)
					warning("failed utime() on %s: %s",
						tmpname, strerror(errno));
			}

			snprintf(tmpname, sizeof(tmpname), "%s-%s.idx",
				 base_name, sha1_to_hex(sha1));
			if (adjust_perm(idx_tmp_name, mode))
