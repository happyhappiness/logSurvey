 
 sub touch
 {
-  local (@filenames) = @_;
   local ($file);
 
-  foreach $file (@filenames) {
+  foreach $file (@_) {
     (open(T, ">> $file") && print(T "\n") && close(T))
 	|| &error("Couldn't touch $file: $!\n", 1);
   }
 }
 
+# Touch with a time offset.  To DTRT, call touch() then use stat() to get the
+# access/mod time for each file and apply the offset.
+
+sub utouch
+{
+  local ($off) = shift;
+  local ($file);
+
+  &touch(@_);
+
+  local (@s) = stat($_[0]);
+
+  utime($s[8]+$off, $s[9]+$off, @_);
+}
+
 # open a file, write some stuff to it, and close it.
 
 sub create_file
