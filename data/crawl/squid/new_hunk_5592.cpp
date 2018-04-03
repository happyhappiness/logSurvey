	case 'w':
		bindpasswd = value;
		break;
	case 'P':
		persistent = !persistent;
		break;
	case 'p':
		port = atoi(value);
		break;
	case 'R':
		noreferrals = !noreferrals;
		break;
	case 'v':
		switch(atoi(value)) {
		case 2:
		    version = LDAP_VERSION2;
		    break;
		case 3:
		    version = LDAP_VERSION3;
		    break;
		default:
		    fprintf( stderr, "Protocol version should be 2 or 3\n");
		    exit(1);
		}
		break;
	case 'Z':
		if ( version == LDAP_VERSION2 ) {
		    fprintf( stderr, "TLS (-Z) is incompatible with version %d\n",
			    version);
		    exit(1);
		}
		version = LDAP_VERSION3;
		use_tls = 1;
		break;
	case 'd':
		debug = 1;
		break;
