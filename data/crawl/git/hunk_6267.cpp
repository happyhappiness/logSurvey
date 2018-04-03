 			safe_write(out, buf + pf+1, len);
 			continue;
 		default:
-			len = sprintf(buf,
-				      "%s: protocol error: bad band #%d\n",
-				      me, band);
-			safe_write(err, buf, len);
+			fprintf(stderr, "%s: protocol error: bad band #%d\n",
+				me, band);
 			return SIDEBAND_PROTOCOL_ERROR;
 		}
 	}
