 #define	access_inited	(user_uid != -1)
 static enum { make, user } current_access;
 
+
+/* Under -d, write a message describing the current IDs.  */
+
+static void
+log_access (flavor)
+     char *flavor;
+{
+  if (! debug_flag)
+    return;
+
+  printf ("%s access: user %d (real %d), group %d (real %d)\n",
+	  flavor, geteuid (), getuid (), getegid (), getgid ());
+  fflush (stdout);
+}
+
+
 static void
 init_access ()
 {
