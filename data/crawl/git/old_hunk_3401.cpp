			if (sizeof(tmpname) <= strlen(base_name) + 50)
				die("pack base name '%s' too long", base_name);
			snprintf(tmpname, sizeof(tmpname), "%s-", base_name);
			finish_tmp_packfile(tmpname, pack_tmp_name,
					    written_list, nr_written,
					    &pack_idx_opts, sha1);
			free(pack_tmp_name);
			puts(sha1_to_hex(sha1));
		}
