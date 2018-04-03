	return NULL;
      }
    /* Do all systems have h_addr_list, or is it a newer thing?  If
       the latter, use address_list_new_one.  */
    al = address_list_new (hptr->h_addr_list);
  }
#endif

  if (!silent)
    logprintf (LOG_VERBOSE, _("done.\n"));

  /* Cache the lookup information. */
  if (opt.dns_cache)
