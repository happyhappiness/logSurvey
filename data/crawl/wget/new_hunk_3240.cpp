            logputs (LOG_VERBOSE, "==> LPSV ... ");
          err = ftp_lpsv (rbuf, addr, port);
        }
      break;
    default:
      abort ();
    }

  return err;
