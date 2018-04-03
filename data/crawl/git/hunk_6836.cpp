 					else
 						putchar(' ');
 				}
-				printf("%s%s\n", ll->line, c_reset);
+				show_line_to_eol(ll->line, -1, c_reset);
 				ll = ll->next;
 			}
 			if (cnt < lno)
