			ret = -4;
	}

	if (!new_refs && ret == 0)
		fprintf(stderr, "Everything up-to-date\n");
	return ret;