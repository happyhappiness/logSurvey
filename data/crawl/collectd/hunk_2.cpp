                                                    .writer = nop_writer,
                                                });
     if (status != 0) {
-      fprintf(stderr, "lcc_network_parse(raw_packet_data[%zu]) = %d, want 0\n",
+      fprintf(stderr,
+              "lcc_network_parse(raw_packet_data[%" PRIsz "]) = %d, want 0\n",
               i, status);
       ret = status;
     }
 
-    printf("ok - lcc_network_parse(raw_packet_data[%zu])\n", i);
+    printf("ok - lcc_network_parse(raw_packet_data[%" PRIsz "])\n", i);
   }
 
   return ret;
