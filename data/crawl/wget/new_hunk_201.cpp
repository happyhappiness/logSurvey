
          res = hash_table_get_pair (jar->chains, victim->domain,
                                     &chain_key, NULL);

          if (res == 0)
            {
              logprintf (LOG_VERBOSE, _("Unable to get cookie for %s\n"),
                         victim->domain);
            }
          if (!victim->next)
            {
              /* VICTIM was the only cookie in the chain.  Destroy the
