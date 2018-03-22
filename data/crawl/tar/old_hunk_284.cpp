	break;

      case 'p':
	switch (argmatch (optarg, pattern_strings))
	  {

	  case -2:
	    error (0, 0, _("Ambiguous pattern `%s'"), optarg);
	    usage (EXIT_FAILURE);

	  case -1:
	    error (0, 0, _("Unknown pattern `%s'"), optarg);
	    usage (EXIT_FAILURE);

	  case 0:
	    pattern = DEFAULT;
	    break;

	  case 1:
	    pattern = ZEROS;
	    break;
	  }
	break;
      }

