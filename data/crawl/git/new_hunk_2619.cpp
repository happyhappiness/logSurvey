		if (!(*list)->next || cmp < 0) {
			struct ref *next = alloc_ref(buffer + 41);
			buffer[40] = '\0';
			if (get_oid_hex(buffer, &next->old_oid)) {
				warning ("invalid SHA-1: %s", buffer);
				free(next);
				continue;
