 					putchar(',');
 			}
 			if (white_space_at_end)
-				printf("white space at end");
+				printf("whitespace at end");
 			printf(":%s ", reset);
 			emit_line_with_ws(1, set, reset, ws, line, len,
 					  data->ws_rule);