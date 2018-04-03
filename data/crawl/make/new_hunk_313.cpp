    case cs_finished:
      switch (f->update_status)
        {
        case us_none:
          break;
        case us_success:
          puts (_("#  Successfully updated."));
          break;
        case us_question:
          assert (question_flag);
          puts (_("#  Needs to be updated (-q is set)."));
          break;
        case us_failed:
          puts (_("#  Failed to be updated."));
          break;
        }
      break;
    default:
