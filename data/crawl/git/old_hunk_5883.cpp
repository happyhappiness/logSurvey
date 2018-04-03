				 base_name, sha1_to_hex(sha1));
			free_pack_by_name(tmpname);
			if (adjust_perm(pack_tmp_name, mode))
				die("unable to make temporary pack file readable: %s",
				    strerror(errno));
			if (rename(pack_tmp_name, tmpname))
				die("unable to rename temporary pack file: %s",
				    strerror(errno));

			/*
			 * Packs are runtime accessed in their mtime
