 	case 'p':
 		persistent = !persistent;
 		break;
+	case 'R':
+		noreferrals = !noreferrals;
+		break;
 	default:
 		fprintf(stderr, "squid_ldap_auth: ERROR: Unknown command line option '%c'\n", option);
 		exit(1);
