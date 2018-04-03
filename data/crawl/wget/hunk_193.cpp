         goto http;
 
       /* Turn "foo.bar.com:path" to "ftp://foo.bar.com/path". */
-      ret = aprintf ("ftp://%s", url);
-      ret[6 + (p - url)] = '/';
+      if ((ret = aprintf ("ftp://%s", url)) != NULL)
+        ret[6 + (p - url)] = '/';
     }
   else
     {
