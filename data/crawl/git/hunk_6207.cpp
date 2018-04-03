 		char *p = memchr(buf, '\n', count);
 		if (p != buf && (fputs(color, fp) < 0 ||
 				fwrite(buf, p ? p - buf : count, 1, fp) != 1 ||
-				fputs(COLOR_RESET, fp) < 0))
+				fputs(GIT_COLOR_RESET, fp) < 0))
 			return -1;
 		if (!p)
 			return 0;
