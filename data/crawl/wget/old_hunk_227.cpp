void
set_windows_fd_as_blocking_socket (int fd)
{
	/* 04/2011
     gnulib select() converts blocking sockets to nonblocking in windows
     discussed here:
     http://old.nabble.com/blocking-socket-is-nonblocking-after-calling-gnulib-
     select%28%29-in-windows-td31432857.html

     wget uses blocking sockets so we must convert them back to blocking.
	*/
	int ret = 0;
	int wsagle = 0;
	const int zero = 0;

	do
	{
		if(wsagle == WSAEINPROGRESS)
		  Sleep(1);  /* use windows sleep */
		
		WSASetLastError (0);
		ret = ioctl (fd, FIONBIO, &zero);
		wsagle = WSAGetLastError();
	}
  while (ret && (wsagle == WSAEINPROGRESS));

	if(ret)
    {
      fprintf (stderr,
               _("ioctl() failed.  The socket could not be set as blocking.\n") );
      DEBUGP (("Winsock error: %d\n", WSAGetLastError ()));
      abort ();
    }
	return;
}
