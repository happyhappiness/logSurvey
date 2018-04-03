     {
       printf (_("Error spawning, %d\n") ,status);
       fflush (stdout);
+      switch (status)
+        {
+        case 0x1c:
+          errno = EPROCLIM;
+          break;
+        default:
+          errno = EFAIL;
+        }
     }
 
   if (comname && !ISDB (DB_JOBS))
