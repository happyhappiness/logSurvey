	       && uname_to_uid (optarg, &owner_option)))
	  {
	    uintmax_t u;
	    if (!check_decimal (optarg, &u) || u != (uid_t) u)
	      ERROR ((TAREXIT_FAILURE, 0, _("Invalid owner given on option")));
	    else
	      owner_option = u;
	  }
	break;

