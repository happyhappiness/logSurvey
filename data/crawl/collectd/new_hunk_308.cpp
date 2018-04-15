
		fields_num = strsplit (buffer_copy, fields,
				sizeof (fields) / sizeof (fields[0]));
		if (fields_num < 1)
		{
			fprintf (fhout, "-1 Internal error\n");
			fclose (fhin);
			fclose (fhout);
			pthread_exit ((void *) 1);
		}

		if (strcasecmp (fields[0], "getval") == 0)