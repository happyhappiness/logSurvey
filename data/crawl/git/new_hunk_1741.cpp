		 * again later for the non-recursive merge.
		 */
		remove_file(o, 0, path, 0);
		update_file(o, 0, &mfi_c1.oid, mfi_c1.mode, a->path);
		update_file(o, 0, &mfi_c2.oid, mfi_c2.mode, b->path);
	} else {
		char *new_path1 = unique_path(o, path, ci->branch1);
		char *new_path2 = unique_path(o, path, ci->branch2);
		output(o, 1, _("Renaming %s to %s and %s to %s instead"),
		       a->path, new_path1, b->path, new_path2);
		remove_file(o, 0, path, 0);
		update_file(o, 0, &mfi_c1.oid, mfi_c1.mode, new_path1);
		update_file(o, 0, &mfi_c2.oid, mfi_c2.mode, new_path2);
		free(new_path2);
		free(new_path1);
	}
