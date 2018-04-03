   return 1;
 }
 
+# We used to use this behavior for this function:
+#
+#sub touch
+#{
+#  local (@filenames) = @_;
+#  local ($now) = time;
+#  local ($file);
+#
+#  foreach $file (@filenames)
+#  {
+#    utime ($now, $now, $file)
+#          || (open (TOUCHFD, ">> $file") && close (TOUCHFD))
+#               || &error ("Couldn't touch $file: $!\n", 1);
+#  }
+#  return 1;
+#}
+#
+# But this behaves badly on networked filesystems where the time is
+# skewed, because it sets the time of the file based on the _local_
+# host.  Normally when you modify a file, it's the _remote_ host that
+# determines the modtime, based on _its_ clock.  So, instead, now we open
+# the file and write something into it to force the remote host to set
+# the modtime correctly according to its clock.
+#
+
 sub touch
 {
   local (@filenames) = @_;
-  local ($now) = time;
   local ($file);
 
-  foreach $file (@filenames)
-  {
-    utime ($now, $now, $file)
-          || (open (TOUCHFD, ">> $file") && close (TOUCHFD))
-               || &error ("Couldn't touch $file: $!\n", 1);
+  foreach $file (@filenames) {
+    (open(T, ">> $file") && print(T "\n") && close(T))
+	|| &error("Couldn't touch $file: $!\n", 1);
   }
-  return 1;
 }
 
 # open a file, write some stuff to it, and close it.
