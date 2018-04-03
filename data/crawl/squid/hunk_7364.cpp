     }
     if (entry->swap_status != NO_SWAP)
 	fatal_dump("neighborsUdpPing: bad swap_status");
-
+    mem->start_ping = current_time;
+    mem->icp_reply_callback = callback;
+    mem->ircb_data = callback_data;
     for (i = 0, e = Peers.first_ping; i++ < Peers.n; e = e->next) {
 	if (e == NULL)
 	    e = Peers.peers_head;
