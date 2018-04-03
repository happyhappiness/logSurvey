    case cs_finished:
      switch (f->update_status)
        {
        case -1:
          break;
        case 0:
          puts (_("#  Successfully updated."));
          break;
        case 1:
          assert (question_flag);
          puts (_("#  Needs to be updated (-q is set)."));
          break;
        case 2:
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
