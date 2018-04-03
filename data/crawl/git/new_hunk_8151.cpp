				    lstat(old_name, &st))
					return -1;
			}
			if (!cached && verify_index_match(ce, &st))
				return error("%s: does not match index",
					     old_name);
			if (cached)
				st_mode = ntohl(ce->ce_mode);
		} else if (stat_ret < 0)
			return error("%s: %s", old_name, strerror(errno));

		if (!cached)
