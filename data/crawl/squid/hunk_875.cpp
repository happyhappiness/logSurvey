     if (_callback.pending())
         return;
 
-    output->Printf("\tClient #%d, %p\n", clientNumber, _callback.callback_data);
-
-    output->Printf("\t\tcopy_offset: %" PRId64 "\n",
-                   copyInto.offset);
-
-    output->Printf("\t\tcopy_size: %d\n",
-                   (int) copyInto.length);
-
-    output->Printf("\t\tflags:");
+    output->appendf("\tClient #%d, %p\n", clientNumber, _callback.callback_data);
+    output->appendf("\t\tcopy_offset: %" PRId64 "\n", copyInto.offset);
+    output->appendf("\t\tcopy_size: %d\n", copyInto.length);
+    output->append("\t\tflags:", 8);
 
     if (flags.disk_io_pending)
-        output->Printf(" disk_io_pending");
+        output->append(" disk_io_pending", 16);
 
     if (flags.store_copying)
-        output->Printf(" store_copying");
+        output->append(" store_copying", 14);
 
     if (flags.copy_event_pending)
-        output->Printf(" copy_event_pending");
+        output->append(" copy_event_pending", 19);
 
-    output->Printf("\n");
+    output->append("\n",1);
 }
 
 bool
