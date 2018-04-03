
        assignment_header = (struct wccp2_item_header_t *) &wccp_packet[offset];

        assignment_header->type = htons(WCCP2_REDIRECT_ASSIGNMENT);

        offset += sizeof(struct wccp2_item_header_t);

        /* Assignment key - fill in master ip later */

