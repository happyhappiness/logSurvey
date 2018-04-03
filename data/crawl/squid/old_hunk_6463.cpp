	storeAppendPrintf(sentry, "peer.local_memory = %d\n",
	    peer->digest.cd ? peer->digest.cd->mask_size/1024 : 0);
	storeAppendPrintf(sentry, "\n");
    }

    storeAppendPrintf(sentry, "\nAlgorithm usage:\n");