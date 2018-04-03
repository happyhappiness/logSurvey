 
   return (val <= 0 ? (time_t) -1 : (time_t) val);
 }
-
-/* This function is called by `ar_scan' to find which member to look at.  */
-
-/* ARGSUSED */
-static long int
-ar_member_date_1 (int desc UNUSED, char *mem, int truncated,
-		  long int hdrpos UNUSED, long int datapos UNUSED,
-                  long int size UNUSED, long int date,
-                  int uid UNUSED, int gid UNUSED, int mode UNUSED, char *name)
-{
-  return ar_name_equal (name, mem, truncated) ? date : 0;
-}
 
 /* Set the archive-member NAME's modtime to now.  */
 
 #ifdef VMS
 int
-ar_touch (char *name)
+ar_touch (const char *name)
 {
   error (NILF, _("touch archive member is not available on VMS"));
   return -1;
 }
 #else
 int
-ar_touch (char *name)
+ar_touch (const char *name)
 {
   char *arname, *memname;
   int arname_used = 0;
