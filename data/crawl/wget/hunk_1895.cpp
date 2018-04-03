 
 static bool find_fragment (const char *, int, const char **, const char **);
 
+/* Replace a string with NEW_TEXT.  Ignore quoting. */
+static const char *
+replace_plain (const char *p, int size, FILE *fp, const char *new_text)
+{
+  fputs (new_text, fp);
+  p += size;
+  return p;
+}
+
 /* Replace an attribute's original text with NEW_TEXT. */
 
 static const char *
