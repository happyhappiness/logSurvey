            logputs (LOG_VERBOSE, "==> LPRT ... ");
          err = ftp_lprt (rbuf, local_sock);
        }
      break;
    default:
      abort ();
    }
  return err;
}
#else
