			 */
			ptr[-42] = ptr[-1] = 0;
			if (add_cacheinfo(mode, sha1, path_name, stage))
				die("git update-index: unable to update %s",
				    path_name);
		}
		continue;
