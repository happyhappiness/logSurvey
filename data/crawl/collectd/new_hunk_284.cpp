        snprintf (address, sizeof (address), "unix:%s", optarg);
        address[sizeof (address) - 1] = '\0';
        break;
      case 'h':
        exit_usage (argv[0], 0);
        break;
