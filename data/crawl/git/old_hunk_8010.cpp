		}

		hashcpy(ref->new_sha1, local);
		if (!verbose)
			continue;
		fprintf(stderr,
			"already have %s (%s)\n", sha1_to_hex(remote),
