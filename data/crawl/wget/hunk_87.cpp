           retr_err = METALINK_RETR_ERROR;
 
           /* If output_stream is not NULL, then we have failed on
-             previous resource and are retrying. Thus, remove the file.  */
+             previous resource and are retrying. Thus, rename/remove
+             the file.  */
           if (output_stream)
             {
               fclose (output_stream);
               output_stream = NULL;
-              if (unlink (filename))
-                logprintf (LOG_NOTQUIET, "unlink: %s\n", strerror (errno));
+              badhash_or_remove (filename);
+              xfree (filename);
+            }
+          else if (filename)
+            {
+              /* Rename/remove the file downloaded previously before
+                 downloading it again.  */
+              badhash_or_remove (filename);
               xfree (filename);
             }
 
