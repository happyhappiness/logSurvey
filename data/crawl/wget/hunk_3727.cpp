 	{
 	  logprintf (LOG_NOTQUIET, "%s: %s\n", file, strerror (errno));
 	  return NULL;
-    }
+        }
 	c = fgetc(fp);
 	fclose(fp);
 	/* If the first character of the file is '0'-'9', it's WINNT
 	   format. */
 	if (c >= '0' && c <='9')
 	  return ftp_parse_winnt_ls (file);
-  else
-	  return ftp_parse_unix_ls (file, TRUE);
+        else
+          return ftp_parse_unix_ls (file, TRUE);
       }
+    case ST_VMS:
+      return ftp_parse_vms_ls (file);
+    case ST_MACOS:
+      return ftp_parse_unix_ls (file, TRUE);
     default:
-#ifdef HAVE_FTPPARSE
-      return ftp_parse_nonunix_ls (file);
-#else
-      /* #### Maybe log some warning here? */ 
-      return ftp_parse_unix_ls (file);
-#endif
+      logprintf (LOG_NOTQUIET, _("\
+Usupported listing type, trying Unix listing parser.\n"));
+      return ftp_parse_unix_ls (file, FALSE);
     }
 }
 
