    int n;
    HttpStateData *httpState = NULL;

    debug(15, 6, "neighborsUdpAck: opcode %d '%s'\n",
	(int) header->opcode, url);
    if (header->opcode > ICP_OP_END)
	return;
    if (mem == NULL) {
	debug(15, 1, "Ignoring ICP reply for missing mem_obj: %s\n", url);
	return;
    }
    if ((e = whichEdge(header, from))) {
	/* Neighbor is alive, reset the ack deficit */
	if (e->stats.ack_deficit >= HIER_MAX_DEFICIT) {
	    debug(15, 0, "neighborsUdpAck: Detected REVIVED %s: %s\n",
		e->type == EDGE_SIBLING ? "SIBLING" : "PARENT",
		e->host);
	}
	e->neighbor_up = 1;
	e->stats.ack_deficit = 0;
	n = ++e->stats.pings_acked;
	e->stats.counts[header->opcode]++;
	if (n > RTT_AV_FACTOR)
	    n = RTT_AV_FACTOR;
	rtt = tvSubMsec(mem->start_ping, current_time);
	e->stats.rtt = (e->stats.rtt * (n - 1) + rtt) / n;
    }
    /* check if someone is already fetching it */
    if (BIT_TEST(entry->flag, ENTRY_DISPATCHED)) {
	debug(15, 5, "neighborsUdpAck: '%s' already being fetched.\n", url);
	return;
    }
    if (entry->ping_status != PING_WAITING) {
	debug(15, 5, "neighborsUdpAck: '%s' unexpected ICP reply.\n", url);
	return;
    }
    debug(15, 3, "neighborsUdpAck: %s for '%s' from %s \n",
	IcpOpcodeStr[header->opcode], url, e ? e->host : "source");

    mem->e_pings_n_acks++;
    if (header->opcode == ICP_OP_SECHO) {
	/* Received source-ping reply */
	if (e) {
	    debug(15, 1, "neighborsUdpAck: Ignoring SECHO from %s\n", e->host);
	} else {
	    /* if we reach here, source-ping reply is the first 'parent',
	     * so fetch directly from the source */
	    debug(15, 6, "Source is the first to respond.\n");
	    hierarchy_log_append(entry,
		HIER_SOURCE_FASTEST,
		0,
		inet_ntoa(from->sin_addr));
	    BIT_SET(entry->flag, ENTRY_DISPATCHED);
	    entry->ping_status = PING_DONE;
	    getFromCache(0, entry, NULL, entry->mem_obj->request);
	    return;
	}
    } else if (header->opcode == ICP_OP_HIT_OBJ) {
	if (entry->object_len != 0) {
	    debug(15, 1, "Too late UDP_HIT_OBJ '%s'?\n", entry->url);
	} else {
	    protoCancelTimeout(0, entry);
	    entry->ping_status = PING_DONE;
	    httpState = xcalloc(1, sizeof(HttpStateData));
	    httpState->entry = entry;
	    httpProcessReplyHeader(httpState, data, data_sz);
	    storeAppend(entry, data, data_sz);
	    storeComplete(entry);
	    hierarchy_log_append(entry,
		HIER_UDP_HIT_OBJ,
		0,
		e ? e->host : inet_ntoa(from->sin_addr));
	    if (httpState->reply_hdr)
		put_free_8k_page(httpState->reply_hdr);
	    safe_free(httpState);
	    return;
	}
    } else if (header->opcode == ICP_OP_HIT) {
	if (e == NULL) {
	    debug(15, 1, "neighborsUdpAck: Ignoring HIT from non-neighbor\n");
	} else {
	    hierarchy_log_append(entry,
		e->type == EDGE_SIBLING ? HIER_NEIGHBOR_HIT : HIER_PARENT_HIT,
		0,
		e->host);
	    BIT_SET(entry->flag, ENTRY_DISPATCHED);
	    entry->ping_status = PING_DONE;
	    getFromCache(0, entry, e, entry->mem_obj->request);
	    return;
	}
    } else if (header->opcode == ICP_OP_DECHO) {
	if (e == NULL) {
	    debug(15, 1, "neighborsUdpAck: Ignoring DECHO from non-neighbor\n");
	} else if (e->type == EDGE_SIBLING) {
	    fatal_dump("neighborsUdpAck: Found non-ICP cache as SIBLING\n");
	} else {
	    w_rtt = tvSubMsec(mem->start_ping, current_time) / e->weight;
	    if (mem->w_rtt == 0 || w_rtt < mem->w_rtt) {
		mem->e_pings_first_miss = e;
		mem->w_rtt = w_rtt;
	    }
	}
    } else if (header->opcode == ICP_OP_MISS) {
	if (e == NULL) {
	    debug(15, 1, "neighborsUdpAck: Ignoring MISS from non-neighbor\n");
	} else if (e->type == EDGE_PARENT) {
	    w_rtt = tvSubMsec(mem->start_ping, current_time) / e->weight;
	    if (mem->w_rtt == 0 || w_rtt < mem->w_rtt) {
		mem->e_pings_first_miss = e;
		mem->w_rtt = w_rtt;
	    }
	}
    } else if (header->opcode == ICP_OP_DENIED) {
	if (e == NULL) {
	    debug(15, 1, "neighborsUdpAck: Ignoring DENIED from non-neighbor\n");
	} else if (e->stats.pings_acked > 100) {
	    if (100 * e->stats.counts[ICP_OP_DENIED] / e->stats.pings_acked > 95) {
		debug(15, 0, "95%% of replies from '%s' are UDP_DENIED\n", e->host);
		debug(15, 0, "Disabling '%s', please check your configuration.\n", e->host);
		neighborRemove(e);
	    }
	}
    } else {
	debug(15, 0, "neighborsUdpAck: Unexpected ICP reply: %s\n",
	    IcpOpcodeStr[header->opcode]);
    }
    if (mem->e_pings_n_acks == mem->e_pings_n_pings) {
	BIT_SET(entry->flag, ENTRY_DISPATCHED);
	entry->ping_status = PING_DONE;
	debug(15, 6, "neighborsUdpAck: All replies received.\n");
	/* pass in fd=0 here so getFromCache() looks up the real FD
	 * and resets the timeout handler */
	getFromDefaultSource(0, entry);
	return;
    }
}

