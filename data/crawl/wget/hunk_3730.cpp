 		  break;
 		case ST_UNIX:
 		case ST_WINNT:
+		case ST_MACOS:
 		  /* pwd_len == 1 means pwd = "/", but u->dir begins with '/'
 		     already */
 		  if (pwd_len > 1)
-		    strcpy (result, pwd);
+		    strcpy (result, con->id);
 		  strcat (result, u->dir);
-		  /* These look like debugging messages to me.  */
-#if 0
-		  logprintf (LOG_VERBOSE, "\npwd=\"%s\"", pwd);
-		  logprintf (LOG_VERBOSE, "\nu->dir=\"%s\"", u->dir);
-#endif
+		  DEBUGP(("\npwd=\"%s\"", con->id));
+		  DEBUGP(("\nu->dir=\"%s\"", u->dir));
 		  break;
 		default:
 		  abort ();
