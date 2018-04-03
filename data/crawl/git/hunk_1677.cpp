 	case 7:
 		return _("both modified:");
 	default:
-		die("bug: unhandled unmerged status %x", stagemask);
+		die("BUG: unhandled unmerged status %x", stagemask);
 	}
 }
 
