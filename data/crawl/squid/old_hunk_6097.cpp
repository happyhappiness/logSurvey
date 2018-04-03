    } else {
	debug(1, 1) ("WCCP Disabled.\n");
    }
 
    router_len = sizeof(router);
    memset(&router, '\0', router_len);
    router.sin_family = AF_INET;
    router.sin_port = htons(2048);
    router.sin_addr = Config.Wccp.router;  
    if(connect(theOutWccpConnection, (struct sockaddr *)&router, router_len))
	fatal("Unable to connect WCCP out socket"); 

    local_len = sizeof(local); 
    memset(&local, '\0', local_len);
    if(getsockname(theOutWccpConnection, (struct sockaddr *)&local, &local_len))
	fatal("Unable to getsockname on WCCP out socket");
    local_ip = local.sin_addr.s_addr;
}
