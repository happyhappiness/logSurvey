			error("failed to delete %s", name);
			return "failed to delete";
		}
		fprintf(stderr, "%s: %s -> deleted\n", name,
			sha1_to_hex(old_sha1));
		return NULL; /* good */
	}
	else {
