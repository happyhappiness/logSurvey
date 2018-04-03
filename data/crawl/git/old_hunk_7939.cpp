			fprintf(stderr, "\n  from %s\n  to   %s\n",
				old_hex, new_hex);
		}
		if (remote) {
			struct refspec rs;
			rs.src = ref->name;
			rs.dst = NULL;
