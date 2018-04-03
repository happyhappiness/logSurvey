        fprintf(fd, "    %s\n", outbuf1);

    }
    fprintf(fd, "\n");
}

/* Get a packet of size n */
struct RFCNB_Pkt *
RFCNB_Alloc_Pkt(int n) {
    RFCNB_Pkt *pkt;

    if ((pkt = (struct RFCNB_Pkt *) malloc(sizeof(struct RFCNB_Pkt))) == NULL) {

        RFCNB_errno = RFCNBE_NoSpace;
        RFCNB_saved_errno = errno;
        return (NULL);

    }
    pkt->next = NULL;
    pkt->len = n;

    if (n == 0)
        return (pkt);

    if ((pkt->data = (char *) malloc(n)) == NULL) {

        RFCNB_errno = RFCNBE_NoSpace;
        RFCNB_saved_errno = errno;
        free(pkt);
        return (NULL);

    }
    return (pkt);
}

/* Free up a packet */
void
RFCNB_Free_Pkt(struct RFCNB_Pkt *pkt)
{
    struct RFCNB_Pkt *pkt_next;
    char *data_ptr;

    while (pkt != NULL) {

        pkt_next = pkt->next;

        data_ptr = pkt->data;

        if (data_ptr != NULL)
            free(data_ptr);
