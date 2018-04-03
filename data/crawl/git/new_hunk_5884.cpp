			snprintf(tmpname, sizeof(tmpname), "%s-%s.idx",
				 base_name, sha1_to_hex(sha1));
			if (adjust_perm(idx_tmp_name, mode))
				die_errno("unable to make temporary index file readable");
			if (rename(idx_tmp_name, tmpname))
				die_errno("unable to rename temporary index file");

			free(idx_tmp_name);
			free(pack_tmp_name);
