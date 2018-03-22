      break;

    case GNUTYPE_MULTIVOL:
      ERROR ((0, 0, _("\
Cannot extract `%s' -- file is continued from another volume"),
	      current_file_name));
      skip_file (current_stat.st_size);
      if (backup_option)
