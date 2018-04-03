			add_pending_object(revs, object, tag->tag);
		if (!tag->tagged)
			die("bad tag");
		object = parse_object(get_object_hash(*tag->tagged));
		if (!object) {
			if (flags & UNINTERESTING)
				return NULL;
