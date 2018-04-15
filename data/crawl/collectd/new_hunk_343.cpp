			if (tmp_alloc == NULL)
			{
				fprintf (stderr, "rrdtool: realloc failed.\n");
				ERROR ("rrdtool: realloc failed.\n");
				free (value_copy);
				return (1);
			}
