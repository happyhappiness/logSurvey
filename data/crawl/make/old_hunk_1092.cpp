	case -1:
	  break;
	case 0:
	  puts ("#  Successfully updated.");
	  break;
	case 1:
	  assert (question_flag);
	  puts ("#  Needs to be updated (-q is set).");
	  break;
	case 2:
	  puts ("#  Failed to be updated.");
	  break;
	default:
	  puts ("#  Invalid value in `update_status' member!");
	  fflush (stdout);
	  fflush (stderr);
	  abort ();
	}
      break;
    default:
      puts ("#  Invalid value in `command_state' member!");
      fflush (stdout);
      fflush (stderr);
      abort ();
