  if (opt.enable_iri || opt.locale || opt.encoding_remote)
    {
      /* sXXXav : be more specific... */
      fprintf (stderr, _("This version does not have support for IRIs\n"));
      exit(1);
    }
#endif
