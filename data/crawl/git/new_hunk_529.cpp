			error("sha1 mismatch %s", sha1_to_hex(repl));
			return NULL;
		}
		parse_blob_buffer(lookup_blob(oid.hash), NULL, 0);
		return lookup_object(sha1);
	}
