		  break;
		case ST_UNIX:
		case ST_WINNT:
		  /* pwd_len == 1 means pwd = "/", but u->dir begins with '/'
		     already */
		  if (pwd_len > 1)
		    strcpy (result, pwd);
		  strcat (result, u->dir);
		  /* These look like debugging messages to me.  */
#if 0
		  logprintf (LOG_VERBOSE, "\npwd=\"%s\"", pwd);
		  logprintf (LOG_VERBOSE, "\nu->dir=\"%s\"", u->dir);
#endif
		  break;
		default:
		  abort ();
