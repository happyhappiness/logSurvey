		return (1);
	}

	fprintf (fh, "%d\n", getpid());
	fclose(fh);

	return (0);
