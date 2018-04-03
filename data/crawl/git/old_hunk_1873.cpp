	if (delete_redundant && repository_format_precious_objects)
		die(_("cannot delete packs in a precious-objects repo"));

	if (pack_kept_objects < 0)
		pack_kept_objects = write_bitmaps;

