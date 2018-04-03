      /* Print results. */
      int nrecords = hash_table_count (warc_cdx_dedup_table);
      logprintf (LOG_VERBOSE, ngettext ("Loaded %d record from CDX.\n\n",
                                        "Loaded %d records from CDX.\n\n", nrecords),
                              nrecords);
    }

