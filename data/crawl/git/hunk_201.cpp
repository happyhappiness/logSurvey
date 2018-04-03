 		if (argc != 2)
 			return error(_("--write-terms requires two arguments"));
 		return write_terms(argv[0], argv[1]);
+	case BISECT_CLEAN_STATE:
+		if (argc != 0)
+			return error(_("--bisect-clean-state requires no arguments"));
+		return bisect_clean_state();
 	default:
 		return error("BUG: unknown subcommand '%d'", cmdmode);
 	}
