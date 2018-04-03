         }
     }
 
-  if (opt.post_data || opt.post_file_name)
+  if (opt.method)
     {
-      request_set_header (req, "Content-Type",
-                          "application/x-www-form-urlencoded", rel_none);
-      if (opt.post_data)
-        post_data_size = strlen (opt.post_data);
-      else
+
+      if (opt.body_data || opt.body_file)
         {
-          post_data_size = file_size (opt.post_file_name);
-          if (post_data_size == -1)
+          request_set_header (req, "Content-Type",
+                              "application/x-www-form-urlencoded", rel_none);
+
+          if (opt.body_data)
+            body_data_size = strlen (opt.body_data);
+          else
             {
-              logprintf (LOG_NOTQUIET, _("POST data file %s missing: %s\n"),
-                         quote (opt.post_file_name), strerror (errno));
-              return FILEBADFILE;
+              body_data_size = file_size (opt.body_file);
+              if (body_data_size == -1)
+                {
+                  logprintf (LOG_NOTQUIET, _("BODY data file %s missing: %s\n"),
+                             quote (opt.body_file), strerror (errno));
+                  return FILEBADFILE;
+                }
             }
+          request_set_header (req, "Content-Length",
+                              xstrdup (number_to_static_string (body_data_size)),
+                              rel_value);
         }
-      request_set_header (req, "Content-Length",
-                          xstrdup (number_to_static_string (post_data_size)),
-                          rel_value);
     }
 
  retry_with_auth:
