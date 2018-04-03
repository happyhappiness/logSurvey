	args,
	"diskd",
	&rfd,
	&diskdinfo->wfd);
    if (x < 0)
	fatalf("execl: %s", Config.Program.diskd);
    if (rfd != diskdinfo->wfd)
	comm_close(rfd);
    fd_note(diskdinfo->wfd, "squid -> diskd");
    commSetTimeout(diskdinfo->wfd, -1, NULL, NULL);
    commSetNonBlocking(diskdinfo->wfd);
    
    commonUfsDirInit (sd);
    
    comm_quick_poll_required();
}
