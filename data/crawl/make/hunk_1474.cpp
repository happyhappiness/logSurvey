       file = file->prev;
     } while (file != 0);
 
+  {
+    /* Files can have bogus timestamps that nothing newly made will be
+       "newer" than.  Updating their dependents could just result in loops.
+       So notify the user of the anomaly by treating future files as
+       unrecoverably absent.  */
+
+    static time_t now;
+    if (mtime > now && ! file->updated)
+      {
+	/* This file's time appears to be in the future.
+	   Update our concept of the present, and compare again.  */
+	extern time_t time ();
+	if (mtime > time (&now))
+	  {
+	    error ("*** File `%s' has modification time in the future",
+		   file->name);
+	    file->update_status = 2;
+	  }
+      }
+  }
+
   return mtime;
 }
 
