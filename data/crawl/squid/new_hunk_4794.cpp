
            router_list_ptr->local_ip = local.sin_addr;

            /* Disconnect the sending socket. Note: FreeBSD returns error
             * but disconnects anyway so we have to just assume it worked
             */
            if (wccp2_numrouters > 1)

                connect(theWccp2Connection, (struct sockaddr *) &null, router_len);
        }

        service_list_ptr = service_list_ptr->next;
    }

    wccp2_connected = 1;
}

