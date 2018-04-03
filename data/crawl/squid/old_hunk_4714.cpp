        for (num_caches = 0; num_caches < (int) ntohl(tmp); num_caches++) {
            /* Get a copy of the ip */

            cache_identity = (struct wccp2_cache_identity_info_t *) ptr;

            ptr += sizeof(struct wccp2_cache_identity_info_t);

            memcpy(&cache_address, &cache_identity->addr, sizeof(struct IN_ADDR));

            /* Update the cache list */
            cache_list_ptr->cache_ip = cache_address;
	    cache_list_ptr->weight = ntohs(cache_identity->weight);
            cache_list_ptr->next = (wccp2_cache_list_t*) xcalloc(1, sizeof(struct wccp2_cache_list_t));
            cache_list_ptr = cache_list_ptr->next;
            cache_list_ptr->next = NULL;

            debug(80, 5) ("checking cache list: (%x:%x)\n", cache_address.s_addr, router_list_ptr->local_ip.s_addr);
            /* Check to see if it's the master, or us */

            if (cache_address.s_addr == router_list_ptr->local_ip.s_addr) {
