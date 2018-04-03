     if (entry->swap_status != NO_SWAP)
 	fatal_dump("neighborsUdpPing: bad swap_status");
 
-    mem->e_pings_n_pings = 0;
-    mem->e_pings_n_acks = 0;
-    mem->e_pings_first_miss = NULL;
-    mem->w_rtt = 0;
-    mem->start_ping = current_time;
-
     for (i = 0, e = Peers.first_ping; i++ < Peers.n; e = e->next) {
 	if (e == NULL)
 	    e = Peers.peers_head;
