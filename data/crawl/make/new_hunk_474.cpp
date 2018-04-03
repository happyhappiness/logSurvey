	  puts (_("#  Failed to be updated."));
	  break;
	default:
	  puts (_("#  Invalid value in 'update_status' member!"));
	  fflush (stdout);
	  fflush (stderr);
	  abort ();
	}
      break;
    default:
      puts (_("#  Invalid value in 'command_state' member!"));
      fflush (stdout);
      fflush (stderr);
      abort ();
