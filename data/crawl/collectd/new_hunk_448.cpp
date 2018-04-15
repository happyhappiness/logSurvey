		{
			fprintf (stderr, "Cannot compile regex %s: %i/%s",
					entry, rcompile, regerr);
			ERROR ("Cannot compile regex %s: %i/%s",
					entry, rcompile, regerr);
		}
		else
		{
			fprintf (stderr, "Cannot compile regex %s: %i",
					entry, rcompile);
			ERROR ("Cannot compile regex %s: %i",
					entry, rcompile);
		}

