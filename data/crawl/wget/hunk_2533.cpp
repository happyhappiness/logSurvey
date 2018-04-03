   if ((cmd & DO_RETR) && *len == 0)
     {
       if (opt.verbose)
-	{
+        {
           if (!opt.server_response)
-	    logprintf (LOG_VERBOSE, "==> SIZE %s ... ", escnonprint (u->file));
-	}
+            logprintf (LOG_VERBOSE, "==> SIZE %s ... ", escnonprint (u->file));
+        }
 
       err = ftp_size (csock, u->file, len);
       /* FTPRERR */
       switch (err)
-	{
-	case FTPRERR:
-	case FTPSRVERR:
-	  logputs (LOG_VERBOSE, "\n");
-	  logputs (LOG_NOTQUIET, _("\
+        {
+        case FTPRERR:
+        case FTPSRVERR:
+          logputs (LOG_VERBOSE, "\n");
+          logputs (LOG_NOTQUIET, _("\
 Error in server response, closing control connection.\n"));
-	  fd_close (csock);
-	  con->csock = -1;
-	  return err;
-	case FTPOK:
-	  /* Everything is OK.  */
-	  break;
-	default:
-	  abort ();
-	}
-	if (!opt.server_response)
-	  logprintf (LOG_VERBOSE, *len ? "%s\n" : _("done.\n"),
-		     number_to_static_string (*len));
+          fd_close (csock);
+          con->csock = -1;
+          return err;
+        case FTPOK:
+          /* Everything is OK.  */
+          break;
+        default:
+          abort ();
+        }
+        if (!opt.server_response)
+          logprintf (LOG_VERBOSE, *len ? "%s\n" : _("done.\n"),
+                     number_to_static_string (*len));
     }
 
   /* If anything is to be retrieved, PORT (or PASV) must be sent.  */
   if (cmd & (DO_LIST | DO_RETR))
     {
       if (opt.ftp_pasv)
-	{
-  	  ip_address passive_addr;
-  	  int        passive_port;
-	  err = ftp_do_pasv (csock, &passive_addr, &passive_port);
-	  /* FTPRERR, WRITEFAILED, FTPNOPASV, FTPINVPASV */
-	  switch (err)
-	    {
-	    case FTPRERR:
-	      logputs (LOG_VERBOSE, "\n");
-	      logputs (LOG_NOTQUIET, _("\
+        {
+          ip_address passive_addr;
+          int        passive_port;
+          err = ftp_do_pasv (csock, &passive_addr, &passive_port);
+          /* FTPRERR, WRITEFAILED, FTPNOPASV, FTPINVPASV */
+          switch (err)
+            {
+            case FTPRERR:
+              logputs (LOG_VERBOSE, "\n");
+              logputs (LOG_NOTQUIET, _("\
 Error in server response, closing control connection.\n"));
-	      fd_close (csock);
-	      con->csock = -1;
-	      return err;
-	    case WRITEFAILED:
-	      logputs (LOG_VERBOSE, "\n");
-	      logputs (LOG_NOTQUIET,
-		       _("Write failed, closing control connection.\n"));
-	      fd_close (csock);
-	      con->csock = -1;
-	      return err;
-	    case FTPNOPASV:
-	      logputs (LOG_VERBOSE, "\n");
-	      logputs (LOG_NOTQUIET, _("Cannot initiate PASV transfer.\n"));
-	      break;
-	    case FTPINVPASV:
-	      logputs (LOG_VERBOSE, "\n");
-	      logputs (LOG_NOTQUIET, _("Cannot parse PASV response.\n"));
-	      break;
-	    case FTPOK:
-	      break;
-	    default:
-	      abort ();
-	    }	/* switch (err) */
-	  if (err==FTPOK)
-	    {
-	      DEBUGP (("trying to connect to %s port %d\n", 
-		      print_address (&passive_addr), passive_port));
-	      dtsock = connect_to_ip (&passive_addr, passive_port, NULL);
-	      if (dtsock < 0)
-		{
-		  int save_errno = errno;
-		  fd_close (csock);
-		  con->csock = -1;
-		  logprintf (LOG_VERBOSE, _("couldn't connect to %s port %d: %s\n"),
-			     print_address (&passive_addr), passive_port,
-			     strerror (save_errno));
-		  return (retryable_socket_connect_error (save_errno)
-			  ? CONERROR : CONIMPOSSIBLE);
-		}
-
-	      pasv_mode_open = true;  /* Flag to avoid accept port */
-	      if (!opt.server_response)
-		logputs (LOG_VERBOSE, _("done.    "));
-	    } /* err==FTP_OK */
-	}
+              fd_close (csock);
+              con->csock = -1;
+              return err;
+            case WRITEFAILED:
+              logputs (LOG_VERBOSE, "\n");
+              logputs (LOG_NOTQUIET,
+                       _("Write failed, closing control connection.\n"));
+              fd_close (csock);
+              con->csock = -1;
+              return err;
+            case FTPNOPASV:
+              logputs (LOG_VERBOSE, "\n");
+              logputs (LOG_NOTQUIET, _("Cannot initiate PASV transfer.\n"));
+              break;
+            case FTPINVPASV:
+              logputs (LOG_VERBOSE, "\n");
+              logputs (LOG_NOTQUIET, _("Cannot parse PASV response.\n"));
+              break;
+            case FTPOK:
+              break;
+            default:
+              abort ();
+            }   /* switch (err) */
+          if (err==FTPOK)
+            {
+              DEBUGP (("trying to connect to %s port %d\n", 
+                      print_address (&passive_addr), passive_port));
+              dtsock = connect_to_ip (&passive_addr, passive_port, NULL);
+              if (dtsock < 0)
+                {
+                  int save_errno = errno;
+                  fd_close (csock);
+                  con->csock = -1;
+                  logprintf (LOG_VERBOSE, _("couldn't connect to %s port %d: %s\n"),
+                             print_address (&passive_addr), passive_port,
+                             strerror (save_errno));
+                  return (retryable_socket_connect_error (save_errno)
+                          ? CONERROR : CONIMPOSSIBLE);
+                }
+
+              pasv_mode_open = true;  /* Flag to avoid accept port */
+              if (!opt.server_response)
+                logputs (LOG_VERBOSE, _("done.    "));
+            } /* err==FTP_OK */
+        }
 
       if (!pasv_mode_open)   /* Try to use a port command if PASV failed */
-	{
-	  err = ftp_do_port (csock, &local_sock);
-	  /* FTPRERR, WRITEFAILED, bindport (FTPSYSERR), HOSTERR,
-	     FTPPORTERR */
-	  switch (err)
-	    {
-	    case FTPRERR:
-	      logputs (LOG_VERBOSE, "\n");
-	      logputs (LOG_NOTQUIET, _("\
+        {
+          err = ftp_do_port (csock, &local_sock);
+          /* FTPRERR, WRITEFAILED, bindport (FTPSYSERR), HOSTERR,
+             FTPPORTERR */
+          switch (err)
+            {
+            case FTPRERR:
+              logputs (LOG_VERBOSE, "\n");
+              logputs (LOG_NOTQUIET, _("\
 Error in server response, closing control connection.\n"));
-	      fd_close (csock);
-	      con->csock = -1;
-	      fd_close (dtsock);
-	      fd_close (local_sock);
-	      return err;
-	    case WRITEFAILED:
-	      logputs (LOG_VERBOSE, "\n");
-	      logputs (LOG_NOTQUIET,
-		       _("Write failed, closing control connection.\n"));
-	      fd_close (csock);
-	      con->csock = -1;
-	      fd_close (dtsock);
-	      fd_close (local_sock);
-	      return err;
-	    case CONSOCKERR:
-	      logputs (LOG_VERBOSE, "\n");
-	      logprintf (LOG_NOTQUIET, "socket: %s\n", strerror (errno));
-	      fd_close (csock);
-	      con->csock = -1;
-	      fd_close (dtsock);
-	      fd_close (local_sock);
-	      return err;
-	    case FTPSYSERR:
-	      logputs (LOG_VERBOSE, "\n");
-	      logprintf (LOG_NOTQUIET, _("Bind error (%s).\n"),
-			 strerror (errno));
-	      fd_close (dtsock);
-	      return err;
-	    case FTPPORTERR:
-	      logputs (LOG_VERBOSE, "\n");
-	      logputs (LOG_NOTQUIET, _("Invalid PORT.\n"));
-	      fd_close (csock);
-	      con->csock = -1;
-	      fd_close (dtsock);
-	      fd_close (local_sock);
-	      return err;
-	    case FTPOK:
-	      break;
-	    default:
-	      abort ();
-	    } /* port switch */
-	  if (!opt.server_response)
-	    logputs (LOG_VERBOSE, _("done.    "));
-	} /* dtsock == -1 */
+              fd_close (csock);
+              con->csock = -1;
+              fd_close (dtsock);
+              fd_close (local_sock);
+              return err;
+            case WRITEFAILED:
+              logputs (LOG_VERBOSE, "\n");
+              logputs (LOG_NOTQUIET,
+                       _("Write failed, closing control connection.\n"));
+              fd_close (csock);
+              con->csock = -1;
+              fd_close (dtsock);
+              fd_close (local_sock);
+              return err;
+            case CONSOCKERR:
+              logputs (LOG_VERBOSE, "\n");
+              logprintf (LOG_NOTQUIET, "socket: %s\n", strerror (errno));
+              fd_close (csock);
+              con->csock = -1;
+              fd_close (dtsock);
+              fd_close (local_sock);
+              return err;
+            case FTPSYSERR:
+              logputs (LOG_VERBOSE, "\n");
+              logprintf (LOG_NOTQUIET, _("Bind error (%s).\n"),
+                         strerror (errno));
+              fd_close (dtsock);
+              return err;
+            case FTPPORTERR:
+              logputs (LOG_VERBOSE, "\n");
+              logputs (LOG_NOTQUIET, _("Invalid PORT.\n"));
+              fd_close (csock);
+              con->csock = -1;
+              fd_close (dtsock);
+              fd_close (local_sock);
+              return err;
+            case FTPOK:
+              break;
+            default:
+              abort ();
+            } /* port switch */
+          if (!opt.server_response)
+            logputs (LOG_VERBOSE, _("done.    "));
+        } /* dtsock == -1 */
     } /* cmd & (DO_LIST | DO_RETR) */
 
   /* Restart if needed.  */
   if (restval && (cmd & DO_RETR))
     {
       if (!opt.server_response)
-	logprintf (LOG_VERBOSE, "==> REST %s ... ",
-		   number_to_static_string (restval));
+        logprintf (LOG_VERBOSE, "==> REST %s ... ",
+                   number_to_static_string (restval));
       err = ftp_rest (csock, restval);
 
       /* FTPRERR, WRITEFAILED, FTPRESTFAIL */
       switch (err)
-	{
-	case FTPRERR:
-	  logputs (LOG_VERBOSE, "\n");
-	  logputs (LOG_NOTQUIET, _("\
+        {
+        case FTPRERR:
+          logputs (LOG_VERBOSE, "\n");
+          logputs (LOG_NOTQUIET, _("\
 Error in server response, closing control connection.\n"));
-	  fd_close (csock);
-	  con->csock = -1;
-	  fd_close (dtsock);
-	  fd_close (local_sock);
-	  return err;
-	case WRITEFAILED:
-	  logputs (LOG_VERBOSE, "\n");
-	  logputs (LOG_NOTQUIET,
-		   _("Write failed, closing control connection.\n"));
-	  fd_close (csock);
-	  con->csock = -1;
-	  fd_close (dtsock);
-	  fd_close (local_sock);
-	  return err;
-	case FTPRESTFAIL:
-	  logputs (LOG_VERBOSE, _("\nREST failed, starting from scratch.\n"));
-	  rest_failed = true;
-	  break;
-	case FTPOK:
-	  break;
-	default:
-	  abort ();
-	}
+          fd_close (csock);
+          con->csock = -1;
+          fd_close (dtsock);
+          fd_close (local_sock);
+          return err;
+        case WRITEFAILED:
+          logputs (LOG_VERBOSE, "\n");
+          logputs (LOG_NOTQUIET,
+                   _("Write failed, closing control connection.\n"));
+          fd_close (csock);
+          con->csock = -1;
+          fd_close (dtsock);
+          fd_close (local_sock);
+          return err;
+        case FTPRESTFAIL:
+          logputs (LOG_VERBOSE, _("\nREST failed, starting from scratch.\n"));
+          rest_failed = true;
+          break;
+        case FTPOK:
+          break;
+        default:
+          abort ();
+        }
       if (err != FTPRESTFAIL && !opt.server_response)
-	logputs (LOG_VERBOSE, _("done.    "));
+        logputs (LOG_VERBOSE, _("done.    "));
     } /* restval && cmd & DO_RETR */
 
   if (cmd & DO_RETR)
     {
       /* If we're in spider mode, don't really retrieve anything.  The
-	 fact that we got to this point should be proof enough that
-	 the file exists, vaguely akin to HTTP's concept of a "HEAD"
-	 request.  */
+         fact that we got to this point should be proof enough that
+         the file exists, vaguely akin to HTTP's concept of a "HEAD"
+         request.  */
       if (opt.spider)
-	{
-	  fd_close (csock);
-	  con->csock = -1;
-	  fd_close (dtsock);
-	  fd_close (local_sock);
-	  return RETRFINISHED;
-	}
+        {
+          fd_close (csock);
+          con->csock = -1;
+          fd_close (dtsock);
+          fd_close (local_sock);
+          return RETRFINISHED;
+        }
 
       if (opt.verbose)
-	{
-	  if (!opt.server_response)
-	    {
-	      if (restval)
-		logputs (LOG_VERBOSE, "\n");
-	      logprintf (LOG_VERBOSE, "==> RETR %s ... ", escnonprint (u->file));
-	    }
-	}
+        {
+          if (!opt.server_response)
+            {
+              if (restval)
+                logputs (LOG_VERBOSE, "\n");
+              logprintf (LOG_VERBOSE, "==> RETR %s ... ", escnonprint (u->file));
+            }
+        }
 
       err = ftp_retr (csock, u->file);
       /* FTPRERR, WRITEFAILED, FTPNSFOD */
       switch (err)
-	{
-	case FTPRERR:
-	  logputs (LOG_VERBOSE, "\n");
-	  logputs (LOG_NOTQUIET, _("\
+        {
+        case FTPRERR:
+          logputs (LOG_VERBOSE, "\n");
+          logputs (LOG_NOTQUIET, _("\
 Error in server response, closing control connection.\n"));
-	  fd_close (csock);
-	  con->csock = -1;
-	  fd_close (dtsock);
-	  fd_close (local_sock);
-	  return err;
-	case WRITEFAILED:
-	  logputs (LOG_VERBOSE, "\n");
-	  logputs (LOG_NOTQUIET,
-		   _("Write failed, closing control connection.\n"));
-	  fd_close (csock);
-	  con->csock = -1;
-	  fd_close (dtsock);
-	  fd_close (local_sock);
-	  return err;
-	case FTPNSFOD:
-	  logputs (LOG_VERBOSE, "\n");
-	  logprintf (LOG_NOTQUIET, _("No such file `%s'.\n\n"),
-		     escnonprint (u->file));
-	  fd_close (dtsock);
-	  fd_close (local_sock);
-	  return err;
-	case FTPOK:
-	  break;
-	default:
-	  abort ();
-	}
+          fd_close (csock);
+          con->csock = -1;
+          fd_close (dtsock);
+          fd_close (local_sock);
+          return err;
+        case WRITEFAILED:
+          logputs (LOG_VERBOSE, "\n");
+          logputs (LOG_NOTQUIET,
+                   _("Write failed, closing control connection.\n"));
+          fd_close (csock);
+          con->csock = -1;
+          fd_close (dtsock);
+          fd_close (local_sock);
+          return err;
+        case FTPNSFOD:
+          logputs (LOG_VERBOSE, "\n");
+          logprintf (LOG_NOTQUIET, _("No such file `%s'.\n\n"),
+                     escnonprint (u->file));
+          fd_close (dtsock);
+          fd_close (local_sock);
+          return err;
+        case FTPOK:
+          break;
+        default:
+          abort ();
+        }
 
       if (!opt.server_response)
-	logputs (LOG_VERBOSE, _("done.\n"));
+        logputs (LOG_VERBOSE, _("done.\n"));
       expected_bytes = ftp_expected_bytes (ftp_last_respline);
     } /* do retrieve */
 
   if (cmd & DO_LIST)
     {
       if (!opt.server_response)
-	logputs (LOG_VERBOSE, "==> LIST ... ");
+        logputs (LOG_VERBOSE, "==> LIST ... ");
       /* As Maciej W. Rozycki (macro@ds2.pg.gda.pl) says, `LIST'
-	 without arguments is better than `LIST .'; confirmed by
-	 RFC959.  */
+         without arguments is better than `LIST .'; confirmed by
+         RFC959.  */
       err = ftp_list (csock, NULL);
       /* FTPRERR, WRITEFAILED */
       switch (err)
-	{
-	case FTPRERR:
-	  logputs (LOG_VERBOSE, "\n");
-	  logputs (LOG_NOTQUIET, _("\
+        {
+        case FTPRERR:
+          logputs (LOG_VERBOSE, "\n");
+          logputs (LOG_NOTQUIET, _("\
 Error in server response, closing control connection.\n"));
-	  fd_close (csock);
-	  con->csock = -1;
-	  fd_close (dtsock);
-	  fd_close (local_sock);
-	  return err;
-	case WRITEFAILED:
-	  logputs (LOG_VERBOSE, "\n");
-	  logputs (LOG_NOTQUIET,
-		   _("Write failed, closing control connection.\n"));
-	  fd_close (csock);
-	  con->csock = -1;
-	  fd_close (dtsock);
-	  fd_close (local_sock);
-	  return err;
-	case FTPNSFOD:
-	  logputs (LOG_VERBOSE, "\n");
-	  logprintf (LOG_NOTQUIET, _("No such file or directory `%s'.\n\n"),
-		     ".");
-	  fd_close (dtsock);
-	  fd_close (local_sock);
-	  return err;
-	case FTPOK:
-	  break;
-	default:
-	  abort ();
-	}
+          fd_close (csock);
+          con->csock = -1;
+          fd_close (dtsock);
+          fd_close (local_sock);
+          return err;
+        case WRITEFAILED:
+          logputs (LOG_VERBOSE, "\n");
+          logputs (LOG_NOTQUIET,
+                   _("Write failed, closing control connection.\n"));
+          fd_close (csock);
+          con->csock = -1;
+          fd_close (dtsock);
+          fd_close (local_sock);
+          return err;
+        case FTPNSFOD:
+          logputs (LOG_VERBOSE, "\n");
+          logprintf (LOG_NOTQUIET, _("No such file or directory `%s'.\n\n"),
+                     ".");
+          fd_close (dtsock);
+          fd_close (local_sock);
+          return err;
+        case FTPOK:
+          break;
+        default:
+          abort ();
+        }
       if (!opt.server_response)
-	logputs (LOG_VERBOSE, _("done.\n"));
+        logputs (LOG_VERBOSE, _("done.\n"));
       expected_bytes = ftp_expected_bytes (ftp_last_respline);
     } /* cmd & DO_LIST */
 
