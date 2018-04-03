		if (!object) {
			if (flags & UNINTERESTING)
				return NULL;
			die("bad object %s", sha1_to_hex(tag->tagged->sha1));
		}
		object->flags |= flags;
		/*
