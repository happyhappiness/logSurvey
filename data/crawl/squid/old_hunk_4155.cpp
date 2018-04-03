      debug = 1;
      break;              
    case 'i':
      loging = 1;
      break;              
    case 's':
      service_principal = strdup(optarg);
      break;
    case 'h':
      fprintf(stdout, "Usage: \n");
      fprintf(stdout, "squid_kerb_auth -d [-s SPN]\n");
      fprintf(stdout, "SPN = service principal name\n");
      fprintf(stdout, "Can be set to GSS_C_NO_NAME to allow any entry from keytab\n");
      fprintf(stdout, "default SPN is HTTP/fqdn@DEFAULT_REALM\n");
      break;
    default:
      fprintf(stderr, "%s| %s: unknown option: -%c.\n", LogTime(), PROGRAM, opt);
    }
  }

  if (service_principal && strcasecmp(service_principal,"GSS_C_NO_NAME") ) {
    service.value = service_principal;
    service.length = strlen((char *)service.value);
  } else {
    host_name=gethost_name();
    if ( !host_name ) {
      fprintf(stderr, "%s| %s: Local hostname could not be determined. Please specify the service principal\n", LogTime(), PROGRAM);
      exit(-1);
    }
    service.value = malloc(strlen(service_name)+strlen(host_name)+2);
    snprintf(service.value,strlen(service_name)+strlen(host_name)+2,"%s@%s",service_name,host_name);
    service.length = strlen((char *)service.value);
  }
