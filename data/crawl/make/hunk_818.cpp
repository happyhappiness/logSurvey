   return o;
 }
 
-char *
-strip_whitespace (char **begpp, char **endpp)
+static char *
+strip_whitespace (const char **begpp, const char **endpp)
 {
   while (isspace ((unsigned char)**begpp) && *begpp <= *endpp)
     (*begpp) ++;
   while (isspace ((unsigned char)**endpp) && *endpp >= *begpp)
     (*endpp) --;
-  return *begpp;
+  return (char *)*begpp;
 }
 
-int
-is_numeric (char *p)
+static void
+check_numeric (const char *s, const char *message)
 {
-  char *end = p + strlen (p) - 1;
-  char *beg = p;
-  strip_whitespace (&p, &end);
-
-  while (p <= end)
-    if (!ISDIGIT (*(p++)))  /* ISDIGIT only evals its arg once: see make.h.  */
-      return 0;
+  const char *end = s + strlen (s) - 1;
+  const char *beg = s;
+  strip_whitespace (&s, &end);
 
-  return (end - beg >= 0);
-}
+  for (; s <= end; ++s)
+    if (!ISDIGIT (*s))  /* ISDIGIT only evals its arg once: see make.h.  */
+      break;
 
-void
-check_numeric (char *s, char *message)
-{
-  if (!is_numeric (s))
-    fatal (reading_file, message);
+  if (s <= end || end - beg < 0)
+    fatal (reading_file, "%s: '%s'", message, beg);
 }
 
 
