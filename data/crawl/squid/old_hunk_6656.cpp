	    if (parse_menu)
		fputs(munge_menu_line(buf, req), stdout);
	    else
		fputs(buf, stdout);
	    break;
	case isForward:
	    /* forward: no modifications allowed */
