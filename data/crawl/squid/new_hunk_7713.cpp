	}
    }

    /* Sanity checks */
    if (getClientLifetime() < getReadTimeout()) {
	printf("WARNING: client_lifetime (%d seconds) is less than read_timeout (%d seconds).\n",
