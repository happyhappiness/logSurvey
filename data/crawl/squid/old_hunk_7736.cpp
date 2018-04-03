	    perror("recv");
	    exit(2);
	}
	memcpy(ip, &R.sin_addr.s_addr, 4);
	hp = gethostbyaddr(ip, 4, AF_INET);
	printf("==============================================================================\n");
	printf("Received from %s [%s]\n",
