
      if (!pasv_mode_open)   /* Try to use a port command if PASV failed */
	{
	  err = ftp_do_port (&con->rbuf, &local_sock);
	  /* FTPRERR, WRITEFAILED, bindport (CONSOCKERR, CONPORTERR, BINDERR,
	     LISTENERR), HOSTERR, FTPPORTERR */
	  switch (err)
