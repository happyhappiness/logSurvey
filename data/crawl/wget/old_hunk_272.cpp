          config_opt = &option_data[confval & ~BOOLEAN_NEG_MARKER];
          if (strcmp (config_opt->long_name, "config") == 0)
            {
              userrc_ret &= run_wgetrc (optarg);
              use_userconfig = true;
            }
          if (!userrc_ret)
            {
              fprintf (stderr, _("Exiting due to error in %s\n"), optarg);
              exit (2);
            }
          else
            break;
        }
    }

