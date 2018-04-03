  switch (ar_member_touch (arname, memname))
    {
    case -1:
      error (NILF, _("touch: Archive `%s' does not exist"), arname);
      break;
    case -2:
      error (NILF, _("touch: `%s' is not a valid archive"), arname);
      break;
    case -3:
      perror_with_name ("touch: ", arname);
      break;
    case 1:
      error (NILF,
             _("touch: Member `%s' does not exist in `%s'"), memname, arname);
      break;
    case 0:
      val = 0;
      break;
    default:
      error (NILF,
             _("touch: Bad return code from ar_member_touch on `%s'"), name);
    }

  free (arname);
