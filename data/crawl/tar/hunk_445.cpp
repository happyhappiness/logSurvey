 
 
 /*------------------------------------------------------------------------.
-| Converts long VALUE into a DIGS-digit field at WHERE, including a       |
-| trailing space and room for a NUL.  For example, 3 for DIGS 3 means one |
-| digit, a space, and room for a NUL.                                     |
+| Convert VALUE into a size-SIZE field at WHERE, including a		  |
+| trailing space.  For example, 3 for SIZE means two digits and a space.  |
 |                                                                         |
 | We assume the trailing NUL is already there and don't fill it in.  This |
 | fact is used by start_header and finish_header, so don't change it!     |
 `------------------------------------------------------------------------*/
 
-/* This should be equivalent to: sprintf (WHERE, "%*lo ", DIGS - 2, VALUE);
+/* This should be equivalent to: sprintf (WHERE, "%*lo ", SIZE - 1, VALUE);
+   except that we don't assume VALUE fits in an unsigned long, and
    except that sprintf fills in the trailing NUL and we don't.  */
 
-void
-to_oct (long value, int digs, char *where)
+static void
+to_oct (uintmax_t value, char *where, size_t size, const char *type)
 {
-  --digs;			/* Trailing null slot is left alone */
-  where[--digs] = ' ';		/* put in the space, though */
+  uintmax_t v = value;
+  size_t i = size;
+  where[--i] = ' ';		/* put in the space, though */
 
   /* Produce the digits -- at least one.  */
 
   do
     {
-      where[--digs] = '0' + (char) (value & 7);	/* one octal digit */
-      value >>= 3;
+      where[--i] = '0' + (int) (v & 7);	/* one octal digit */
+      v >>= 3;
     }
-  while (digs > 0 && value != 0);
+  while (i != 0 && v != 0);
 
   /* Leading spaces, if necessary.  */
-  while (digs > 0)
-    where[--digs] = ' ';
+  while (i != 0)
+    where[--i] = ' ';
+
+  if (v != 0)
+    {
+      char buf[UINTMAX_STRSIZE_BOUND];
+      ERROR ((0, 0, _("%s value %s is too large to fit in a %u-bit field"),
+	      type, STRINGIFY_BIGINT (value, buf),
+	      (unsigned) ((size - 1) * 3)));
+    }
+}
+void
+gid_to_oct (gid_t v, char *p, size_t s)
+{
+  to_oct (v, p, s, "gid_t");
+}
+void
+major_to_oct (major_t v, char *p, size_t s)
+{
+  to_oct (v, p, s, "major_t");
+}
+void
+minor_to_oct (minor_t v, char *p, size_t s)
+{
+  to_oct (v, p, s, "minor_t");
+}
+void
+mode_to_oct (mode_t v, char *p, size_t s)
+{
+  to_oct (v, p, s, "mode_t");
+}
+void
+off_to_oct (off_t v, char *p, size_t s)
+{
+  to_oct (v, p, s, "off_t");
+}
+void
+size_to_oct (size_t v, char *p, size_t s)
+{
+  to_oct (v, p, s, "size_t");
+}
+void
+time_to_oct (time_t v, char *p, size_t s)
+{
+  to_oct (v, p, s, "time_t");
+}
+void
+uid_to_oct (uid_t v, char *p, size_t s)
+{
+  to_oct (v, p, s, "uid_t");
+}
+void
+uintmax_to_oct (uintmax_t v, char *p, size_t s)
+{
+  to_oct (v, p, s, "uintmax_t");
 }
 
 /* Writing routines.  */
