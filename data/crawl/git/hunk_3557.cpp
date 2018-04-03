 	return 1;
 }
 
+static void normalize_argv_string(const char **var, const char *input)
+{
+	if (!strcmp(input, "<null>"))
+		*var = NULL;
+	else if (!strcmp(input, "<empty>"))
+		*var = "";
+	else
+		*var = input;
+
+	if (*var && (**var == '<' || **var == '('))
+		die("Bad value: %s\n", input);
+}
+
 int main(int argc, char **argv)
 {
 	if (argc == 3 && !strcmp(argv[1], "normalize_path_copy")) {
