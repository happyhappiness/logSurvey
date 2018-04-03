		parse_tag_buffer(tag, buffer, size);
		obj = &tag->object;
	} else {
		warning("object %s has unknown type id %d\n", sha1_to_hex(sha1), type);
		obj = NULL;
	}
	if (obj && obj->type == OBJ_NONE)
		obj->type = type;
	*eaten_p = eaten;
	return obj;
}
