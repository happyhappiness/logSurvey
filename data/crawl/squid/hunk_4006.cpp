     if (Config.peers == NULL)
         return 0;
 
-    if (theOutIcpConnection < 0)
-        fatal("neighborsUdpPing: There is no ICP socket!");
-
     assert(entry->swap_status == SWAPOUT_NONE);
 
     mem->start_ping = current_time;
