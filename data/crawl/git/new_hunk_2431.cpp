			add_pending_object(revs, object, tag->tag);
		if (!tag->tagged)
			die("bad tag");
		object = parse_object(tag->tagged->oid.hash);
		if (!object) {
			if (flags & UNINTERESTING)
				return NULL;
