	}
	else
	{
		fprintf (fh, "%s\n", msg);
		if (do_close != 0)
			fclose (fh);
	}