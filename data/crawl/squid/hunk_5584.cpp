 	case 'd':
 	    debug = 1;
 	    break;
+	case 'g':
+	    use_grouprdn = 1;
+	    break;
 	default:
 	    fprintf(stderr, "squid_ldap_match: ERROR: Unknown command line option '%c'\n", option);
 	    exit(1);
