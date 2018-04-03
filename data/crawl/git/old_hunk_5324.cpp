{
	if (has_symlink_or_noent_leading_path(ce->name, ce_namelen(ce)))
		return;
	if (S_ISGITLINK(ce->ce_mode)) {
		if (rmdir(ce->name)) {
			warning("unable to rmdir %s: %s",
				ce->name, strerror(errno));
			return;
		}
	}
	else
		if (unlink_or_warn(ce->name))
			return;
	schedule_dir_for_removal(ce->name, ce_namelen(ce));
}

