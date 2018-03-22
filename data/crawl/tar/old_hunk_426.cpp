	  = mode_compile (optarg,
			  MODE_MASK_EQUALS | MODE_MASK_PLUS | MODE_MASK_MINUS);
	if (mode_option == MODE_INVALID)
	  ERROR ((TAREXIT_FAILURE, 0, _("Invalid mode given on option")));
	if (mode_option == MODE_MEMORY_EXHAUSTED)
	  ERROR ((TAREXIT_FAILURE, 0, _("Memory exhausted")));
	break;

      case NO_RECURSE_OPTION:
