 			file_change_cr(b, 0);
 		else if (!strcmp("deleteall", command_buf.buf))
 			file_change_deleteall(b);
-		else
-			die("Unsupported file_change: %s", command_buf.buf);
+		else {
+			unread_command_buf = 1;
+			break;
+		}
 		read_next_command();
 	}
 
