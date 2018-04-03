			 * to preserve this property.
			 */
			if (stat(pack_tmp_name, &st) < 0) {
				warning("failed to stat %s: %s",
					pack_tmp_name, strerror(errno));
			} else if (!last_mtime) {
				last_mtime = st.st_mtime;
			} else {
				struct utimbuf utb;
				utb.actime = st.st_atime;
				utb.modtime = --last_mtime;
				if (utime(pack_tmp_name, &utb) < 0)
					warning("failed utime() on %s: %s",
						pack_tmp_name, strerror(errno));
			}

			strbuf_addf(&tmpname, "%s-", base_name);