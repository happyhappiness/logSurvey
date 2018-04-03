 			aprintf ("bytes=%s-",
 				 number_to_static_string (hs->restval)),
 			rel_value);
-  if (opt.useragent)
-    request_set_header (req, "User-Agent", opt.useragent, rel_none);
-  else
-    request_set_header (req, "User-Agent",
-			aprintf ("Wget/%s", version_string), rel_value);
+  SET_USER_AGENT (req);
   request_set_header (req, "Accept", "*/*", rel_none);
 
   /* Find the username and password for authentication. */
