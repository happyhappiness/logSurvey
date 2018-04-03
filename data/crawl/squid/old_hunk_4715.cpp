            router.sin_addr = router_list_ptr->router_sendto_address;

            /* Set the cache id (ip) */
            service_list_ptr->wccp2_identity_info_ptr->cache_identity.addr = router_list_ptr->local_ip;
            /* Security update, if needed */

            if (service_list_ptr->wccp2_security_type == WCCP2_MD5_SECURITY) {
