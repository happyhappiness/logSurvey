	return service->fn();
}

static int upload_pack(void)
{
	/* Timeout as string */
	char timeout_buf[64];

	snprintf(timeout_buf, sizeof timeout_buf, "--timeout=%u", timeout);

	/* git-upload-pack only ever reads stuff, so this is safe */
	execl_git_cmd("upload-pack", "--strict", timeout_buf, ".", NULL);
	return -1;
}

static int upload_archive(void)
{
	execl_git_cmd("upload-archive", ".", NULL);
	return -1;
}

static int receive_pack(void)
{
	execl_git_cmd("receive-pack", ".", NULL);
	return -1;
}

static struct daemon_service daemon_service[] = {