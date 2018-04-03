         saved_offset = offset;
 
         for (router_list_ptr = &service_list_ptr->router_list_head; router_list_ptr->next != NULL; router_list_ptr = router_list_ptr->next) {
-	    unsigned long *weight = (unsigned long *)xcalloc(sizeof(*weight), ntohl(router_list_ptr->num_caches));
-	    unsigned long total_weight = 0;
-	    int num_caches = ntohl(router_list_ptr->num_caches);
+            unsigned long *weight = (unsigned long *)xcalloc(sizeof(*weight), ntohl(router_list_ptr->num_caches));
+            unsigned long total_weight = 0;
+            int num_caches = ntohl(router_list_ptr->num_caches);
 
             offset = saved_offset;
 
-            /* Number of caches */
-            xmemcpy(&wccp_packet[offset], &router_list_ptr->num_caches, sizeof(router_list_ptr->num_caches));
-            offset += sizeof(router_list_ptr->num_caches);
+            switch (Config.Wccp2.assignment_method) {
+
+            case WCCP2_ASSIGNMENT_METHOD_HASH:
+                /* Number of caches */
+                xmemcpy(&wccp_packet[offset], &router_list_ptr->num_caches, sizeof(router_list_ptr->num_caches));
+                offset += sizeof(router_list_ptr->num_caches);
+
+                if (num_caches) {
+                    int cache;
+
+                    for (cache = 0, cache_list_ptr = &router_list_ptr->cache_list_head; cache_list_ptr->next; cache_list_ptr = cache_list_ptr->next, cache++) {
+                        /* add caches */
 
-	    if (num_caches) {
-		int cache;
-		for (cache = 0, cache_list_ptr = &router_list_ptr->cache_list_head; cache_list_ptr->next; cache_list_ptr = cache_list_ptr->next, cache++) {
-                    /* add caches */
+                        cache_address = (struct IN_ADDR *) &wccp_packet[offset];
 
-                    cache_address = (struct IN_ADDR *) &wccp_packet[offset];
+                        xmemcpy(cache_address, &cache_list_ptr->cache_ip, sizeof(struct IN_ADDR));
+                        total_weight += cache_list_ptr->weight << 12;
+                        weight[cache] = cache_list_ptr->weight << 12;
 
-                    xmemcpy(cache_address, &cache_list_ptr->cache_ip, sizeof(struct IN_ADDR));
-		    total_weight += cache_list_ptr->weight << 12;
-		    weight[cache] = cache_list_ptr->weight << 12;
-                    offset += sizeof(struct IN_ADDR);
+                        offset += sizeof(struct IN_ADDR);
+                    }
                 }
-            }
 
-            /* Add buckets */
-            buckets = (char *) &wccp_packet[offset];
-
-            memset(buckets, '\0', WCCP_BUCKETS);
-
-	    if (num_caches != 0) {
-		if (total_weight == 0) {
-		    for (bucket_counter = 0; bucket_counter < WCCP_BUCKETS; bucket_counter++) {
-			buckets[bucket_counter] = (char) (bucket_counter % num_caches);
-		    }
-		} else {
-		    unsigned long *assigned = (unsigned long *)xcalloc(sizeof(*assigned), num_caches);
-		    unsigned long done = 0;
-		    int cache = -1;
-		    unsigned long per_bucket = total_weight / WCCP_BUCKETS;
-		    for (bucket_counter = 0; bucket_counter < WCCP_BUCKETS; bucket_counter++) {
-			int n;
-			unsigned long step;
-			for (n = num_caches; n; n--) {
-			    cache++;
-			    if (cache >= num_caches)
-				cache = 0;
-			    if (!weight[cache]) {
-				n++;
-				continue;
-			    }
-			    if (assigned[cache] <= done)
-				break;
-			}
-			buckets[bucket_counter] = (char)cache;
-			step = per_bucket * total_weight / weight[cache];
-			assigned[cache] += step;
-			done += per_bucket;
-		    }
-		    safe_free(assigned);
-		}
-	    }
-	    offset += (WCCP_BUCKETS * sizeof(char));
-	    safe_free(weight);
+                /* Add buckets */
+                buckets = (char *) &wccp_packet[offset];
+
+                memset(buckets, '\0', WCCP_BUCKETS);
+
+                if (num_caches != 0) {
+                    if (total_weight == 0) {
+                        for (bucket_counter = 0; bucket_counter < WCCP_BUCKETS; bucket_counter++) {
+                            buckets[bucket_counter] = (char) (bucket_counter % num_caches);
+                        }
+                    } else {
+                        unsigned long *assigned = (unsigned long *)xcalloc(sizeof(*assigned), num_caches);
+                        unsigned long done = 0;
+                        int cache = -1;
+                        unsigned long per_bucket = total_weight / WCCP_BUCKETS;
+
+                        for (bucket_counter = 0; bucket_counter < WCCP_BUCKETS; bucket_counter++) {
+                            int n;
+                            unsigned long step;
+
+                            for (n = num_caches; n; n--) {
+                                cache++;
+
+                                if (cache >= num_caches)
+                                    cache = 0;
+
+                                if (!weight[cache]) {
+                                    n++;
+                                    continue;
+                                }
+
+                                if (assigned[cache] <= done)
+                                    break;
+                            }
+
+                            buckets[bucket_counter] = (char) cache;
+                            step = per_bucket * total_weight / weight[cache];
+                            assigned[cache] += step;
+                            done += per_bucket;
+                        }
+
+                        safe_free(assigned);
+                    }
+                }
 
-            /* Fill in length */
+                offset += (WCCP_BUCKETS * sizeof(char));
+                safe_free(weight);
+                break;
 
-            assignment_header->length = htons(sizeof(struct assignment_key_t) + sizeof(service_list_ptr->num_routers) +
+            case WCCP2_ASSIGNMENT_METHOD_MASK:
+                num_maskval = htonl(1);
+                xmemcpy(&wccp_packet[offset], &num_maskval, sizeof(int));
+                offset += sizeof(int);
+
+                mask_element = (struct wccp2_mask_element_t *) &wccp_packet[offset];
+                service_flags = ntohl(service_list_ptr->service_info->service_flags);
+
+                if ((service_flags & WCCP2_SERVICE_SRC_IP_HASH) || (service_flags & WCCP2_SERVICE_SRC_IP_ALT_HASH)) {
+                    mask_element->source_ip_mask = htonl(0x00001741);
+                    mask_element->dest_ip_mask = 0;
+                    mask_element->source_port_mask = 0;
+                    mask_element->dest_port_mask = 0;
+                } else if ((service_list_ptr->info.service == WCCP2_SERVICE_STANDARD) || (service_flags & WCCP2_SERVICE_DST_IP_HASH) || (service_flags & WCCP2_SERVICE_DST_IP_ALT_HASH)) {
+                    mask_element->source_ip_mask = 0;
+                    mask_element->dest_ip_mask = htonl(0x00001741);
+                    mask_element->source_port_mask = 0;
+                    mask_element->dest_port_mask = 0;
+                } else if ((service_flags & WCCP2_SERVICE_SRC_PORT_HASH) || (service_flags & WCCP2_SERVICE_SRC_PORT_ALT_HASH)) {
+                    mask_element->source_ip_mask = 0;
+                    mask_element->dest_ip_mask = 0;
+                    mask_element->source_port_mask = htons(0x1741);
+                    mask_element->dest_port_mask = 0;
+                } else if ((service_flags & WCCP2_SERVICE_DST_PORT_HASH) || (service_flags & WCCP2_SERVICE_DST_PORT_ALT_HASH)) {
+                    mask_element->source_ip_mask = 0;
+                    mask_element->dest_ip_mask = 0;
+                    mask_element->source_port_mask = 0;
+                    mask_element->dest_port_mask = htons(0x1741);
+                } else {
+                    fatalf("Unknown service hash method\n");
+                }
+
+                mask_element->number_values = htonl(64);
+
+                offset += sizeof(struct wccp2_mask_element_t);
+
+                cache_list_ptr = &router_list_ptr->cache_list_head;
+                value = 0;
+
+                for (valuecounter = 0; valuecounter < 64; valuecounter++) {
+
+                    value_element = (struct wccp2_value_element_t *) &wccp_packet[offset];
+
+                    if ((service_flags & WCCP2_SERVICE_SRC_IP_HASH) || (service_flags & WCCP2_SERVICE_SRC_IP_ALT_HASH)) {
+                        value_element->source_ip_value = htonl(value);
+                        value_element->dest_ip_value = 0;
+                        value_element->source_port_value = 0;
+                        value_element->dest_port_value = 0;
+                    } else if ((service_list_ptr->info.service == WCCP2_SERVICE_STANDARD) || (service_flags & WCCP2_SERVICE_DST_IP_HASH) || (service_flags & WCCP2_SERVICE_DST_IP_ALT_HASH)) {
+                        value_element->source_ip_value = 0;
+                        value_element->dest_ip_value = htonl(value);
+                        value_element->source_port_value = 0;
+                        value_element->dest_port_value = 0;
+                    } else if ((service_flags & WCCP2_SERVICE_SRC_PORT_HASH) || (service_flags & WCCP2_SERVICE_SRC_PORT_ALT_HASH)) {
+                        value_element->source_ip_value = 0;
+                        value_element->dest_ip_value = 0;
+                        value_element->source_port_value = htons(value);
+                        value_element->dest_port_value = 0;
+                    } else if ((service_flags & WCCP2_SERVICE_DST_PORT_HASH) || (service_flags & WCCP2_SERVICE_DST_PORT_ALT_HASH)) {
+                        value_element->source_ip_value = 0;
+                        value_element->dest_ip_value = 0;
+                        value_element->source_port_value = 0;
+                        value_element->dest_port_value = htons(value);
+                    } else {
+                        fatalf("Unknown service hash method\n");
+                    }
+
+                    value_element->cache_ip = cache_list_ptr->cache_ip;
+
+                    offset += sizeof(struct wccp2_value_element_t);
+
+                    /* Update the value according the the "correct" formula */
+
+                    for (value++; (value & 0x1741) != value; value++) {
+                        assert(value <= 0x1741);
+                    }
+
+                    /* Assign the next value to the next cache */
+                    if ((cache_list_ptr->next) && (cache_list_ptr->next->next))
+                        cache_list_ptr = cache_list_ptr->next;
+                    else
+                        cache_list_ptr = &router_list_ptr->cache_list_head;
+                }
 
-                                              (ntohl(service_list_ptr->num_routers) * sizeof(struct wccp2_router_assign_element_t)) +
+                /* Fill in length */
+                alt_assignment_type_header->length = htons(offset - alt_assignment_offset);
+
+                break;
+
+            default:
+                fatalf("Unknown Wccp2 assignment method\n");
+            }
+
+            /* Fill in length */
 
-                                              sizeof                        (router_list_ptr->num_caches) + (ntohl(router_list_ptr->num_caches) * sizeof(struct IN_ADDR)) +
-                                              (WCCP_BUCKETS * sizeof(char)));
+            assignment_header->length = htons(offset - assignment_offset);
 
             /* Fill in assignment key */
             assignment_key->master_ip = router_list_ptr->local_ip;
