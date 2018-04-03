
            router_list_ptr->local_ip = local.sin_addr;

            /* Disconnect the sending socket */
            router.sin_family = AF_UNSPEC;

            if (connect(theWccp2Connection, (struct sockaddr *) &router, router_len))
                fatal("Unable to disconnect WCCP out socket");
        }

        service_list_ptr = service_list_ptr->next;
    }

    if (wccp2_numrouters == 1) {
        router.sin_family = AF_INET;

        connect(theWccp2Connection, (struct sockaddr *) &router, sizeof(router));
    }

    wccp2_connected = 1;
}

