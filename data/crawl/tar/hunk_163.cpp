   return false;
 }
 
-/* Decodes a single extended header record. Advances P to the next
-   record.
-   Returns true on success, false otherwise. */
+/* Decode a single extended header record, advancing *PTR to the next record.
+   Return true on success, false otherwise.  */
 static bool
-decode_record (char **p,
+decode_record (char **ptr,
 	       void (*handler) (void *, char const *, char const *),
 	       void *data)
 {
-  size_t len;
+  char *start = *ptr;
+  char *p = start;
+  unsigned long int len;
+  char *len_lim;
   char const *keyword;
-  char *start = *p;
-  char endc;
+  char *nextp;
+  size_t len_max = extended_header.buffer + extended_header.size - start;
 
-  if (**p == 0)
-    return false;
+  while (*p == ' ' || *p == '\t')
+    p++;
 
-  len = strtoul (*p, p, 10);
-  if (**p != ' ')
+  if (! ISDIGIT (*p))
     {
-      ERROR ((0, 0,
-       _("Malformed extended header: missing whitespace after the length")));
+      if (*p)
+	ERROR ((0, 0, _("Malformed extended header: missing length")));
       return false;
     }
 
-  keyword = ++*p;
-  for (;*p < start + len; ++*p)
-    if (**p == '=')
-      break;
+  errno = 0;
+  len = strtoul (p, &len_lim, 10);
 
-  if (**p != '=')
+  if (len_max < len || (len == ULONG_MAX && errno == ERANGE))
     {
-      ERROR ((0, 0, _("Malformed extended header: missing equal sign")));
+      ERROR ((0, 0, _("Malformed extended header: length out of range")));
       return false;
     }
 
-  **p = 0;
+  nextp = start + len;
 
-  endc = start[len-1];
-  start[len-1] = 0;
+  for (p = len_lim; *p == ' ' || *p == '\t'; p++)
+    continue;
+  if (p == len_lim)
+    {
+      ERROR ((0, 0,
+	      _("Malformed extended header: missing blank after length")));
+      return false;
+    }
 
-  handler (data, keyword, *p + 1);
+  keyword = p;
+  p = strchr (p, '=');
+  if (! (p && p < nextp))
+    {
+      ERROR ((0, 0, _("Malformed extended header: missing equal sign")));
+      return false;
+    }
+
+  if (nextp[-1] != '\n')
+    {
+      ERROR ((0, 0, _("Malformed extended header: missing newline")));
+      return false;
+    }
 
-  start[len-1] = endc;
-  **p = '=';
-  *p = &start[len];
+  *p = nextp[-1] = '\0';
+  handler (data, keyword, p + 1);
+  *p = '=';
+  nextp[-1] = '\n';
+  *ptr = nextp;
   return true;
 }
 
