		printf("<PRE>\n");
	    }
	    istate = isBody;
	    break;
	case isBody:
	    /* interpret [and reformat] cache response */
	    if (parse_menu)