		else
			packet_write(out, "%s %s %s",
				     old_hex, new_hex, ref->name);
		if (will_delete_ref)
			fprintf(stderr, "deleting '%s'\n", ref->name);
		else {
			fprintf(stderr, "updating '%s'", ref->name);
