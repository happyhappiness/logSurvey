
        /* Add the cache identity section */

        switch (Config.Wccp2.assignment_method) {

        case WCCP2_ASSIGNMENT_METHOD_HASH:

            wccp2_here_i_am_header.length += sizeof(struct wccp2_identity_info_t);
            assert(wccp2_here_i_am_header.length <= WCCP_RESPONSE_SIZE);
            wccp2_identity_info.cache_identity_type = htons(WCCP2_WC_ID_INFO);
            wccp2_identity_info.cache_identity_length = htons(sizeof(wccp2_identity_info.cache_identity));
            memset(&wccp2_identity_info.cache_identity.addr, '\0', sizeof(wccp2_identity_info.cache_identity.addr));
            memset(&wccp2_identity_info.cache_identity.hash_revision, '\0', sizeof(wccp2_identity_info.cache_identity.hash_revision));
            memset(&wccp2_identity_info.cache_identity.bits, '\0', sizeof(wccp2_identity_info.cache_identity.bits));
            memset(&wccp2_identity_info.cache_identity.buckets, '\0', sizeof(wccp2_identity_info.cache_identity.buckets));
            wccp2_identity_info.cache_identity.weight = htons(Config.Wccp2.weight);
            memset(&wccp2_identity_info.cache_identity.status, '\0', sizeof(wccp2_identity_info.cache_identity.status));

            xmemcpy(ptr, &wccp2_identity_info, sizeof(struct wccp2_identity_info_t));
            service_list_ptr->wccp2_identity_info_ptr = ptr;

            ptr += sizeof(struct wccp2_identity_info_t);
            break;

        case WCCP2_ASSIGNMENT_METHOD_MASK:

            wccp2_here_i_am_header.length += sizeof(struct wccp2_mask_identity_info_t);
            assert(wccp2_here_i_am_header.length <= WCCP_RESPONSE_SIZE);
            wccp2_mask_identity_info.cache_identity_type = htons(WCCP2_WC_ID_INFO);
            wccp2_mask_identity_info.cache_identity_length = htons(sizeof(wccp2_mask_identity_info.cache_identity));
            memset(&wccp2_mask_identity_info.cache_identity.addr, '\0', sizeof(wccp2_mask_identity_info.cache_identity.addr));
            wccp2_mask_identity_info.cache_identity.num1 = htonl(2);
            wccp2_mask_identity_info.cache_identity.num2 = htonl(1);
            service_flags = ntohl(service_list_ptr->service_info->service_flags);

            if ((service_flags & WCCP2_SERVICE_SRC_IP_HASH) || (service_flags & WCCP2_SERVICE_SRC_IP_ALT_HASH)) {
                wccp2_mask_identity_info.cache_identity.source_ip_mask = htonl(0x00001741);
                wccp2_mask_identity_info.cache_identity.dest_ip_mask = 0;
                wccp2_mask_identity_info.cache_identity.source_port_mask = 0;
                wccp2_mask_identity_info.cache_identity.dest_port_mask = 0;
            } else if ((service_list_ptr->info.service == WCCP2_SERVICE_STANDARD) || (service_flags & WCCP2_SERVICE_DST_IP_HASH) || (service_flags & WCCP2_SERVICE_DST_IP_ALT_HASH)) {
                wccp2_mask_identity_info.cache_identity.source_ip_mask = 0;
                wccp2_mask_identity_info.cache_identity.dest_ip_mask = htonl(0x00001741);
                wccp2_mask_identity_info.cache_identity.source_port_mask = 0;
                wccp2_mask_identity_info.cache_identity.dest_port_mask = 0;
            } else if ((service_flags & WCCP2_SERVICE_SRC_PORT_HASH) || (service_flags & WCCP2_SERVICE_SRC_PORT_ALT_HASH)) {
                wccp2_mask_identity_info.cache_identity.source_ip_mask = 0;
                wccp2_mask_identity_info.cache_identity.dest_ip_mask = 0;
                wccp2_mask_identity_info.cache_identity.source_port_mask = htons(0x1741);
                wccp2_mask_identity_info.cache_identity.dest_port_mask = 0;
            } else if ((service_flags & WCCP2_SERVICE_DST_PORT_HASH) || (service_flags & WCCP2_SERVICE_DST_PORT_ALT_HASH)) {
                wccp2_mask_identity_info.cache_identity.source_ip_mask = 0;
                wccp2_mask_identity_info.cache_identity.dest_ip_mask = 0;
                wccp2_mask_identity_info.cache_identity.source_port_mask = 0;
                wccp2_mask_identity_info.cache_identity.dest_port_mask = htons(0x1741);
            } else {
                fatalf("Unknown service hash method\n");
            }

            wccp2_mask_identity_info.cache_identity.num3 = 0;
            wccp2_mask_identity_info.cache_identity.num4 = 0;

            xmemcpy(ptr, &wccp2_mask_identity_info, sizeof(struct wccp2_mask_identity_info_t));
            service_list_ptr->wccp2_identity_info_ptr = ptr;

            ptr += sizeof(struct wccp2_mask_identity_info_t);
            break;

        default:
            fatalf("Unknown Wccp2 assignment method\n");
        }

        /* Add the cache view section */
        wccp2_here_i_am_header.length += sizeof(wccp2_cache_view_header);
