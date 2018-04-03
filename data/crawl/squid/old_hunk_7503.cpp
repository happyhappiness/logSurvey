	    debug(15, 1, "Ignoring DECHO from non-neighbor %s\n",
		inet_ntoa(from->sin_addr));
	} else if (e->type == EDGE_SIBLING) {
	    fatal_dump("neighborsUdpAck: Found non-ICP cache as SIBLING\n");
	} else {
	    w_rtt = tvSubMsec(mem->start_ping, current_time) / e->weight;
	    if (mem->w_rtt == 0 || w_rtt < mem->w_rtt) {