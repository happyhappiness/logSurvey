 {
   extern char *ctime ();
 
-  printf ("Member `%s'%s: %ld bytes at %ld (%ld).\n",
-	  name, truncated ? " (name might be truncated)" : "",
+  printf (_("Member `%s'%s: %ld bytes at %ld (%ld).\n"),
+	  name, truncated ? _(" (name might be truncated)") : "",
 	  size, hdrpos, datapos);
-  printf ("  Date %s", ctime (&date));
-  printf ("  uid = %d, gid = %d, mode = 0%o.\n", uid, gid, mode);
+  printf (_("  Date %s"), ctime (&date));
+  printf (_("  uid = %d, gid = %d, mode = 0%o.\n"), uid, gid, mode);
 
   return 0;
 }
