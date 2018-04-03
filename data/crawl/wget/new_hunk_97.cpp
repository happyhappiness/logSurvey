          success = false;
        }
      xfree(sni_hostname);

      pinsuccess = pkp_pin_peer_pubkey (cert, opt.pinnedpubkey);
      if (!pinsuccess)
        {
          logprintf (LOG_ALWAYS, _("The public key does not match pinned public key!\n"));
          success = false;
        }

 crt_deinit:
      gnutls_x509_crt_deinit (cert);
    }
