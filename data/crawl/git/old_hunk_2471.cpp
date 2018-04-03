		int type = sha1_object_info(get_object_hash(*obj), &size);
		if (type <= 0)
			die(_("did not receive expected object %s"),
			      sha1_to_hex(obj->sha1));
		if (type != obj->type)
			die(_("object %s: expected type %s, found %s"),
			    sha1_to_hex(obj->sha1),
			    typename(obj->type), typename(type));
		obj->flags |= FLAG_CHECKED;
		return 1;
