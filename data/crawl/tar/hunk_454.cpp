 | (all blank, or nonoctal).						  |
 `------------------------------------------------------------------------*/
 
-long
-from_oct (int digs, char *where)
+static uintmax_t
+from_oct (const char *where0, size_t digs0, const char *type, uintmax_t maxval)
 {
-  long value;
+  uintmax_t value;
+  const char *where = where0;
+  size_t digs = digs0;
 
-  while (ISSPACE (*where))
-    {				/* skip spaces */
+  for (;;)
+    {
+      if (digs == 0)
+	{
+	  ERROR ((0, 0, _("Blanks in header where octal %s value expected"),
+		  type));
+	  return -1;
+	}
+      if (!ISSPACE (*where))
+	break;
       where++;
-      if (--digs <= 0)
-	return -1;		/* all blank field */
+      digs--;
     }
+
   value = 0;
-  while (digs > 0 && ISODIGIT (*where))
+  while (digs != 0 && ISODIGIT (*where))
     {
       /* Scan til nonoctal.  */
 
+      if (value << 3 >> 3 != value)
+	goto out_of_range;
       value = (value << 3) | (*where++ - '0');
       --digs;
     }
 
-  if (digs > 0 && *where && !ISSPACE (*where))
-    return -1;			/* ended on non-space/nul */
+  if (digs != 0 && *where && !ISSPACE (*where))
+    {
+      ERROR ((0, 0, _("Header contains `%.*s' where octal %s value expected"),
+	      (int) digs0, where0, type));
+      return -1;
+    }
+
+  if (value <= maxval)
+    return value;
 
-  return value;
+ out_of_range:
+  ERROR ((0, 0, _("Octal value `%.*s' is out of range for %s"),
+	  (int) digs0, where0, type));
+  return -1;
+}
+gid_t
+gid_from_oct (const char *p, size_t s)
+{
+  return from_oct (p, s, "gid_t", GID_MAX);
+}
+major_t
+major_from_oct (const char *p, size_t s)
+{
+  return from_oct (p, s, "major_t", MAJOR_MAX);
+}
+minor_t
+minor_from_oct (const char *p, size_t s)
+{
+  return from_oct (p, s, "minor_t", MINOR_MAX);
+}
+mode_t
+mode_from_oct (const char *p, size_t s)
+{
+  return from_oct (p, s, "mode_t", MODE_MAX);
+}
+off_t
+off_from_oct (const char *p, size_t s)
+{
+  return from_oct (p, s, "off_t", OFF_MAX);
+}
+size_t
+size_from_oct (const char *p, size_t s)
+{
+  return from_oct (p, s, "size_t", SIZE_MAX);
+}
+time_t
+time_from_oct (const char *p, size_t s)
+{
+  return from_oct (p, s, "time_t", TIME_MAX);
+}
+uid_t
+uid_from_oct (const char *p, size_t s)
+{
+  return from_oct (p, s, "uid_t", UID_MAX);
+}
+uintmax_t
+uintmax_from_oct (const char *p, size_t s)
+{
+  return from_oct (p, s, "uintmax_t", UINTMAX_MAX);
+}
+
+
+
+/*----------------------------------------------------------------------.
+| Format O as a null-terminated decimal string into BUF _backwards_;	|
+| return pointer to start of result.					|
+`----------------------------------------------------------------------*/
+char *
+stringify_uintmax_t_backwards (uintmax_t o, char *buf)
+{
+  *--buf = '\0';
+  do
+    *--buf = '0' + (int) (o % 10);
+  while ((o /= 10) != 0);
+  return buf;
 }
 
 #if !USE_OLD_CTIME
