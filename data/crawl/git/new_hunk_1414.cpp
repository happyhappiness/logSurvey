		 * correct; since there is no true "middle point" between
		 * them, simply reuse the base version for virtual merge base.
		 */
		ret = remove_file_from_cache(path);
		if (!ret)
			ret = update_file(o, 0, o_oid, o_mode,
					  renamed ? renamed : path);
	} else if (!a_oid) {
		if (!renamed) {
			output(o, 1, _("CONFLICT (%s/delete): %s deleted in %s "
			       "and %s in %s. Version %s of %s left in tree."),
			       change, path, o->branch1, change_past,
			       o->branch2, o->branch2, path);
			ret = update_file(o, 0, b_oid, b_mode, path);
		} else {
			output(o, 1, _("CONFLICT (%s/delete): %s deleted in %s "
			       "and %s in %s. Version %s of %s left in tree at %s."),
			       change, path, o->branch1, change_past,
			       o->branch2, o->branch2, path, renamed);
			ret = update_file(o, 0, b_oid, b_mode, renamed);
		}
	} else {
		if (!renamed) {