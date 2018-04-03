			else
				mode = 0666;
			fd = open(path, O_WRONLY | O_TRUNC | O_CREAT, mode);
			if (fd < 0)
				die_errno(_("failed to open '%s'"), path);
			write_in_full(fd, buf, size);
			close(fd);
		} else if (S_ISLNK(mode)) {
			char *lnk = xmemdupz(buf, size);
			safe_create_leading_directories_const(path);
			unlink(path);
			if (symlink(lnk, path))
				die_errno(_("failed to symlink '%s'"), path);
			free(lnk);
		} else
			die(_("do not know what to do with %06o %s '%s'"),
			    mode, oid_to_hex(oid), path);
 free_buf:
		free(buf);
	}
 update_index:
	if (update_cache)
		add_cacheinfo(mode, oid, path, 0, update_wd, ADD_CACHE_OK_TO_ADD);
	return 0;
}

static int update_file(struct merge_options *o,
