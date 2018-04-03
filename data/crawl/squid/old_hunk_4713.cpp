
        /* Add the cache identity section */

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

        service_list_ptr->wccp2_identity_info_ptr = (struct wccp2_identity_info_t *) ptr;

        ptr += sizeof(struct wccp2_identity_info_t);

        /* Add the cache view section */
        wccp2_here_i_am_header.length += sizeof(wccp2_cache_view_header);
