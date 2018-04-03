      int confval;
      bool userrc_ret = true;
      struct cmdline_option *config_opt;

      /* There is no short option for "--config". */
      if (longindex >= 0)
        {
          confval = long_options[longindex].val;
          config_opt = &option_data[confval & ~BOOLEAN_NEG_MARKER];
          if (strcmp (config_opt->long_name, "config") == 0)
            {
              userrc_ret &= run_wgetrc (optarg);
              use_userconfig = true;
            }
          if (!userrc_ret)
            {
              printf ("Exiting due to error in %s\n", optarg);
              exit (2);
            }
          else
            break;
        }
    }

  /* If the user did not specify a config, read the system wgetrc and ~/.wgetrc. */
