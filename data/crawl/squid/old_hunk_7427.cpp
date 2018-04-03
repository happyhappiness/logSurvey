		    p_state = 1;
		    for (s = reserve; *s; s++)
			switch (*s) {
			case '<': printf("&lt;");  break;
			case '&': printf("&amp;"); break;
			default:  putchar(*s);     break;
			}
		    break;
		case INFO:
