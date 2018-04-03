			free(lnk);
		} else
			die(_("do not know what to do with %06o %s '%s'"),
			    mode, sha1_to_hex(sha), path);
		free(buf);
	}
 update_index:
	if (update_cache)
		add_cacheinfo(mode, sha, path, 0, update_wd, ADD_CACHE_OK_TO_ADD);
}

static void update_file(struct merge_options *o,
			int clean,
			const unsigned char *sha,
			unsigned mode,
			const char *path)
{
	update_file_flags(o, sha, mode, path, o->call_depth || clean, !o->call_depth);
}

/* Low level file merging, update and removal */
