 					putchar(' ');
 				p_mask <<= 1;
 			}
-			printf("%.*s%s\n", sl->len, sl->bol, c_reset);
+			show_line_to_eol(sl->bol, sl->len, c_reset);
 		}
 	}
 }
