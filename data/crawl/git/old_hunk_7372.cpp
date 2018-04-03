			die("SHA1 COLLISION FOUND WITH %s !", sha1_to_hex(sha1));
		free(has_data);
	}
}

static void resolve_delta(struct object_entry *delta_obj, void *base_data,
