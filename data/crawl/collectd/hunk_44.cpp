       return -1;
     }
 
-    int status = lcc_network_parse(buffer, buffer_size, nop_writer);
+    int status =
+        lcc_network_parse(buffer, buffer_size, (lcc_network_parse_options_t){
+                                                   .writer = nop_writer,
+                                               });
     if (status != 0) {
       fprintf(stderr, "lcc_network_parse(raw_packet_data[%zu]) = %d, want 0\n",
               i, status);
