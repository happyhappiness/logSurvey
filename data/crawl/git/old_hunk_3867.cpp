		return -1;
	}

	return 0;
#endif
}

static int socket_read(struct imap_socket *sock, char *buf, int len)
{