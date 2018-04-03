         {
           DEBUGP (("[POST data: %s]\n", opt.post_data));
           write_error = fd_write (sock, opt.post_data, post_data_size, -1);
+          if (write_error >= 0 && warc_tmp != NULL)
+            {
+              /* Remember end of headers / start of payload. */
+              warc_payload_offset = ftell (warc_tmp);
+
+              /* Write a copy of the data to the WARC record. */
+              int warc_tmp_written = fwrite (opt.post_data, 1, post_data_size, warc_tmp);
+              if (warc_tmp_written != post_data_size)
+                write_error = -2;
+            }
         }
       else if (opt.post_file_name && post_data_size != 0)
-        write_error = post_file (sock, opt.post_file_name, post_data_size);
+        {
+          if (warc_tmp != NULL)
+            /* Remember end of headers / start of payload. */
+            warc_payload_offset = ftell (warc_tmp);
+
+          write_error = post_file (sock, opt.post_file_name, post_data_size, warc_tmp);
+        }
     }
 
   if (write_error < 0)
     {
       CLOSE_INVALIDATE (sock);
       request_free (req);
-      return WRITEFAILED;
+
+      if (warc_tmp != NULL)
+        fclose (warc_tmp);
+
+      if (write_error == -2)
+        return WARC_TMP_FWRITEERR;
+      else
+        return WRITEFAILED;
     }
   logprintf (LOG_VERBOSE, _("%s request sent, awaiting response... "),
              proxy ? "Proxy" : "HTTP");
