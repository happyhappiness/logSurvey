        }
    }

  err = _do_handshake (session, fd, opt.connect_timeout);

  if (err < 0)
    {
