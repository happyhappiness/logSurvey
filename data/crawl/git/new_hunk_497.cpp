		const char *name = entry->name;
		int flags = (obj->flags & UNINTERESTING);
		if (!obj->parsed)
			obj = parse_object(&obj->oid);
		obj = deref_tag(obj, NULL, 0);
		if (!obj)
			die(_("invalid object '%s' given."), name);
