	const char *vhost)
{
	if (!vhost)
		packet_write_fmt(stdin_fd, "%s %s%c", serv, repo, 0);
	else
		packet_write_fmt(stdin_fd, "%s %s%chost=%s%c", serv, repo, 0,
			     vhost, 0);
}

