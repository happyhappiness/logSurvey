    }

  ctx = xnew0 (struct wgnutls_transport_context);
  ctx->session = session;
  fd_register_transport (fd, &wgnutls_transport, ctx);
  return true;
}
