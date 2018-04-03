 #if HAVE_MSTATS && HAVE_GNUMALLOC_H
     struct mstats ms = mstats();
     fprintf(debug_log, "\ttotal space in arena:  %6d KB\n",
-	ms.bytes_total >> 10);
+	(int) (ms.bytes_total >> 10));
     fprintf(debug_log, "\tTotal free:            %6d KB %d%%\n",
-	ms.bytes_free >> 10,
+	(int) (ms.bytes_free >> 10),
 	percent(ms.bytes_free, ms.bytes_total));
 #elif HAVE_MALLINFO
     struct mallinfo mp;
