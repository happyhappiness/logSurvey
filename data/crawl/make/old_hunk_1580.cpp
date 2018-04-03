	  return 0;

	default:
	  error ("internal error: `%s' command_state == %d in update_file_1",
		 f->name, (int) f->command_state);
	  abort ();
	  break;
