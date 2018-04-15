		}
		else
		{
			fprintf (fh, "-1 Unknown command: %s\n", fields[0]);
			fflush (fh);
		}
	} /* while (fgets) */