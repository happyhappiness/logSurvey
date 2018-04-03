		parse_tag_buffer(tag, buffer, size);
		obj = &tag->object;
	} else {
		obj = NULL;
	}
	*eaten_p = eaten;
	return obj;
}
