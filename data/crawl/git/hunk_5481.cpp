 				    comment_end = i;
 			}
 			if (comment_end)
-				putchar(' ');
+				printf("%s%s %s%s", c_reset,
+						    c_plain, c_reset,
+						    c_func);
 			for (i = 0; i < comment_end; i++)
 				putchar(hunk_comment[i]);
 		}
