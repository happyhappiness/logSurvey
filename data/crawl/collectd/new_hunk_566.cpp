};
static int config_keys_num = 2;

#endif /* if APCMAIN */

struct apc_detail_s
{
	double linev;
	double loadpct;
	double bcharge;
	double timeleft;
	double outputv;
	double itemp;
	double battv;
	double linefreq;
};

#define BIG_BUF 4096

/*
 * Read nbytes from the network.
 * It is possible that the total bytes require in several
 * read requests
 */
static int read_nbytes (int *fd, char *ptr, int nbytes)
{
	int nleft;
	int nread;

	nleft = nbytes;
	nread = -1;

	assert (*fd >= 0);

	while ((nleft > 0) && (nread != 0))
	{
		nread = read (*fd, ptr, nleft);

		if ((nread < 0) && (errno == EINTR || errno == EAGAIN))
			continue;

		if (nread < 0)
		{
			*fd = -1;
			DBG ("Reading from socket failed failed: %s; *fd = -1;", strerror (errno));
			syslog (LOG_ERR, "apcups plugin: Reading from socket failed failed: %s", strerror (errno));
			return (-1);
		}

		if (nread == 0)
		{
			DBG ("Received EOF. Closing socket %i.", *fd);
			close (*fd);
			*fd = -1;
			return (nbytes - nleft);
		}

		nleft -= nread;
		ptr += nread;
	}

	return (nbytes - nleft);
}

/*
 * Write nbytes to the network.
 * It may require several writes.
 */
static int write_nbytes (int *fd, void *buf, int buflen)
{
	int nleft;
	int nwritten;
	char *ptr;

	assert (buflen > 0);
	assert (*fd >= 0);

	ptr = (char *) buf;

	nleft = buflen;
	while (nleft > 0)
	{
		nwritten = write (*fd, ptr, nleft);

		if ((nwritten < 0) && ((errno == EAGAIN) || (errno == EINTR)))
			continue;

		if (nwritten < 0)
		{
			*fd = -1;
			DBG ("Writing to socket failed: %s; *fd = -1;", strerror (errno));
			syslog (LOG_ERR, "apcups plugin: Writing to socket failed: %s", strerror (errno));
			return (-1);
		}

		nleft -= nwritten;
