	    fatal("Cannot open Multicast Miss Stream Socket");
	debug(46, 1) ("Multicast Miss Stream Socket opened on FD %d\n",
	    mcast_miss_fd);
	mcastSetTtl(mcast_miss_fd, 128);
	if (strlen(Config.mcast_miss.encode_key) < 16)
	    fatal("mcast_encode_key is too short, must be 16 characters");
    }
