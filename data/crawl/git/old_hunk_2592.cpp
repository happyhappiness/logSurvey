			add_pending_object(revs, object, tag->tag);
		if (!tag->tagged)
			die("bad tag");
		object = parse_object(tag->tagged->sha1);
		if (!object) {
			if (flags & UNINTERESTING)
				return NULL;
