        fprintf(fd, "    %s\n", outbuf1);

    }
    fprintf(fd, "\n");

}
#endif

/* Get a packet of size n */

struct RFCNB_Pkt *
RFCNB_Alloc_Pkt(int n) {
    RFCNB_Pkt *pkt;

    if ((pkt = malloc(sizeof(struct RFCNB_Pkt))) == NULL) {
        RFCNB_errno = RFCNBE_NoSpace;
        RFCNB_saved_errno = errno;
        return (NULL);
    }
    pkt->next = NULL;
    pkt->len = n;

    if (n == 0)
        return (pkt);

    if ((pkt->data = malloc(n)) == NULL) {
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

    while (pkt != NULL) {

        pkt_next = pkt->next;

        if (pkt->data != NULL)
            free(pkt->data);

        free(pkt);

