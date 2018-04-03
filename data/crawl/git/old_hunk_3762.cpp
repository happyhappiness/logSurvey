		unsigned char sha1[20];
		/* Is it a rev? */
		if (!get_sha1(arg, sha1)) {
			struct object *object = parse_object(sha1);
			if (!object)
				die(_("bad object %s"), arg);
			if (!seen_dashdash)
				verify_non_filename(prefix, arg);
			add_object_array(object, arg, &list);
