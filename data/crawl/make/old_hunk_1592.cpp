  other_args->idx = 1;
  other_args->list[0] = savestring (argv[0], strlen (argv[0]));

  for (i = 1; i < argc; i++)
    {
      sw = argv[i];
      if (*sw++ == '-')
	while (*sw != '\0')
	  {
	    for (cs = switches; cs->c != '\0'; ++cs)
	      if (cs->c == *sw)
		{
		  ++sw;
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
		      if (*sw == '\0')
			{
			  arg = argv[++i];
			  if (arg == 0)
			    {
			      arg = cs->noarg_value;
			      if (arg == 0)
				{
				  error ("argument required for `-%c' option",
					 cs->c);
				  bad = 1;
				  break;
				}
			    }
			}
		      else
			arg = sw;

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
		      sl->list[sl->idx++] = savestring (arg, strlen (arg));
		      sl->list[sl->idx] = 0;
		      sw = "";
		      break;

		    case positive_int:
		      if (*sw == '\0')
			arg = argv[++i];
		      else
			arg = sw;
		      if (arg != 0 && isdigit (*arg))
			{
			  int i = atoi (arg);
			  if (arg == sw)
			    while (isdigit (*sw))
			      ++sw;
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
			{
			  if (cs->noarg_value != 0)
			    *(unsigned int *) cs->value_ptr
			      = *(unsigned int *) cs->noarg_value;
			  else
			    {
			      error ("the `-%c' option requires an argument",
				     cs->c);
			      bad = 1;
			    }

			  if (arg == argv[i])
			    /* We moved to the next arg, so move back.  */
			    --i;
			}
		      break;

		    case floating:
		      if (*sw == '\0')
			arg = argv[++i];
		      else
			arg = sw;
		      if (arg != 0 && (*arg == '.' || isdigit (*arg)))
			{
			  *(double *) cs->value_ptr = atof (arg);
			  if (arg == sw)
			    while (*sw == '.' || isdigit (*sw))
			      ++sw;
			}
		      else
			{
			  if (cs->noarg_value != 0)
			    *(double *) cs->value_ptr
			      = *(double *) cs->noarg_value;
			  else
			    {
			      error ("the `-%c' option requires an argument",
				     cs->c);
			      bad = 1;
			    }

			  if (arg == argv[i])
			    /* We moved to the next arg, so move back.  */
			    --i;
			}
		      break;
		    }

		  /* We've found the switch.  Stop looking.  */
		  break;
		}
		  
	    if (cs->c == '\0')
	      {
		error ("unknown option `-%c'", *sw++);
		bad = 1;
	      }
	  }
      else
	{
	  if (other_args->idx == other_args->max - 1)
	    {
	      other_args->max += 5;
	      other_args->list = (char **)
		xrealloc ((char *) other_args->list,
			  other_args->max * sizeof (char *));
	    }
	  other_args->list[other_args->idx++] = argv[i];
	}
    }

  if (other_args != 0)
    other_args->list[other_args->idx] = 0;

  if (bad)
    die (1);
}

static void
