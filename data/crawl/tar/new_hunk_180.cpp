
    case GNUTYPE_LONGNAME:
    case GNUTYPE_LONGLINK:
      ERROR ((0, 0, _("Unexpected long name header")));
      skip_member ();
      if (backup_option)
	undo_last_backup ();
