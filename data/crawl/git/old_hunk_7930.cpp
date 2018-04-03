			if (rename(idx_tmp_name, tmpname))
				die("unable to rename temporary index file: %s",
				    strerror(errno));
			puts(sha1_to_hex(sha1));
		}

