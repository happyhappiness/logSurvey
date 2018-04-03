                            &dt, opt.recursive, iri, true);
            }

          if (opt.delete_after && filename != NULL && file_exists_p (filename))
            {
              DEBUGP (("Removing file due to --delete-after in main():\n"));
              logprintf (LOG_VERBOSE, _("Removing %s.\n"), filename);
