      *fun = extract_volhdr;
      break;

    case GNUTYPE_MULTIVOL:
      ERROR ((0, 0,
	      _("%s: Cannot extract -- file is continued from another volume"),
