    }
    if (entry->swap_status != NO_SWAP)
	fatal_dump("neighborsUdpPing: bad swap_status");
    mem->w_rtt = 0;
    mem->e_pings_closest_parent = NULL;
    mem->p_rtt = 0;
    mem->start_ping = current_time;
    mem->icp_reply_callback = callback;
    mem->ircb_data = callback_data;
