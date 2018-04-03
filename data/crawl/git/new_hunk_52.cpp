		if (!quiet)
			error("object %s is a %s, not a %s",
			      oid_to_hex(&obj->oid),
			      type_name(obj->type), type_name(type));
		return NULL;
	}
}
