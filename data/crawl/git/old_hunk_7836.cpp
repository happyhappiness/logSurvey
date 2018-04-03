					old_hex, new_hex, ref->name);
		}
		if (will_delete_ref)
			fprintf(stderr, "deleting '%s'\n", ref->name);
		else {
			fprintf(stderr, "updating '%s'", ref->name);
			if (strcmp(ref->name, ref->peer_ref->name))
				fprintf(stderr, " using '%s'",
					ref->peer_ref->name);
			fprintf(stderr, "\n  from %s\n  to   %s\n",
				old_hex, new_hex);
		}
	}

