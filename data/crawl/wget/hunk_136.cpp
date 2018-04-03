         case SCHEME_HTTPS: scheme_str = "SCHEME_HTTPS";   break;
       #endif
       case SCHEME_FTP:     scheme_str = "SCHEME_FTP";     break;
-      case SCHEME_INVALID: scheme_str = "SCHEME_INVALID"; break;
+      default:             scheme_str = "SCHEME_INVALID"; break;
     }
 
-  fprintf (f, "%s\t%s\t%s\t%i\t%s\t%s\t%s\t%s",
+  fprintf (fp, "%s\t%s\t%s\t%i\t%s\t%s\t%s\t%s",
     escaped_str,
     scheme_str,
     url->host,
     url->port,
     url->path,
-    url->params ? url->params : empty_str,
-    url->query ? url->query : empty_str,
-    url->fragment ? url->fragment : empty_str);
+    url->params ? url->params : "",
+    url->query ? url->query : "",
+    url->fragment ? url->fragment : "");
 
-  free (escaped_str);
+  xfree (escaped_str);
 }
 
 /* This function writes out information on why a URL was rejected and its
    context from download_child such as the URL being rejected and it's
    parent's URL. The format it uses is comma separated values but with tabs. */
 static void
-write_reject_log_reason (FILE *f, reject_reason r, struct url *url,
-                         struct url *parent)
+write_reject_log_reason (FILE *fp, reject_reason reason,
+                         const struct url *url, const struct url *parent)
 {
-  if (!f)
+  const char *reason_str;
+
+  if (!fp)
     return;
 
-  char const *reason_str = 0;
-  switch (r)
+  switch (reason)
     {
       case SUCCESS:     reason_str = "SUCCESS";     break;
       case BLACKLIST:   reason_str = "BLACKLIST";   break;
