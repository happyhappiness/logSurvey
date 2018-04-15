    memcpy(&us, buf + offset + 2, 2);
    qclass = ntohs(us);

    fprintf (stderr, "qtype = %hu\n", qtype);

    /* gather stats */
    qtype_counts[qtype]++;
