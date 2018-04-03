		}
		else
		{
			fprintf (fh, "Unknown command: %s\n", fields[0]);
			fflush (fh);
		}
	} /* while (fgets) */