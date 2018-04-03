 
     if (Config.peers == NULL)
 	return 0;
-    if (theOutIcpConnection < 0) {
-	debug(15, 0) ("neighborsUdpPing: There is no ICP socket!\n");
-	debug(15, 0) ("Cannot query neighbors for '%s'.\n", url);
-	debug(15, 0) ("Check 'icp_port' in your config file\n");
-	fatal_dump(NULL);
-    }
+    if (theOutIcpConnection < 0)
+	fatal("neighborsUdpPing: There is no ICP socket!");
     assert(entry->swap_status == SWAPOUT_NONE);
     mem->start_ping = current_time;
     mem->icp_reply_callback = callback;
