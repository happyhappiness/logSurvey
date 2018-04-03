 	  adjusted_mtime -= adjustment;
 #endif
 
-	/* If the file's time appears to be in the future, udpate our
+	/* If the file's time appears to be in the future, update our
 	   concept of the present and try once more.  */
-	if (now < adjusted_mtime
-	    && (now = file_timestamp_now ()) < adjusted_mtime)
-          {
-	    char mtimebuf[FILE_TIMESTAMP_PRINT_LEN_BOUND + 1];
-	    char nowbuf[FILE_TIMESTAMP_PRINT_LEN_BOUND + 1];
-
-	    file_timestamp_sprintf (mtimebuf, mtime);
-	    file_timestamp_sprintf (nowbuf, now);
-            error (NILF, _("*** Warning: File `%s' has modification time in the future (%s > %s)"),
-                   file->name, mtimebuf, nowbuf);
-            clock_skew_detected = 1;
+	if (adjusted_now < adjusted_mtime)
+	  {
+	    int resolution;
+	    FILE_TIMESTAMP now = file_timestamp_now (&resolution);
+	    adjusted_now = now + (resolution - 1);
+	    if (adjusted_now < adjusted_mtime)
+	      {
+#ifdef NO_FLOAT
+		error (NILF, _("*** Warning: File `%s' has modification time in the future"),
+                       file->name);
+#else
+		double from_now =
+		  (FILE_TIMESTAMP_S (mtime) - FILE_TIMESTAMP_S (now)
+		   + ((FILE_TIMESTAMP_NS (mtime) - FILE_TIMESTAMP_NS (now))
+		      / 1e9));
+		error (NILF, _("*** Warning: File `%s' has modification time %.2g s in the future"),
+		       file->name, from_now);
+#endif
+		clock_skew_detected = 1;
+	      }
           }
       }
   }
