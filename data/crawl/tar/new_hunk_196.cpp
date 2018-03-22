    case V7_FORMAT:			/* old V7 tar format */
    case USTAR_FORMAT:
    case STAR_FORMAT:
      ERROR ((0, 0,
	      _("%s: link name is too long; not dumped"),
	      quotearg_colon (st->link_name)));
      break;

    case OLDGNU_FORMAT:
    case GNU_FORMAT:
