		return (1);
	}

	fprintf (fh, "%i\n", (int) getpid ());
	fclose(fh);

	return (0);
