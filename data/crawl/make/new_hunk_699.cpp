      break;

    default:
      fatal (*expanding_var, "Internal error: func_error: '%s'", funcname);
  }

  /* The warning function expands to the empty string.  */
