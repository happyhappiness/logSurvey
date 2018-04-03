	args,
	"diskd",
	&rfd,
	&DIO->wfd);
    if (x < 0)
	fatalf("execl: %s", Config.Program.diskd);
    if (rfd != DIO->wfd)
	comm_close(rfd);
    fd_note(DIO->wfd, "squid -> diskd");
    commSetTimeout(DIO->wfd, -1, NULL, NULL);
    commSetNonBlocking(DIO->wfd);
    
    UFSSwapDir::init();
    
    comm_quick_poll_required();
}
