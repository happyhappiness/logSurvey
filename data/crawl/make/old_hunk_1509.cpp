      unblock_sigs ();
      break;

    case cs_finished:
      notice_finished_file (c->file);
      free_child (c);
      break;

    default:
      error ("internal error: `%s' command_state == %d in new_job",
	     c->file->name, (int) c->file->command_state);
      abort ();
      break;
    }

