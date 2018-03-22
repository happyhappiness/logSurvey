
      case OWNER_OPTION:
	if (!uname_to_uid (optarg, &owner_option))
	  if (!check_decimal (optarg) >= 0)
	    ERROR ((TAREXIT_FAILURE, 0, _("Invalid owner given on option")));
	  else
	    owner_option = check_decimal (optarg);
	break;

      case POSIX_OPTION:
