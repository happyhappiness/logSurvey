               DEBUGP (("  Unix: '%s'\n  VMS: '%s'\n", target, ntarget));
               target = ntarget;
             }
+#endif /* 0 */
+
+          /* 2004-09-20 SMS.
+             A relative directory is relative to the initial directory. 
+             Thus, what _is_ useful on VMS (and probably elsewhere) is
+             to CWD to the initial directory (ideally, whatever the
+             server reports, _exactly_, NOT badly UNIX-ixed), and then
+             CWD to the (new) relative directory.  This should probably
+             be restructured as a function, called once or twice, but
+             I'm lazy enough to take the badly indented loop short-cut
+             for now.
+          */
+
+          /* Decide on one pass (absolute) or two (relative).
+             The VMS restriction may be relaxed when the squirrely code
+             above is reformed.
+          */
+	  if ((con->rs == ST_VMS) && (target[0] != '/'))
+	    {
+	      cwd_start = 0;
+	      DEBUGP (("Using two-step CWD for relative path.\n"));
+	    }
+	  else
+	    {
+              /* Go straight to the target. */
+	      cwd_start = 1;
+	    }
+
+          /* At least one VMS FTP server (TCPware V5.6-2) can switch to
+             a UNIX emulation mode when given a UNIX-like directory
+             specification (like "a/b/c").  If allowed to continue this
+             way, LIST interpretation will be confused, because the
+             system type (SYST response) will not be re-checked, and
+             future UNIX-format directory listings (for multiple URLs or
+             "-r") will be horribly misinterpreted.
+
+             The cheap and nasty work-around is to do a "CWD []" after a
+             UNIX-like directory specification is used.  (A single-level
+             directory is harmless.)  This puts the TCPware server back
+             into VMS mode, and does no harm on other servers.
+
+             Unlike the rest of this block, this particular behavior
+             _is_ VMS-specific, so it gets its own VMS test.
+          */
+	  if ((con->rs == ST_VMS) && (strchr( target, '/') != NULL))
+            {
+              cwd_end = 3;
+	      DEBUGP (("Using extra \"CWD []\" step for VMS server.\n"));
+            }
+          else
+            {
+              cwd_end = 2;
+            }
+
+          /* 2004-09-20 SMS. */
+          /* Sorry about the deviant indenting.  Laziness. */
+
+	  for (cwd_count = cwd_start; cwd_count < cwd_end; cwd_count++)
+	{
+          switch (cwd_count)
+            {
+              case 0:
+	        /* Step one (optional): Go to the initial directory,
+	           exactly as reported by the server.
+	        */
+	        targ = con->id;
+                break;
+
+              case 1:
+	        /* Step two: Go to the target directory.  (Absolute or
+	           relative will work now.)
+	        */
+	        targ = target;
+                break;
+
+              case 2:
+                /* Step three (optional): "CWD []" to restore server
+                   VMS-ness.
+                */
+                targ = "[]";
+                break;
+
+              default:
+                /* Can't happen. */
+                assert (1);
+	    }
 
           if (!opt.server_response)
-            logprintf (LOG_VERBOSE, "==> CWD %s ... ", escnonprint (target));
-          err = ftp_cwd (csock, target);
+            logprintf (LOG_VERBOSE, "==> CWD (%d) %s ... ",
+             cwd_count, escnonprint (target));
+          err = ftp_cwd (csock, targ);
           /* FTPRERR, WRITEFAILED, FTPNSFOD */
           switch (err)
             {
