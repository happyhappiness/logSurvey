 
 long int
 describe_member (int desc, const char *name, int truncated,
-		 long int hdrpos, long int datapos, long int size,
+                 long int hdrpos, long int datapos, long int size,
                  long int date, int uid, int gid, int mode, const void *arg)
 {
   extern char *ctime ();
 
   printf (_("Member '%s'%s: %ld bytes at %ld (%ld).\n"),
-	  name, truncated ? _(" (name might be truncated)") : "",
-	  size, hdrpos, datapos);
+          name, truncated ? _(" (name might be truncated)") : "",
+          size, hdrpos, datapos);
   printf (_("  Date %s"), ctime (&date));
   printf (_("  uid = %d, gid = %d, mode = 0%o.\n"), uid, gid, mode);
 
