    case GNUTYPE_LONGNAME:
    case GNUTYPE_LONGLINK:
      ERROR ((0, 0, _("Visible long name error")));
      skip_member ();
      if (backup_option)
	undo_last_backup ();
      break;
