      unblock_sigs ();
      break;

    case cs_not_started:
      /* All the command lines turned out to be empty.  */
      c->file->update_status = 0;
      /* FALLTHROUGH */

    case cs_finished:
      notice_finished_file (c->file);
      free_child (c);
      break;

    default:
      assert (c->file->command_state == cs_finished);
      break;
    }

