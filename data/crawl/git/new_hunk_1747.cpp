			entry->processed = 0;
			break;
		}
	} else if (o_oid && (!a_oid || !b_oid)) {
		/* Case A: Deleted in one */
		if ((!a_oid && !b_oid) ||
		    (!b_oid && blob_unchanged(o_oid, o_mode, a_oid, a_mode, normalize, path)) ||
		    (!a_oid && blob_unchanged(o_oid, o_mode, b_oid, b_mode, normalize, path))) {
			/* Deleted in both or deleted in one and
			 * unchanged in the other */
			if (a_oid)
				output(o, 2, _("Removing %s"), path);
			/* do not touch working file if it did not exist */
			remove_file(o, 1, path, !a_oid);
		} else {
			/* Modify/delete; deleted side may have put a directory in the way */
			clean_merge = 0;
			handle_modify_delete(o, path, o_oid, o_mode,
					     a_oid, a_mode, b_oid, b_mode);
		}
	} else if ((!o_oid && a_oid && !b_oid) ||
		   (!o_oid && !a_oid && b_oid)) {
		/* Case B: Added in one. */
		/* [nothing|directory] -> ([nothing|directory], file) */

		const char *add_branch;
		const char *other_branch;
		unsigned mode;
		const struct object_id *oid;
		const char *conf;

		if (a_oid) {
			add_branch = o->branch1;
			other_branch = o->branch2;
			mode = a_mode;
			oid = a_oid;
			conf = _("file/directory");
		} else {
			add_branch = o->branch2;
			other_branch = o->branch1;
			mode = b_mode;
			oid = b_oid;
			conf = _("directory/file");
		}
		if (dir_in_way(path, !o->call_depth)) {
