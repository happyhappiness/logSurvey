      debug = 1;
      break;              
    case 'i':
      log = 1;
      break;              
    case 's':
      service_principal = xstrdup(optarg);
      break;
    case 'h':
      fprintf(stderr, "Usage: \n");
      fprintf(stderr, "squid_kerb_auth [-d] [-i] [-s SPN] [-h]\n");
      fprintf(stderr, "-d full debug\n");
      fprintf(stderr, "-i informational messages\n");
      fprintf(stderr, "-s service principal name\n");
      fprintf(stderr, "-h help\n");
      fprintf(stderr, "The SPN can be set to GSS_C_NO_NAME to allow any entry from keytab\n");
      fprintf(stderr, "default SPN is HTTP/fqdn@DEFAULT_REALM\n");
      exit(0);
    default:
      fprintf(stderr, "%s| %s: unknown option: -%c.\n", LogTime(), PROGRAM, opt);
    }
  }

  if (debug)
    fprintf(stderr, "%s| %s: Starting version %s\n", LogTime(), PROGRAM, VERSION);
  if (service_principal && strcasecmp(service_principal,"GSS_C_NO_NAME") ) {
    service.value = service_principal;
    service.length = strlen((char *)service.value);
  } else {
    host_name=gethost_name();
    if ( !host_name ) {
      fprintf(stderr, "%s| %s: Local hostname could not be determined. Please specify the service principal\n", LogTime(), PROGRAM);
      fprintf(stdout, "BH hostname error\n");
      exit(-1);
    }
    service.value = xmalloc(strlen(service_name)+strlen(host_name)+2);
    snprintf(service.value,strlen(service_name)+strlen(host_name)+2,"%s@%s",service_name,host_name);
    service.length = strlen((char *)service.value);
  }
