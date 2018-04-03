	if (!dir->untracked)
		dir->unmanaged_exclude_files++;
	el = add_exclude_list(dir, EXC_FILE, fname);
	if (add_excludes(fname, "", 0, el, NULL, oid_stat) < 0)
		die("cannot use %s as an exclude file", fname);
}

