    case RFCNB_SESSION_KEEP_ALIVE:

        fprintf(fd, "RFCNB SESSION KEEP ALIVE: Length = %i\n",
                RFCNB_Pkt_Len(pkt -> data));
        break;

    default:

        break;
    }

}

/* Resolve a name into an address */

int RFCNB_Name_To_IP(char *host, struct in_addr *Dest_IP)

{
    int addr;         /* Assumes IP4, 32 bit network addresses */
    struct hostent *hp;

    /* Use inet_addr to try to convert the address */

    if ((addr = inet_addr(host)) == INADDR_NONE) { /* Oh well, a good try :-) */

        /* Now try a name look up with gethostbyname */

        if ((hp = gethostbyname(host)) == NULL) { /* Not in DNS */

            /* Try NetBIOS name lookup, how the hell do we do that? */

            RFCNB_errno = RFCNBE_BadName;   /* Is this right? */
            RFCNB_saved_errno = errno;
            return(RFCNBE_Bad);

        } else { /* We got a name */

            memcpy((void *)Dest_IP, (void *)hp -> h_addr_list[0], sizeof(struct in_addr));

        }
    } else { /* It was an IP address */

        memcpy((void *)Dest_IP, (void *)&addr, sizeof(struct in_addr));

    }

    return 0;

}

/* Disconnect the TCP connection to the server */

int RFCNB_Close(int socket)

{

    close(socket);

    /* If we want to do error recovery, here is where we put it */

    return 0;

}

/* Connect to the server specified in the IP address.
   Not sure how to handle socket options etc.         */

int RFCNB_IP_Connect(struct in_addr Dest_IP, int port)

{
    struct sockaddr_in Socket;
    int fd;

    /* Create a socket */

    if ((fd = socket(PF_INET, SOCK_STREAM, 0)) < 0) { /* Handle the error */

        RFCNB_errno = RFCNBE_BadSocket;
        RFCNB_saved_errno = errno;
        return(RFCNBE_Bad);
    }

    memset((char *)&Socket, 0, sizeof(Socket));
    memcpy((char *)&Socket.sin_addr, (char *)&Dest_IP, sizeof(Dest_IP));

    Socket.sin_port = htons(port);
    Socket.sin_family = PF_INET;

    /* Now connect to the destination */

    if (connect(fd, (struct sockaddr *)&Socket, sizeof(Socket)) < 0) { /* Error */

        close(fd);
        RFCNB_errno = RFCNBE_ConnectFailed;
        RFCNB_saved_errno = errno;
        return(RFCNBE_Bad);
    }

    return(fd);

}

/* handle the details of establishing the RFCNB session with remote
   end

*/

int RFCNB_Session_Req(struct RFCNB_Con *con,
                      char *Called_Name,
                      char *Calling_Name,
                      BOOL *redirect,
                      struct in_addr *Dest_IP,
                      int * port)

{
    char *sess_pkt;

