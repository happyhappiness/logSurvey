 #endif
 				     );
 
+  if (opt.post_data || opt.post_file_name)
+    {
+      post_content_type = "Content-Type: application/x-www-form-urlencoded\r\n";
+      if (opt.post_data)
+	post_data_size = strlen (opt.post_data);
+      else
+	{
+	  post_data_size = file_size (opt.post_file_name);
+	  if (post_data_size == -1)
+	    {
+	      logprintf (LOG_NOTQUIET, "POST data file missing: %s\n",
+			 opt.post_file_name);
+	      post_data_size = 0;
+	    }
+	}
+      post_content_length = xmalloc (16 + numdigit (post_data_size) + 2 + 1);
+      sprintf (post_content_length,
+	       "Content-Length: %ld\r\n", post_data_size);
+    }
+
   if (proxy)
     full_path = xstrdup (u->url);
   else
