			if (rename(pack_tmp_name, tmpname))
				die("unable to rename temporary pack file: %s",
				    strerror(errno));
			snprintf(tmpname, sizeof(tmpname), "%s-%s.idx",
				 base_name, sha1_to_hex(sha1));
			if (adjust_perm(idx_tmp_name, mode))
