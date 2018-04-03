 	static unsigned long vms_now[2]; /* assumes 32 bit long ! */
 	sys$gettim (vms_now);
 	now = ((vms_now[0]>>24) & 0xff) + ((vms_now[1]<<8) & 0xffffff00);
-	if (mtime > now)
 #else
 	extern time_t time ();
-	if (mtime > time (&now))
+	time (&now);
 #endif
-	  {
-	    error ("*** File `%s' has modification time in the future",
-		   file->name);
-	    file->update_status = 2;
-	  }
+	if (mtime > now)
+          error ("*** Warning: File `%s' has modification time in the future",
+                 file->name);
       }
   }
 
