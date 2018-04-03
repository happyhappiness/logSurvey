		if (!get_sha1(arg, sha1)) {
			struct object *object = parse_object(sha1);
			if (!object)
				die(_("bad object %s"), arg);
			add_object_array(object, arg, &list);
			continue;
		}
