  for (i = 0; i < countof (tests_succ); i++)
    {
      int ind;
      const char *data = tests_succ[i].data;
      const char **expected = tests_succ[i].results;
      struct cookie *c;

      c = parse_set_cookie (data, true);
      if (!c)
	{
	  printf ("NULL cookie returned for valid data: %s\n", data);
	  continue;
	}

      /* Test whether extract_param handles these cases correctly. */
      {
	param_token name, value;
	const char *ptr = data;
	int j = 0;
	while (extract_param (&ptr, &name, &value))
	  {
	    char *n = strdupdelim (name.b, name.e);
	    char *v = strdupdelim (value.b, value.e);
	    if (!expected[j])
	      {
		printf ("Too many parameters for '%s'\n", data);
		break;
	      }
	    if (0 != strcmp (expected[j], n))
	      printf ("Invalid name %d for '%s' (expected '%s', got '%s')\n",
		      j / 2 + 1, data, expected[j], n);
	    if (0 != strcmp (expected[j + 1], v))
	      printf ("Invalid value %d for '%s' (expected '%s', got '%s')\n",
		      j / 2 + 1, data, expected[j + 1], v);
	    j += 2;
	    free (n);
	    free (v);
	  }
	if (expected[j])
	  printf ("Too few parameters for '%s'\n", data);
      }
    }

  for (i = 0; i < countof (tests_fail); i++)
    {
      struct cookie *c;
      char *data = tests_fail[i];
      c = parse_set_cookie (data, true);
      if (c)
	printf ("Failed to report error on invalid data: %s\n", data);
    }
