 	}
 
 	strcpy(date, git_default_date);
-	if (!name_addr_only && date_str)
-		parse_date(date_str, date, sizeof(date));
+	if (!name_addr_only && date_str && date_str[0]) {
+		if (parse_date(date_str, date, sizeof(date)) < 0)
+			die("invalid date format: %s", date_str);
+	}
 
 	i = copy(buffer, sizeof(buffer), 0, name);
 	i = add_raw(buffer, sizeof(buffer), i, " <");
