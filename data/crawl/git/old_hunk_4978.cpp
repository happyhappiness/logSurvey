		close(fd);
}

static void daemonize(void)
{
	switch (fork()) {
