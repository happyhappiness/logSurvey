	case GNUTYPE_LONGNAME:
	case GNUTYPE_LONGLINK:
	  modes[0] = 'L';
	  ERROR ((0, 0, _("Visible longname error")));
	  break;

	case GNUTYPE_SPARSE:
