            logputs (LOG_VERBOSE, "==> LPRT ... ");
          err = ftp_lprt (rbuf, local_sock);
        }
    }
  else 
    {
      if (!opt.server_response)
        logputs (LOG_VERBOSE, "==> PORT ... ");
      err = ftp_port (rbuf, local_sock);
    }

  return err;
}
#else
