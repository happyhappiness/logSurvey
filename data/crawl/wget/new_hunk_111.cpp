  wgnutls_peek, wgnutls_errstr, wgnutls_close
};

static int
_do_handshake (gnutls_session_t session, int fd, double timeout)
{
#ifdef F_GETFL
  int flags = 0;
#endif
  int err;

  if (timeout)
    {
#ifdef F_GETFL
      flags = fcntl (fd, F_GETFL, 0);
      if (flags < 0)
        return flags;
      if (fcntl (fd, F_SETFL, flags | O_NONBLOCK))
        return -1;
#else
      /* XXX: Assume it was blocking before.  */
      const int one = 1;
      if (ioctl (fd, FIONBIO, &one) < 0)
        return -1;
#endif
    }

  /* We don't stop the handshake process for non-fatal errors */
  do
    {
      err = gnutls_handshake (session);

      if (timeout && err == GNUTLS_E_AGAIN)
        {
          if (gnutls_record_get_direction (session))
            {
              /* wait for writeability */
              err = select_fd (fd, timeout, WAIT_FOR_WRITE);
            }
          else
            {
              /* wait for readability */
              err = select_fd (fd, timeout, WAIT_FOR_READ);
            }

          if (err <= 0)
            {
              if (err == 0)
                {
                  errno = ETIMEDOUT;
                  err = -1;
                }
              break;
            }

           err = GNUTLS_E_AGAIN;
        }
      else if (err < 0)
        {
          logprintf (LOG_NOTQUIET, "GnuTLS: %s\n", gnutls_strerror (err));
          if (err == GNUTLS_E_WARNING_ALERT_RECEIVED ||
              err == GNUTLS_E_FATAL_ALERT_RECEIVED)
            {
              gnutls_alert_description_t alert = gnutls_alert_get (session);
              const char *str = gnutls_alert_get_name (alert);
              logprintf (LOG_NOTQUIET, "GnuTLS: received alert [%d]: %s\n",
                         alert, str ? str : "(unknown)");
            }
        }
    }
  while (err && gnutls_error_is_fatal (err) == 0);

  if (timeout)
    {
#ifdef F_GETFL
      if (fcntl (fd, F_SETFL, flags) < 0)
        return -1;
#else
      const int zero = 0;
      if (ioctl (fd, FIONBIO, &zero) < 0)
        return -1;
#endif
    }

  return err;
}

bool
ssl_connect_wget (int fd, const char *hostname, int *continue_session)
{
  struct wgnutls_transport_context *ctx;
  gnutls_session_t session;
  int err;

  gnutls_init (&session, GNUTLS_CLIENT);

