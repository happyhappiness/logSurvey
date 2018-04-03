		const char *name = *argv++;

		if (!get_sha1(name, sha1)) {
			struct object *object = parse_object(sha1);
			if (!object)
				die("bad object: %s", name);
			add_pending_object(&revs, object, "");
		}
		else
