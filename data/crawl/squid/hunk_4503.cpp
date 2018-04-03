 
     output->Printf("\tClient #%d, %p\n", clientNumber, _callback.callback_data);
 
-    output->Printf("\t\tcopy_offset: %lu\n",
-                   (unsigned long) copyInto.offset);
+    output->Printf("\t\tcopy_offset: %"PRId64"\n",
+                   copyInto.offset);
 
     output->Printf("\t\tcopy_size: %d\n",
                    (int) copyInto.length);
