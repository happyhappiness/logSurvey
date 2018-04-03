 	extern time_t time ();
 	time (&now);
 #endif
-	if (mtime > now)
-          error ("*** Warning: File `%s' has modification time in the future",
-                 file->name);
+#ifdef WINDOWS32
+	/*
+	 * FAT filesystems round time to nearest even second(!). Just
+	 * allow for any file (NTFS or FAT) to perhaps suffer from this
+	 * braindamage.
+	 */
+	if (mtime > now && (((mtime % 2) == 0) && ((mtime-1) > now)))
+#else
+        if (mtime > now)
+#endif
+          {
+            error("*** Warning: File `%s' has modification time in the future",
+                  file->name);
+            clock_skew_detected = 1;
+          }
       }
   }
 
