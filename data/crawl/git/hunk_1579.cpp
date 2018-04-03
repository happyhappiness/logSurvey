 		wt_porcelain_print(s);
 		break;
 	case STATUS_FORMAT_PORCELAIN_V2:
-		/* TODO */
+		wt_porcelain_v2_print(s);
 		break;
 	case STATUS_FORMAT_UNSPECIFIED:
 		die("BUG: finalize_deferred_config() should have been called");