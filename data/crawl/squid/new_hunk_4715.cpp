            router.sin_addr = router_list_ptr->router_sendto_address;

            /* Set the cache id (ip) */

            switch (Config.Wccp2.assignment_method) {

            case WCCP2_ASSIGNMENT_METHOD_HASH:

                wccp2_identity_info_ptr = (struct wccp2_identity_info_t *) service_list_ptr->wccp2_identity_info_ptr;
                wccp2_identity_info_ptr->cache_identity.addr = router_list_ptr->local_ip;
                break;

            case WCCP2_ASSIGNMENT_METHOD_MASK:

                wccp2_mask_identity_info_ptr = (struct wccp2_mask_identity_info_t *) service_list_ptr->wccp2_identity_info_ptr;
                wccp2_mask_identity_info_ptr->cache_identity.addr = router_list_ptr->local_ip;
                break;

            default:
                fatalf("Unknown Wccp2 assignment method\n");
            }

            /* Security update, if needed */

            if (service_list_ptr->wccp2_security_type == WCCP2_MD5_SECURITY) {
