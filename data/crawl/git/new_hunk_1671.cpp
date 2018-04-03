		 */
		remove_file(o, 1, path, !a_mode);
	} else
		die(_("BUG: fatal merge failure, shouldn't happen."));

	return clean_merge;
}
