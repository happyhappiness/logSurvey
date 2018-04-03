
    while (pkt_ptr != NULL) {

        for (i = 0;
                i < ((Len > (pkt_ptr->len) ? pkt_ptr->len : Len) - Offset);
                i++) {

            c = pkt_ptr->data[i + Offset];
            c1 = Hex_List[c >> 4];
            c2 = Hex_List[c & 0xF];

            outbuf1[j++] = c1;
            outbuf1[j++] = c2;

            if (j == 32) {	/* Print and reset */
                outbuf1[j] = 0;
                fprintf(fd, "    %s\n", outbuf1);
                j = 0;
            }
        }

        Offset = 0;
        Len = Len - pkt_ptr->len;	/* Reduce amount by this much */
        pkt_ptr = pkt_ptr->next;

    }

    /* Print last lot in the buffer ... */

    if (j > 0) {

        outbuf1[j] = 0;
        fprintf(fd, "    %s\n", outbuf1);

    }
    fprintf(fd, "\n");