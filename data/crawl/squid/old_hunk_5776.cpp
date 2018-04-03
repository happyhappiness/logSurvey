    memset(addr, '\0', sizeof(struct in_addr));
}

#if DELAY_POOLS

/* do nothing - free_delay_pool_count is the magic free function.
