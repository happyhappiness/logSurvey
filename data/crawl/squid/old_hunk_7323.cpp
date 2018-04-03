    }
    if (entry->swap_status != NO_SWAP)
	fatal_dump("neighborsUdpPing: bad swap_status");
    mem->start_ping = current_time;
    mem->icp_reply_callback = callback;
    mem->ircb_data = callback_data;
