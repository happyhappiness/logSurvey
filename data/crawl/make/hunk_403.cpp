 static void
 child_out (const struct child *child, const char *msg, int out)
 {
-  int outfd = out ? child->outfd : child->errfd;
+  int fd = out ? child->outfd : child->errfd;
 
-  if (outfd >= 0)
+  if (fd >= 0)
     {
-      int t = strlen (msg);
-      int l;
-      lseek (outfd, 0, SEEK_END);
-      while (t)
+      int len = strlen (msg);
+
+      lseek (fd, 0, SEEK_END);
+      while (1)
         {
-          EINTRLOOP (l, write (outfd, msg, t));
-          if (l == t)
+          int b;
+          EINTRLOOP (b, write (fd, msg, len));
+          if (b == len)
             break;
-          if (l < 0)
-            {
-              perror ("write()");
-              break;
-            }
-          t -= l;
-          msg += l;
+          if (b <= 0)
+            return;
+          len -= b;
+          msg += b;
         }
     }
   else
     {
-      FILE *outf = out ? stdout : stderr;
-      fputs (msg, outf);
-      fflush (outf);
+      FILE *f = out ? stdout : stderr;
+      fputs (msg, f);
+      fflush (f);
     }
 }
 
