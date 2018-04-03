    {
      if (!opt.server_response)
        logputs (LOG_VERBOSE, "==> EPRT ... ");
      err = ftp_eprt (rbuf);

      /* If EPRT is not supported try LPRT */
      if (err == FTPPORTERR)
        {
          if (!opt.server_response)
            logputs (LOG_VERBOSE, "==> LPRT ... ");
          err = ftp_lprt (rbuf);
        }
    }
  else 
    {
      if (!opt.server_response)
        logputs (LOG_VERBOSE, "==> PORT ... ");
      err = ftp_port (rbuf);
    }

  return err;
}
#else
#define ftp_do_pasv ftp_pasv
#define ftp_do_port ftp_port
#endif

/* Retrieves a file with denoted parameters through opening an FTP
