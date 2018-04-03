        saved_offset = offset;

        for (router_list_ptr = &service_list_ptr->router_list_head; router_list_ptr->next != NULL; router_list_ptr = router_list_ptr->next) {
	    unsigned long *weight = (unsigned long *)xcalloc(sizeof(*weight), ntohl(router_list_ptr->num_caches));
	    unsigned long total_weight = 0;
	    int num_caches = ntohl(router_list_ptr->num_caches);

            offset = saved_offset;

            /* Number of caches */
            xmemcpy(&wccp_packet[offset], &router_list_ptr->num_caches, sizeof(router_list_ptr->num_caches));
            offset += sizeof(router_list_ptr->num_caches);

	    if (num_caches) {
		int cache;
		for (cache = 0, cache_list_ptr = &router_list_ptr->cache_list_head; cache_list_ptr->next; cache_list_ptr = cache_list_ptr->next, cache++) {
                    /* add caches */

                    cache_address = (struct IN_ADDR *) &wccp_packet[offset];

                    xmemcpy(cache_address, &cache_list_ptr->cache_ip, sizeof(struct IN_ADDR));
		    total_weight += cache_list_ptr->weight << 12;
		    weight[cache] = cache_list_ptr->weight << 12;
                    offset += sizeof(struct IN_ADDR);
                }
            }

            /* Add buckets */
            buckets = (char *) &wccp_packet[offset];

            memset(buckets, '\0', WCCP_BUCKETS);

	    if (num_caches != 0) {
		if (total_weight == 0) {
		    for (bucket_counter = 0; bucket_counter < WCCP_BUCKETS; bucket_counter++) {
			buckets[bucket_counter] = (char) (bucket_counter % num_caches);
		    }
		} else {
		    unsigned long *assigned = (unsigned long *)xcalloc(sizeof(*assigned), num_caches);
		    unsigned long done = 0;
		    int cache = -1;
		    unsigned long per_bucket = total_weight / WCCP_BUCKETS;
		    for (bucket_counter = 0; bucket_counter < WCCP_BUCKETS; bucket_counter++) {
			int n;
			unsigned long step;
			for (n = num_caches; n; n--) {
			    cache++;
			    if (cache >= num_caches)
				cache = 0;
			    if (!weight[cache]) {
				n++;
				continue;
			    }
			    if (assigned[cache] <= done)
				break;
			}
			buckets[bucket_counter] = (char)cache;
			step = per_bucket * total_weight / weight[cache];
			assigned[cache] += step;
			done += per_bucket;
		    }
		    safe_free(assigned);
		}
	    }
	    offset += (WCCP_BUCKETS * sizeof(char));
	    safe_free(weight);

            /* Fill in length */

            assignment_header->length = htons(sizeof(struct assignment_key_t) + sizeof(service_list_ptr->num_routers) +

                                              (ntohl(service_list_ptr->num_routers) * sizeof(struct wccp2_router_assign_element_t)) +

                                              sizeof                        (router_list_ptr->num_caches) + (ntohl(router_list_ptr->num_caches) * sizeof(struct IN_ADDR)) +
                                              (WCCP_BUCKETS * sizeof(char)));

            /* Fill in assignment key */
            assignment_key->master_ip = router_list_ptr->local_ip;
