			if (tagged->type != OBJ_COMMIT) {
				die ("Tag %s tags unexported %s!",
				     oid_to_hex(&tag->object.oid),
				     type_name(tagged->type));
			}
			p = (struct commit *)tagged;
			for (;;) {