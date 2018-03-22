	       && gname_to_gid (optarg, &group_option)))
	  {
	    uintmax_t g;
	    if (!check_decimal (optarg, &g) || g != (gid_t) g)
	      ERROR ((TAREXIT_FAILURE, 0, _("Invalid group given on option")));
	    else
	      group_option = g;
	  }
	break;

