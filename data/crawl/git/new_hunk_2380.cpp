			len--;
		if (args->verbose)
			fprintf(stderr, "%.*s\n", (int)len, args->base);
		err = write_entry(args, args->tree->object.oid.hash, args->base,
				  len, 040777);
		if (err)
			return err;