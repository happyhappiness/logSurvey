	}
	else {
		enum object_type type;
		if (size_only)
			type = sha1_object_info(s->sha1, &s->size);
		else {
			s->data = read_sha1_file(s->sha1, &type, &s->size);
			s->should_free = 1;
		}
	}