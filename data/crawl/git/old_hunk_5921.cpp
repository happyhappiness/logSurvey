{
	ssize_t ret = read_in_full(fd, buffer, size);
	if (ret < 0)
		die("read error (%s)", strerror(errno));
	else if (ret < size)
		die("The remote end hung up unexpectedly");
}
