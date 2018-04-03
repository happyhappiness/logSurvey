     int n;
     HttpStateData *httpState = NULL;
 
-    debug(15, 6, "neighborsUdpAck: url=%s (%d chars), header=0x%x, from=0x%x, ent=0x%x\n",
-	url, strlen(url), header, from, entry);
-    debug(15, 6, "     hdr: opcode=%d, ver=%d, shostid=%x, len=%d, rn=0x%x\n",
-	header->opcode, header->version, header->shostid,
-	header->length, header->reqnum);
-    debug(15, 6, "     from: fam=%d, port=%d, addr=0x%x\n",
-	ntohs(from->sin_family),
-	ntohs(from->sin_port),
-	ntohl(from->sin_addr.s_addr));
-
-    /* look up for neighbor/parent entry */
-    e = whichEdge(header, from);
-
-    if (e) {
-	/* reset the deficit. It's alive now. */
-	/* Don't care about exact count. */
-	if ((e->stats.ack_deficit >= HIER_MAX_DEFICIT)) {
-	    if (e->type == EDGE_SIBLING) {
-		hierarchy_log_append("Detect: ",
-		    HIER_REVIVE_NEIGHBOR, 0, e->host);
-	    } else {
-		hierarchy_log_append("Detect: ",
-		    HIER_REVIVE_PARENT, 0, e->host);
-	    }
+    debug(15, 6, "neighborsUdpAck: opcode %d '%s'\n",
+	(int) header->opcode, url);
+    if (header->opcode > ICP_OP_END)
+	return;
+    if (mem == NULL) {
+	debug(15, 1, "Ignoring ICP reply for missing mem_obj: %s\n", url);
+	return;
+    }
+    if ((e = whichEdge(header, from))) {
+	/* Neighbor is alive, reset the ack deficit */
+	if (e->stats.ack_deficit >= HIER_MAX_DEFICIT) {
+	    debug(15, 0, "neighborsUdpAck: Detected REVIVED %s: %s\n",
+		e->type == EDGE_SIBLING ? "SIBLING" : "PARENT",
+		e->host);
 	}
 	e->neighbor_up = 1;
 	e->stats.ack_deficit = 0;
 	n = ++e->stats.pings_acked;
-	if (header->opcode < ICP_OP_END)
-	    e->stats.counts[header->opcode]++;
-	if (mem) {
-	    if (n > RTT_AV_FACTOR)
-		n = RTT_AV_FACTOR;
-	    rtt = tvSubMsec(mem->start_ping, current_time);
-	    e->stats.rtt = (e->stats.rtt * (n - 1) + rtt) / n;
-	}
+	e->stats.counts[header->opcode]++;
+	if (n > RTT_AV_FACTOR)
+	    n = RTT_AV_FACTOR;
+	rtt = tvSubMsec(mem->start_ping, current_time);
+	e->stats.rtt = (e->stats.rtt * (n - 1) + rtt) / n;
     }
     /* check if someone is already fetching it */
-    if (BIT_TEST(entry->flag, ENTRY_DISPATCHED) || (entry->ping_status != PING_WAITING)) {
-	if (entry->ping_status == PING_DONE) {
-	    debug(15, 5, "There is already a cache/source dispatched for this object\n");
-	    debug(15, 5, "--> <URL:%s>\n", entry->url);
-	    debug(15, 5, "--> entry->flag & ENTRY_DISPATCHED = %d\n",
-		BIT_TEST(entry->flag, ENTRY_DISPATCHED));
-	    debug(15, 5, "--> entry->ping_status = %d\n", entry->ping_status);
-	} else {
-	    debug(15, 5, "The ping already timed out.\n");
-	    debug(15, 5, "--> <URL:%s>\n", entry->url);
-	    debug(15, 5, "--> entry->flag & ENTRY_DISPATCHED = %lx\n",
-		BIT_TEST(entry->flag, ENTRY_DISPATCHED));
-	    debug(15, 5, "--> entry->ping_status = %d\n", entry->ping_status);
-	}
+    if (BIT_TEST(entry->flag, ENTRY_DISPATCHED)) {
+	debug(15, 5, "neighborsUdpAck: '%s' already being fetched.\n", url);
+	return;
+    }
+    if (entry->ping_status != PING_WAITING) {
+	debug(15, 5, "neighborsUdpAck: '%s' unexpected ICP reply.\n", url);
 	return;
     }
-    debug(15, 6, "neighborsUdpAck - url: %s to us %s \n",
-	url, e ? inet_ntoa(e->in_addr.sin_addr) : "url-host");
+    debug(15, 3, "neighborsUdpAck: %s for '%s' from %s \n",
+	IcpOpcodeStr[header->opcode], url, e ? e->host : "source");
 
+    mem->e_pings_n_acks++;
     if (header->opcode == ICP_OP_SECHO) {
-	/* receive ping back from source or from non-ICP cache */
+	/* Received source-ping reply */
 	if (e) {
-	    debug(15, 6, "Got SECHO from non-ICP cache:%s\n",
-		inet_ntoa(e->in_addr.sin_addr));
-	    debug(15, 6, "This is not supposed to happen.  Ignored.\n");
+	    debug(15, 1, "neighborsUdpAck: Ignoring SECHO from %s\n", e->host);
 	} else {
-	    /* if we reach here, source is the one has the fastest respond. */
-	    /* fetch directly from source */
+	    /* if we reach here, source-ping reply is the first 'parent',
+	     * so fetch directly from the source */
 	    debug(15, 6, "Source is the first to respond.\n");
-	    hierarchy_log_append(entry->url,
+	    hierarchy_log_append(entry,
 		HIER_SOURCE_FASTEST,
 		0,
 		inet_ntoa(from->sin_addr));
-	    if (mem)
-		mem->hierarchy_code = HIER_SOURCE_FASTEST;
 	    BIT_SET(entry->flag, ENTRY_DISPATCHED);
 	    entry->ping_status = PING_DONE;
 	    getFromCache(0, entry, NULL, entry->mem_obj->request);
+	    return;
 	}
-	return;
     } else if (header->opcode == ICP_OP_HIT_OBJ) {
 	if (entry->object_len != 0) {
-	    debug(15, 0, "Too late UDP_HIT_OBJ '%s'?\n", entry->url);
+	    debug(15, 1, "Too late UDP_HIT_OBJ '%s'?\n", entry->url);
+	} else {
+	    protoCancelTimeout(0, entry);
+	    entry->ping_status = PING_DONE;
+	    httpState = xcalloc(1, sizeof(HttpStateData));
+	    httpState->entry = entry;
+	    httpProcessReplyHeader(httpState, data, data_sz);
+	    storeAppend(entry, data, data_sz);
+	    storeComplete(entry);
+	    hierarchy_log_append(entry,
+		HIER_UDP_HIT_OBJ,
+		0,
+		e ? e->host : inet_ntoa(from->sin_addr));
+	    if (httpState->reply_hdr)
+		put_free_8k_page(httpState->reply_hdr);
+	    safe_free(httpState);
 	    return;
 	}
-	protoCancelTimeout(0, entry);
-	entry->ping_status = PING_DONE;
-	httpState = xcalloc(1, sizeof(HttpStateData));
-	httpState->entry = entry;
-	httpProcessReplyHeader(httpState, data, data_sz);
-	storeAppend(entry, data, data_sz);
-	storeComplete(entry);
-	hierarchy_log_append(entry->url,
-	    HIER_UDP_HIT_OBJ,
-	    0,
-	    e ? e->host : inet_ntoa(from->sin_addr));
-	if (mem)
-	    mem->hierarchy_code = HIER_UDP_HIT_OBJ;
-	if (httpState->reply_hdr)
-	    put_free_8k_page(httpState->reply_hdr);
-	safe_free(httpState);
-	return;
     } else if (header->opcode == ICP_OP_HIT) {
-	/* If an edge is not found, count it as a MISS message. */
-	if (!e) {
-	    /* count it as a MISS message */
-	    mem->e_pings_n_acks++;
+	if (e == NULL) {
+	    debug(15, 1, "neighborsUdpAck: Ignoring HIT from non-neighbor\n");
+	} else {
+	    hierarchy_log_append(entry,
+		e->type == EDGE_SIBLING ? HIER_NEIGHBOR_HIT : HIER_PARENT_HIT,
+		0,
+		e->host);
+	    BIT_SET(entry->flag, ENTRY_DISPATCHED);
+	    entry->ping_status = PING_DONE;
+	    getFromCache(0, entry, e, entry->mem_obj->request);
 	    return;
 	}
-	/* GOT a HIT here */
-	debug(15, 6, "HIT: Getting %s from host: %s\n", entry->url, e->host);
-	if (e->type == EDGE_SIBLING) {
-	    hierarchy_log_append(entry->url, HIER_NEIGHBOR_HIT, 0, e->host);
-	    if (mem)
-		mem->hierarchy_code = HIER_NEIGHBOR_HIT;
+    } else if (header->opcode == ICP_OP_DECHO) {
+	if (e == NULL) {
+	    debug(15, 1, "neighborsUdpAck: Ignoring DECHO from non-neighbor\n");
+	} else if (e->type == EDGE_SIBLING) {
+	    fatal_dump("neighborsUdpAck: Found non-ICP cache as SIBLING\n");
 	} else {
-	    hierarchy_log_append(entry->url, HIER_PARENT_HIT, 0, e->host);
-	    if (mem)
-		mem->hierarchy_code = HIER_PARENT_HIT;
-	}
-	BIT_SET(entry->flag, ENTRY_DISPATCHED);
-	entry->ping_status = PING_DONE;
-	getFromCache(0, entry, e, entry->mem_obj->request);
-	return;
-    } else if ((header->opcode == ICP_OP_MISS) || (header->opcode == ICP_OP_DECHO)) {
-	/* everytime we get here, count it as a miss */
-	mem->e_pings_n_acks++;
-
-	if (header->opcode == ICP_OP_DECHO) {
-	    /* receive ping back from non-ICP cache */
-
-	    if (e) {
-		debug(15, 6, "Got DECHO from non-ICP cache:%s\n",
-		    inet_ntoa(e->in_addr.sin_addr));
-
-		if (e->type == EDGE_PARENT) {
-		    w_rtt = tvSubMsec(mem->start_ping, current_time) / e->weight;
-		    if (mem->w_rtt == 0 || w_rtt < mem->w_rtt) {
-			debug(15, 6, "Dumb-cache has minimum weighted RTT = %d\n", w_rtt);
-			mem->e_pings_first_miss = e;
-			mem->w_rtt = w_rtt;
-		    }
-		} else {
-		    debug(15, 6, "Dumb Cached as a neighbor does not make sense.\n");
-		}
-
-
-	    } else {
-		debug(15, 6, "Got DECHO from non-ICP cache: But the host is not in the list.\n");
-		debug(15, 6, "Count it anyway.\n");
-	    }
-
-	} else if (e && e->type == EDGE_PARENT) {
-	    /* ICP_OP_MISS from a cache */
 	    w_rtt = tvSubMsec(mem->start_ping, current_time) / e->weight;
 	    if (mem->w_rtt == 0 || w_rtt < mem->w_rtt) {
 		mem->e_pings_first_miss = e;
 		mem->w_rtt = w_rtt;
 	    }
 	}
-	if (mem->e_pings_n_acks == mem->e_pings_n_pings) {
-	    BIT_SET(entry->flag, ENTRY_DISPATCHED);
-	    entry->ping_status = PING_DONE;
-	    debug(15, 6, "Receive MISSes from all neighbors and parents\n");
-	    /* pass in fd=0 here so getFromCache() looks up the real FD
-	     * and resets the timeout handler */
-	    getFromDefaultSource(0, entry);
-	    return;
+    } else if (header->opcode == ICP_OP_MISS) {
+	if (e == NULL) {
+	    debug(15, 1, "neighborsUdpAck: Ignoring MISS from non-neighbor\n");
+	} else if (e->type == EDGE_PARENT) {
+	    w_rtt = tvSubMsec(mem->start_ping, current_time) / e->weight;
+	    if (mem->w_rtt == 0 || w_rtt < mem->w_rtt) {
+		mem->e_pings_first_miss = e;
+		mem->w_rtt = w_rtt;
+	    }
 	}
     } else if (header->opcode == ICP_OP_DENIED) {
-	debug(15, 5, "neighborsUdpAck: Access denied for '%s'\n", entry->url);
-	if (e && e->stats.pings_acked > 100) {
+	if (e == NULL) {
+	    debug(15, 1, "neighborsUdpAck: Ignoring DENIED from non-neighbor\n");
+	} else if (e->stats.pings_acked > 100) {
 	    if (100 * e->stats.counts[ICP_OP_DENIED] / e->stats.pings_acked > 95) {
 		debug(15, 0, "95%% of replies from '%s' are UDP_DENIED\n", e->host);
 		debug(15, 0, "Disabling '%s', please check your configuration.\n", e->host);
 		neighborRemove(e);
 	    }
 	}
     } else {
-	debug(15, 0, "neighborsUdpAck: WHY ARE WE HERE?  header->opcode = %d\n",
-	    header->opcode);
+	debug(15, 0, "neighborsUdpAck: Unexpected ICP reply: %s\n",
+	    IcpOpcodeStr[header->opcode]);
+    }
+    if (mem->e_pings_n_acks == mem->e_pings_n_pings) {
+	BIT_SET(entry->flag, ENTRY_DISPATCHED);
+	entry->ping_status = PING_DONE;
+	debug(15, 6, "neighborsUdpAck: All replies received.\n");
+	/* pass in fd=0 here so getFromCache() looks up the real FD
+	 * and resets the timeout handler */
+	getFromDefaultSource(0, entry);
+	return;
     }
 }
 
