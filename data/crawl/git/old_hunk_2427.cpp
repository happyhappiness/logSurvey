
			if (!tag->tagged)
				die("bad tag");
			object = parse_object_or_die(get_object_hash(*tag->tagged), NULL);
		}

		if (object->flags & UNINTERESTING)
