             logputs (LOG_VERBOSE, "==> LPSV ... ");
           err = ftp_lpsv (rbuf, addr, port);
         }
-    }
-  else 
-    {
-      if (!opt.server_response)
-        logputs (LOG_VERBOSE, "==> PASV ... ");
-      err = ftp_pasv (rbuf, addr, port);
+      break;
+    default:
+      abort ();
     }
 
   return err;
