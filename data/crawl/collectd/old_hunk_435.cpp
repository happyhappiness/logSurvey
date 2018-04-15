	if (fh == NULL)
	{
			char errbuf[1024];
			fprintf (stderr, "stderr plugin: fopen (%s) failed: %s\n",
					(log_file == NULL) ? "<null>" : log_file,
					sstrerror (errno, errbuf, sizeof (errbuf)));
	}
