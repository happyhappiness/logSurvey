					  item->string,
					  exts[ext].name);
			if (remove_path(fname))
				warning(_("failed to remove '%s'"), fname);
			free(fname);
		}
	}
