 /* "\033[1;38;5;2xx;48;5;2xxm\0" is 23 bytes */
 #define COLOR_MAXLEN 24
 
+/*
+ * IMPORTANT: Due to the way these color codes are emulated on Windows,
+ * write them only using printf(), fprintf(), and fputs(). In particular,
+ * do not use puts() or write().
+ */
 #define GIT_COLOR_NORMAL	""
 #define GIT_COLOR_RESET		"\033[m"
 #define GIT_COLOR_BOLD		"\033[1m"