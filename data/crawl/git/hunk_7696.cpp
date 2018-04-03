 	die("unknown unit: '%s'", end);
 }
 
-static struct whitespace_rule {
-	const char *rule_name;
-	unsigned rule_bits;
-} whitespace_rule_names[] = {
-	{ "trailing-space", WS_TRAILING_SPACE },
-	{ "space-before-tab", WS_SPACE_BEFORE_TAB },
-	{ "indent-with-non-tab", WS_INDENT_WITH_NON_TAB },
-};
-
-static unsigned parse_whitespace_rule(const char *string)
-{
-	unsigned rule = WS_DEFAULT_RULE;
-
-	while (string) {
-		int i;
-		size_t len;
-		const char *ep;
-		int negated = 0;
-
-		string = string + strspn(string, ", \t\n\r");
-		ep = strchr(string, ',');
-		if (!ep)
-			len = strlen(string);
-		else
-			len = ep - string;
-
-		if (*string == '-') {
-			negated = 1;
-			string++;
-			len--;
-		}
-		if (!len)
-			break;
-		for (i = 0; i < ARRAY_SIZE(whitespace_rule_names); i++) {
-			if (strncmp(whitespace_rule_names[i].rule_name,
-				    string, len))
-				continue;
-			if (negated)
-				rule &= ~whitespace_rule_names[i].rule_bits;
-			else
-				rule |= whitespace_rule_names[i].rule_bits;
-			break;
-		}
-		string = ep;
-	}
-	return rule;
-}
-
 int git_parse_long(const char *value, long *ret)
 {
 	if (value && *value) {
