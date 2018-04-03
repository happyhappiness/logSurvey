 
     escape_string (metric_name, sizeof (metric_name));
 
-    status = ssnprintf (csv_buffer + offset, sizeof (csv_buffer) - offset,
+    pthread_mutex_lock (&send_lock);
+
+    status = ssnprintf (send_buffer + send_buffer_fill, sizeof (send_buffer) - send_buffer_fill,
         "\"%s\",%s,%s\n",
         metric_name, timestamp, value);
-    offset += status;
+    send_buffer_fill += status;
 
-  } /* for */
+    printf(send_buffer);
+    printf("Fill: %i\n", send_buffer_fill);
+    printf("----\n");
 
-  printf(csv_buffer);
+    if ((sizeof (send_buffer) - send_buffer_fill) < 128)
+    {
+            http_flush_buffer();
+    }
 
-  pthread_mutex_lock (&send_lock);
+    pthread_mutex_unlock (&send_lock);
 
-  curl_easy_setopt (curl, CURLOPT_POSTFIELDS, csv_buffer);
-  status = curl_easy_perform (curl);
-  if (status != 0)
-  {
-    ERROR ("curl plugin: curl_easy_perform failed with staus %i: %s",
-        status, curl_errbuf);
-    return (-1);
-  }
+  } /* for */
 
-  pthread_mutex_unlock (&send_lock);
 
   return (0);
 