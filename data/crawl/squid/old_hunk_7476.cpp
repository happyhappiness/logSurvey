	xfree(h);
    }
    xfree(L2);

    hashFreeMemory(addr_table);
    hashFreeMemory(host_table);
}

#endif /* USE_ICMP */
