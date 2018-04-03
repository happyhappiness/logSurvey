        }
    }

#ifdef HAVE_LIBCARES
  if (opt.bind_dns_address || opt.dns_servers)
    {
      if (ares_library_init (ARES_LIB_INIT_ALL))
        {
          fprintf (stderr, _("Failed to init libcares\n"));
          exit (WGET_EXIT_GENERIC_ERROR);
        }

      if (ares_init (&ares) != ARES_SUCCESS)
        {
          fprintf (stderr, _("Failed to init c-ares channel\n"));
          exit (WGET_EXIT_GENERIC_ERROR);
        }

      if (opt.bind_dns_address)
        {
          struct in_addr a4;
#ifdef ENABLE_IPV6
          struct in6_addr a6;
#endif

          if (inet_pton (AF_INET, opt.bind_dns_address, &a4) == 1)
            {
              ares_set_local_ip4 (ares, ntohl (a4.s_addr));
            }
#ifdef ENABLE_IPV6
          else if (inet_pton (AF_INET6, opt.bind_dns_address, &a6) == 1)
            {
              ares_set_local_ip6 (ares, (unsigned char *) &a6);
            }
#endif
          else
            {
              fprintf (stderr, _("Failed to parse IP address '%s'\n"), opt.bind_dns_address);
              exit (WGET_EXIT_GENERIC_ERROR);
            }
        }

      if (opt.dns_servers)
        {
          int result;

          if ((result = ares_set_servers_csv (ares, opt.dns_servers)) != ARES_SUCCESS)
            {
              fprintf (stderr, _("Failed to set DNS server(s) '%s' (%d)\n"), opt.dns_servers, result);
              exit (WGET_EXIT_GENERIC_ERROR);
            }
        }
    }
#endif

#ifdef __VMS
  /* Set global ODS5 flag according to the specified destination (if
     any), otherwise according to the current default device.
