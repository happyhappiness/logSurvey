			return (-1);
		}

		if (i != 0)
			fprintf (log, ":");
		fprintf(log, "%.*s", (tmp - name), name);
	}
	fprintf(log, "\n");
	fclose(log);
