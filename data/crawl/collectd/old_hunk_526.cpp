
		/* The `%.*s' is needed because there is no null-byte behind
		 * the name. */
		fprintf(log, ",%.*s", (tmp - name), name);
	}
	fprintf(log, "\n");
	fclose(log);
