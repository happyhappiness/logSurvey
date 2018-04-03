				 base_name, sha1_to_hex(sha1));
			free_pack_by_name(tmpname);
			if (adjust_perm(pack_tmp_name, mode))
				die_errno("unable to make temporary pack file readable");
			if (rename(pack_tmp_name, tmpname))
				die_errno("unable to rename temporary pack file");

			/*
			 * Packs are runtime accessed in their mtime
