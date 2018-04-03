 * Send a message over the network. The send consists of
 * two network packets. The first is sends a short containing
 * the length of the data packet which follows.
 * Returns zero on success
 * Returns non-zero on error
 */
static int net_send (int sockfd, char *buff, int len)
{
	int rc;
	short packet_size;

	/* send short containing size of data packet */
	packet_size = htons ((short) len);

	rc = write_nbytes(sockfd, &packet_size, sizeof (packet_size));
	if (rc != sizeof(packet_size))
		return (-1);

	/* send data packet */
	rc = write_nbytes (sockfd, buff, len);
	if (rc != len)
		return (-1);

	return (0);
}

/* Get and print status from apcupsd NIS server */
static int do_pthreads_status (char *host, int port,
		struct apc_detail_s *apcups_detail)
{
	int     sockfd;
	int     n;
	char    recvline[MAXSTRING + 1];
