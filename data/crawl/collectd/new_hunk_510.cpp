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

		if (nread == -1 && (errno == EINTR || errno == EAGAIN))
			continue;

		if (nread == -1)
		{
			*fd = -1;
			syslog (LOG_ERR, "apcups plugin: write failed: %s", strerror (errno));
			return (-1);
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

		if ((nwritten == -1) && ((errno == EAGAIN) || (errno == EINTR)))
			continue;

		if (nwritten == -1)
		{
			syslog (LOG_ERR, "Writing to socket failed: %s", strerror (errno));
			*fd = -1;
			return (-1);
		}

		nleft -= nwritten;
