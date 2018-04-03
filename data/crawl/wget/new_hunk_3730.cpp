		  break;
		case ST_UNIX:
		case ST_WINNT:
		case ST_MACOS:
		  /* pwd_len == 1 means pwd = "/", but u->dir begins with '/'
		     already */
		  if (pwd_len > 1)
		    strcpy (result, con->id);
		  strcat (result, u->dir);
		  DEBUGP(("\npwd=\"%s\"", con->id));
		  DEBUGP(("\nu->dir=\"%s\"", u->dir));
		  break;
		default:
		  abort ();
