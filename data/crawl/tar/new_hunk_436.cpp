	       && gname_to_gid (optarg, &group_option)))
	  {
	    uintmax_t g;
	    if (xstrtoumax (optarg, (char **) 0, 10, &g, "") == LONGINT_OK
		&& g == (gid_t) g)
	      group_option = g;
	    else
	      ERROR ((TAREXIT_FAILURE, 0, _("Invalid group given on option")));
	  }
	break;

