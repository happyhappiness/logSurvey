
    memcpy(&us, buf + 2, 2);
    us = ntohs(us);
    fprintf (stderr, "Bytes 0, 1: 0x%04hx\n", us);
    qh.qr = (us >> 15) & 0x01;
    qh.opcode = (us >> 11) & 0x0F;
    qh.aa = (us >> 10) & 0x01;
