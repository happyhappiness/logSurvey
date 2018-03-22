 
   if (v != 0)
     {
-      char buf[UINTMAX_STRSIZE_BOUND];
-      ERROR ((0, 0, _("%s value %s is too large to fit in a %u-bit field"),
-	      type, STRINGIFY_BIGINT (value, buf),
-	      (unsigned) ((size - 1) * 3)));
+      int bits = size * 3;
+      uintmax_t maxval = (bits < sizeof (uintmax_t) * CHAR_BIT
+			  ? ((uintmax_t) 1 << bits) - 1
+			  : (uintmax_t) -1);
+      char buf1[UINTMAX_STRSIZE_BOUND];
+      char buf2[UINTMAX_STRSIZE_BOUND];
+      char buf3[UINTMAX_STRSIZE_BOUND];
+      char *value_string = STRINGIFY_BIGINT (value, buf1);
+      char *maxval_string = STRINGIFY_BIGINT (maxval, buf2);
+      if (substitute)
+	{
+	  substitute &= maxval;
+	  WARN ((0, 0, _("%s value %s too large (max=%s); substituting %s"),
+		 type, value_string, maxval_string,
+		 STRINGIFY_BIGINT (substitute, buf3)));
+	  to_oct (substitute, (uintmax_t) 0, where, size, type);
+	}
+      else
+	ERROR ((0, 0, _("%s value %s too large (max=%s)"),
+		type, value_string, maxval_string));
     }
 }
+#ifndef GID_NOBODY
+#define GID_NOBODY 0
+#endif
 void
 gid_to_oct (gid_t v, char *p, size_t s)
 {
-  to_oct ((uintmax_t) v, p, s, "gid_t");
+  to_oct ((uintmax_t) v, (uintmax_t) GID_NOBODY, p, s, "gid_t");
 }
 void
 major_to_oct (major_t v, char *p, size_t s)
 {
-  to_oct ((uintmax_t) v, p, s, "major_t");
+  to_oct ((uintmax_t) v, (uintmax_t) 0, p, s, "major_t");
 }
 void
 minor_to_oct (minor_t v, char *p, size_t s)
 {
-  to_oct ((uintmax_t) v, p, s, "minor_t");
+  to_oct ((uintmax_t) v, (uintmax_t) 0, p, s, "minor_t");
 }
 void
 mode_to_oct (mode_t v, char *p, size_t s)
 {
-  to_oct ((uintmax_t) v, p, s, "mode_t");
+  to_oct ((uintmax_t) v, (uintmax_t) 0, p, s, "mode_t");
 }
 void
 off_to_oct (off_t v, char *p, size_t s)
 {
-  to_oct ((uintmax_t) v, p, s, "off_t");
+  to_oct ((uintmax_t) v, (uintmax_t) 0, p, s, "off_t");
 }
 void
 size_to_oct (size_t v, char *p, size_t s)
 {
-  to_oct ((uintmax_t) v, p, s, "size_t");
+  to_oct ((uintmax_t) v, (uintmax_t) 0, p, s, "size_t");
 }
 void
 time_to_oct (time_t v, char *p, size_t s)
 {
-  to_oct ((uintmax_t) v, p, s, "time_t");
+  to_oct ((uintmax_t) v, (uintmax_t) 0, p, s, "time_t");
 }
+#ifndef UID_NOBODY
+#define UID_NOBODY 0
+#endif
 void
 uid_to_oct (uid_t v, char *p, size_t s)
 {
-  to_oct ((uintmax_t) v, p, s, "uid_t");
+  to_oct ((uintmax_t) v, (uintmax_t) UID_NOBODY, p, s, "uid_t");
 }
 void
 uintmax_to_oct (uintmax_t v, char *p, size_t s)
 {
-  to_oct (v, p, s, "uintmax_t");
+  to_oct (v, (uintmax_t) 0, p, s, "uintmax_t");
 }
 
 /* Writing routines.  */
