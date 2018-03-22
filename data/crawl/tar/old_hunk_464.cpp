
      case GROUP_OPTION:
	if (!gname_to_gid (optarg, &group_option))
	  if (!check_decimal (optarg) >= 0)
	    ERROR ((TAREXIT_FAILURE, 0, _("Invalid group given on option")));
	  else
	    group_option = check_decimal (optarg);
	break;

      case MODE_OPTION:
