       switch (err)
         {
         case HOSTERR: case CONIMPOSSIBLE: case FWRITEERR: case FOPENERR:
-        case FTPNSFOD: case FTPLOGINC: case FTPNOPASV: case CONTNOTSUPPORTED:
-        case UNLINKERR: case WARC_TMP_FWRITEERR:
+        case FTPNSFOD: case FTPLOGINC: case FTPNOPASV: case FTPNOAUTH: case FTPNOPBSZ: case FTPNOPROT:
+        case UNLINKERR: case WARC_TMP_FWRITEERR: case CONSSLERR: case CONTNOTSUPPORTED:
+#ifdef HAVE_SSL
+          if (err == FTPNOAUTH)
+            logputs (LOG_NOTQUIET, "Server does not support AUTH TLS.\n");
+          if (opt.ftps_implicit)
+            logputs (LOG_NOTQUIET, "Server does not like implicit FTPS connections.\n");
+#endif
           /* Fatal errors, give up.  */
           if (warc_tmp != NULL)
               fclose (warc_tmp);
