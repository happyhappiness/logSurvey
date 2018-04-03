			warning("invalid replace ref %s", refname);
			return 0;
		}
		obj = parse_object(&original_oid);
		if (obj)
			add_name_decoration(DECORATION_GRAFTED, "replaced", obj);
		return 0;
	}

	obj = parse_object(oid);
	if (!obj)
		return 0;

