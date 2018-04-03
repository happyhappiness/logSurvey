         for (num_caches = 0; num_caches < (int) ntohl(tmp); num_caches++) {
             /* Get a copy of the ip */
 
-            cache_identity = (struct wccp2_cache_identity_info_t *) ptr;
+            switch (Config.Wccp2.assignment_method) {
+
+            case WCCP2_ASSIGNMENT_METHOD_HASH:
+
+                cache_identity = (struct wccp2_cache_identity_info_t *) ptr;
+
+                ptr += sizeof(struct wccp2_cache_identity_info_t);
+
+                memcpy(&cache_address, &cache_identity->addr, sizeof(struct IN_ADDR));
+
+                cache_list_ptr->weight = ntohs(cache_identity->weight);
+                break;
+
+            case WCCP2_ASSIGNMENT_METHOD_MASK:
+
+                cache_mask_info = (struct cache_mask_info_t *) ptr;
+
+                /* The mask assignment has an undocumented variable length entry here */
+
+                if (ntohl(cache_mask_info->num1) == 3) {
+
+                    cache_mask_identity = (struct wccp2_cache_mask_identity_info_t *) ptr;
+
+                    ptr += sizeof(struct wccp2_cache_mask_identity_info_t);
 
-            ptr += sizeof(struct wccp2_cache_identity_info_t);
+                    memcpy(&cache_address, &cache_mask_identity->addr, sizeof(struct IN_ADDR));
+                } else {
+
+                    ptr += sizeof(struct cache_mask_info_t);
+
+                    memcpy(&cache_address, &cache_mask_info->addr, sizeof(struct IN_ADDR));
+                }
 
-            memcpy(&cache_address, &cache_identity->addr, sizeof(struct IN_ADDR));
+                cache_list_ptr->weight = 0;
+                break;
+
+            default:
+                fatalf("Unknown Wccp2 assignment method\n");
+            }
 
             /* Update the cache list */
             cache_list_ptr->cache_ip = cache_address;
-	    cache_list_ptr->weight = ntohs(cache_identity->weight);
+
             cache_list_ptr->next = (wccp2_cache_list_t*) xcalloc(1, sizeof(struct wccp2_cache_list_t));
+
             cache_list_ptr = cache_list_ptr->next;
+
             cache_list_ptr->next = NULL;
 
             debug(80, 5) ("checking cache list: (%x:%x)\n", cache_address.s_addr, router_list_ptr->local_ip.s_addr);
+
             /* Check to see if it's the master, or us */
 
             if (cache_address.s_addr == router_list_ptr->local_ip.s_addr) {
