		struct tag *tag = (struct tag *) object;
		if (revs->tag_objects && !(flags & UNINTERESTING))
			add_pending_object(revs, object, tag->tag);
		object = parse_object(tag->tagged->sha1);
		if (!object)
			die("bad object %s", sha1_to_hex(tag->tagged->sha1));
