           entry->link_expect_html = 1;
         }
     }
+  else if (http_equiv && 0 == strcasecmp (http_equiv, "content-type"))
+    {
+      /* Handle stuff like:
+         <meta http-equiv="Content-Type" content="text/html; charset=CHARSET"> */
+
+      char *mcharset;
+      char *content = find_attr (tag, "content", NULL);
+      if (!content)
+        return;
+
+      mcharset = parse_charset (content);
+      if (!mcharset)
+        return;
+
+      logprintf (LOG_VERBOSE, "Meta tag charset : %s\n", quote (mcharset));
+
+      /* sXXXav: Not used yet */
+      xfree (mcharset);
+    }
   else if (name && 0 == strcasecmp (name, "robots"))
     {
       /* Handle stuff like:
