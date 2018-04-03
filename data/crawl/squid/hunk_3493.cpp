             (int) (ms.bytes_total >> 10));
     fprintf(debug_log, "\tTotal free:            %6d KB %d%%\n",
             (int) (ms.bytes_free >> 10),
-            percent(ms.bytes_free, ms.bytes_total));
+            Math::intPercent(ms.bytes_free, ms.bytes_total));
 #elif HAVE_MALLINFO && HAVE_STRUCT_MALLINFO
 
     struct mallinfo mp;
