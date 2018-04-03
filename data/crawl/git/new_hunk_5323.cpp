			die("unable to remove %s from index", patch->old_name);
	}
	if (!cached) {
		if (!remove_or_warn(patch->old_mode, patch->old_name) && rmdir_empty) {
			remove_path(patch->old_name);
		}
	}
