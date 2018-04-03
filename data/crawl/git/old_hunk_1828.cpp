					  item->string,
					  exts[ext].name);
			if (remove_path(fname))
				warning(_("removing '%s' failed"), fname);
			free(fname);
		}
	}