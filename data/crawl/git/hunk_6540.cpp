 		break;
 
 	default:
-		die("git cat-file: unknown option: %s\n", exp_type);
+		die("git cat-file: unknown option: %s", exp_type);
 	}
 
 	if (!buf)
