		}
		new_path = unique_path(o, path, rename_conflict_info->branch1);
		output(o, 1, _("Adding as %s instead"), new_path);
		update_file(o, 0, mfi.oid.hash, mfi.mode, new_path);
		free(new_path);
		mfi.clean = 0;
	} else {
		update_file(o, mfi.clean, mfi.oid.hash, mfi.mode, path);
	}
	return mfi.clean;

