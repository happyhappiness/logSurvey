 	return !!get_builtin(s);
 }
 
+static void list_builtins(void)
+{
+	int i;
+	for (i = 0; i < ARRAY_SIZE(commands); i++)
+		printf("%s\n", commands[i].cmd);
+}
+
 #ifdef STRIP_EXTENSION
 static void strip_extension(const char **argv)
 {