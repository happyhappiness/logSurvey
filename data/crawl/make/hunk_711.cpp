 
 	      rehash_file (file, name);
 	      check_renamed (file);
-	      mtime = name_mtime (name);
+              /* If the result of a vpath search is -o or -W, preserve it.
+                 Otherwise, find the mtime of the resulting file.  */
+              if (mtime != OLD_MTIME && mtime != NEW_MTIME)
+                mtime = name_mtime (name);
 	    }
 	}
     }
 
-  {
-    /* Files can have bogus timestamps that nothing newly made will be
-       "newer" than.  Updating their dependents could just result in loops.
-       So notify the user of the anomaly with a warning.
+  /* Files can have bogus timestamps that nothing newly made will be
+     "newer" than.  Updating their dependents could just result in loops.
+     So notify the user of the anomaly with a warning.
 
-       We only need to do this once, for now. */
+     We only need to do this once, for now. */
 
-    if (!clock_skew_detected
-	&& mtime != NONEXISTENT_MTIME
-	&& !file->updated)
-      {
-	static FILE_TIMESTAMP adjusted_now;
+  if (!clock_skew_detected
+      && mtime != NONEXISTENT_MTIME && mtime != NEW_MTIME
+      && !file->updated)
+    {
+      static FILE_TIMESTAMP adjusted_now;
 
-	FILE_TIMESTAMP adjusted_mtime = mtime;
+      FILE_TIMESTAMP adjusted_mtime = mtime;
 
 #if defined(WINDOWS32) || defined(__MSDOS__)
-	/* Experimentation has shown that FAT filesystems can set file times
-	   up to 3 seconds into the future!  Play it safe.  */
+      /* Experimentation has shown that FAT filesystems can set file times
+         up to 3 seconds into the future!  Play it safe.  */
 
 #define FAT_ADJ_OFFSET  (FILE_TIMESTAMP) 3
 
-	FILE_TIMESTAMP adjustment = FAT_ADJ_OFFSET << FILE_TIMESTAMP_LO_BITS;
-	if (ORDINARY_MTIME_MIN + adjustment <= adjusted_mtime)
-	  adjusted_mtime -= adjustment;
+      FILE_TIMESTAMP adjustment = FAT_ADJ_OFFSET << FILE_TIMESTAMP_LO_BITS;
+      if (ORDINARY_MTIME_MIN + adjustment <= adjusted_mtime)
+        adjusted_mtime -= adjustment;
 #elif defined(__EMX__)
-	/* FAT filesystems round time to the nearest even second!
-	   Allow for any file (NTFS or FAT) to perhaps suffer from this
-	   brain damage.  */
-	FILE_TIMESTAMP adjustment = (((FILE_TIMESTAMP_S (adjusted_mtime) & 1) == 0
-		       && FILE_TIMESTAMP_NS (adjusted_mtime) == 0)
-		      ? (FILE_TIMESTAMP) 1 << FILE_TIMESTAMP_LO_BITS
-		      : 0);
+      /* FAT filesystems round time to the nearest even second!
+         Allow for any file (NTFS or FAT) to perhaps suffer from this
+         brain damage.  */
+      FILE_TIMESTAMP adjustment = (((FILE_TIMESTAMP_S (adjusted_mtime) & 1) == 0
+                     && FILE_TIMESTAMP_NS (adjusted_mtime) == 0)
+                    ? (FILE_TIMESTAMP) 1 << FILE_TIMESTAMP_LO_BITS
+                    : 0);
 #endif
 
-	/* If the file's time appears to be in the future, update our
-	   concept of the present and try once more.  */
-	if (adjusted_now < adjusted_mtime)
-	  {
-	    int resolution;
-	    FILE_TIMESTAMP now = file_timestamp_now (&resolution);
-	    adjusted_now = now + (resolution - 1);
-	    if (adjusted_now < adjusted_mtime)
-	      {
+      /* If the file's time appears to be in the future, update our
+         concept of the present and try once more.  */
+      if (adjusted_now < adjusted_mtime)
+        {
+          int resolution;
+          FILE_TIMESTAMP now = file_timestamp_now (&resolution);
+          adjusted_now = now + (resolution - 1);
+          if (adjusted_now < adjusted_mtime)
+            {
 #ifdef NO_FLOAT
-		error (NILF, _("Warning: File `%s' has modification time in the future"),
-                       file->name);
+              error (NILF, _("Warning: File `%s' has modification time in the future"),
+                     file->name);
 #else
-		double from_now =
-		  (FILE_TIMESTAMP_S (mtime) - FILE_TIMESTAMP_S (now)
-		   + ((FILE_TIMESTAMP_NS (mtime) - FILE_TIMESTAMP_NS (now))
-		      / 1e9));
-		error (NILF, _("Warning: File `%s' has modification time %.2g s in the future"),
-		       file->name, from_now);
+              double from_now =
+                (FILE_TIMESTAMP_S (mtime) - FILE_TIMESTAMP_S (now)
+                 + ((FILE_TIMESTAMP_NS (mtime) - FILE_TIMESTAMP_NS (now))
+                    / 1e9));
+              error (NILF, _("Warning: File `%s' has modification time %.2g s in the future"),
+                     file->name, from_now);
 #endif
-		clock_skew_detected = 1;
-	      }
-          }
-      }
-  }
+              clock_skew_detected = 1;
+            }
+        }
+    }
 
   /* Store the mtime into all the entries for this file.  */
   if (file->double_colon)
