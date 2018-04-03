      int i;
      debug_logprintf ("Caching %s =>", host);
      for (i = 0; i < al->count; i++)
	debug_logprintf (" %s",
			 pretty_print_address (ADDR_LOCATION (al, i)));
      debug_logprintf ("\n");
    }
#endif
