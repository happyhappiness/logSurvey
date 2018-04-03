 			buffer_copy_bytes(buf, strtouint32(arg));
 			return;
 		}
-	case 'r':
-		if (!prefixcmp(command, "read ")) {
-			const char *s = buffer_read_string(buf, strtouint32(arg));
-			fputs(s, stdout);
-			return;
-		}
 	case 's':
 		if (!prefixcmp(command, "skip ")) {
 			buffer_skip_bytes(buf, strtouint32(arg));
