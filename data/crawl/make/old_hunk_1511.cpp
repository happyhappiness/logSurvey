    case 0:
      DEBUGPR ("Successfully remade target file `%s'.\n");
      break;
    case -1:
      error ("internal error: `%s' update_status is -1 at cs_finished!",
	     file->name);
      abort ();
    default:
      error ("internal error: `%s' update_status invalid!", file->name);
      abort ();
    }

  file->updated = 1;
