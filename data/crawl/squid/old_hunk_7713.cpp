	}
    }

    /* Add INADDR_ANY to end of bind_addr_list as last chance */
    wordlistAdd(&Config.bind_addr_list, "0.0.0.0");

    /* Sanity checks */
    if (getClientLifetime() < getReadTimeout()) {
	printf("WARNING: client_lifetime (%d seconds) is less than read_timeout (%d seconds).\n",
