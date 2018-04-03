                 logputs (LOG_VERBOSE, "done.");
 
               if (!opt.server_response)
-                logprintf (LOG_VERBOSE, "  ==> PROT %c ... ", prot);
+                logprintf (LOG_VERBOSE, "  ==> PROT %c ... ", (int) prot);
               if ((err = ftp_prot (csock, prot)) == FTPNOPROT)
                 {
-                  logprintf (LOG_NOTQUIET, _("Server did not accept the 'PROT %c' command.\n"), prot);
+                  logprintf (LOG_NOTQUIET, _("Server did not accept the 'PROT %c' command.\n"), (int) prot);
                   return err;
                 }
               if (!opt.server_response)
