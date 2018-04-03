                version = LDAP_VERSION3;
                break;
            default:
                fprintf(stderr, "FATAL: Protocol version should be 2 or 3\n");
                exit(1);
            }
            break;
        case 'Z':
            if (version == LDAP_VERSION2) {
                fprintf(stderr, "FATAL: TLS (-Z) is incompatible with version %d\n",
                        version);
                exit(1);
            }
