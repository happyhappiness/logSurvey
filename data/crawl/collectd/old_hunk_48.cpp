
#if 0
    for (int i = 0; i < nr_domains; ++i)
        fprintf (stderr, "domain %s\n", virDomainGetName (domains[i]));
    for (int i = 0; i < nr_block_devices; ++i)
        fprintf  (stderr, "block device %d %s:%s\n",
                  i, virDomainGetName (block_devices[i].dom),
