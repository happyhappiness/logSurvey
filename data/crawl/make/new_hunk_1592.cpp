  other_args->idx = 1;
  other_args->list[0] = savestring (argv[0], strlen (argv[0]));

  /* Fill in the string and vector for getopt.  */
  p = options;
  *p++ = '-';			/* Non-option args are returned in order.  */
  for (i = 0; switches[i].c != '\0'; ++i)
    {
      long_options[i].name = switches[i].long_name;
      *p++ = switches[i].c;
      switch (switches[i].type)
	{
	case flag:
	case flag_off:
	case ignore:
	  long_options[i].has_arg = no_argument;
	  break;

	case string:
	case positive_int:
	case floating:
	  *p++ = ':';
	  if (switches[i].noarg_value != 0)
	    {
	      *p++ = ':';
	      long_options[i].has_arg = optional_argument;
	    }
	  else
	    long_options[i].has_arg = required_argument;
	  break;
	}
    }
  *p = '\0';
  long_options[i].name = 0;

  /* getopt does most of the parsing for us.  */
  while ((c = getopt_long (argc, argv,
			   options, long_options, (int *) 0)) != EOF)
    {
      if (c == '?')
	/* Bad option.  We will print a usage message and die later.
	   But continue to parse the other options so the user can
	   see all he did wrong.  */
	bad = 1;
      else if (c == 1)
	{
	  /* This is a non-option argument.  */
	  if (other_args->idx == other_args->max - 1)
	    {
	      other_args->max += 5;
	      other_args->list = (char **)
		xrealloc ((char *) other_args->list,
			  other_args->max * sizeof (char *));
	    }
	  other_args->list[other_args->idx++] = optarg;
	}
      else
	for (cs = switches; cs->c != '\0'; ++cs)
	  {
	    if (cs->c == c)
	      switch (cs->type)
		{
		default:
		  abort ();

		case ignore:
		  break;

		case flag:
		case flag_off:
		  *(int *) cs->value_ptr = cs->type == flag;
		  break;

		case string:
		  if (optarg == 0)
		    optarg = cs->noarg_value;

		  sl = *(struct stringlist **) cs->value_ptr;
		  if (sl == 0)
		    {
		      sl = (struct stringlist *)
			xmalloc (sizeof (struct stringlist));
		      sl->max = 5;
		      sl->idx = 0;
		      sl->list = (char **) xmalloc (5 * sizeof (char *));
		      *(struct stringlist **) cs->value_ptr = sl;
		    }
		  else if (sl->idx == sl->max - 1)
		    {
		      sl->max += 5;
		      sl->list = (char **)
			xrealloc ((char *) sl->list,
				  sl->max * sizeof (char *));
		    }
		  sl->list[sl->idx++] = savestring (optarg, strlen (optarg));
		  sl->list[sl->idx] = 0;
		  break;

		case positive_int:
		  if (optarg != 0)
		    {
		      int i = atoi (optarg);
		      if (i < 1)
			{
			  error ("the `-%c' option requires a \
positive integral argument",
				 cs->c);
			  bad = 1;
			}
		      else
			*(unsigned int *) cs->value_ptr = i;
		    }
		  else
		    *(unsigned int *) cs->value_ptr
		      = *(unsigned int *) cs->noarg_value;
		  break;

		case floating:
		  if (optarg != 0)
		    *(double *) cs->value_ptr = atof (optarg);
		  else
		    *(double *) cs->value_ptr = *(double *) cs->noarg_value;
		  break;
		}
	    
	    /* We've found the switch.  Stop looking.  */
	    break;
	  }
    }

  if (other_args != 0)
    other_args->list[other_args->idx] = 0;

  if (bad)
    {
      /* Print a nice usage message.  */
      fprintf (stderr, "Usage: %s [options] [target] ...\n", program);
      fputs ("Options:\n", stderr);
      for (cs = switches; cs->c != '\0'; ++cs)
	{
	  char buf[100], arg[50];

	  switch (long_options[cs - switches].has_arg)
	    {
	    case no_argument:
	      arg[0] = '\0';
	      break;
	    case required_argument:
	      sprintf (arg, " %s", cs->argdesc);
	      break;
	    case optional_argument:
	      sprintf (arg, " [%s]", cs->argdesc);
	      break;
	    }

	  if (cs->long_name == 0)
	    sprintf (buf, "  -%c%s",
		     cs->c, arg);
	  else
	    sprintf (buf, "  -%c%s, --%s%s",
		     cs->c, arg,
		     cs->long_name, arg);

	  if (strlen (buf) >= 30)
	    {
	      fprintf (stderr, "%s\n", buf);
	      buf[0] = '\0';
	    }

	  fprintf (stderr, "%-30s%s.\n", buf, cs->description);
	}

      die (1);
    }
}

static void
