			len--;
		if (args->verbose)
			fprintf(stderr, "%.*s\n", (int)len, args->base);
		err = write_entry(args, get_object_hash(args->tree->object), args->base,
				  len, 040777);
		if (err)
			return err;
