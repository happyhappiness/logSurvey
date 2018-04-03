 
     /* Now send the packet and sit back ... */
 
-    if (RFCNB_Send(Con_Handle->Trans_Connect, pkt, pkt_len) < 0) {
+    if (RFCNB_Send(Con_Handle -> Trans_Connect, pkt, pkt_len) < 0) {
 
 #ifdef DEBUG
         fprintf(stderr, "Error sending TCon request\n");
