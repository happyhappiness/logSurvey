 			strcpy(buffer, data[i].from);
 			to = func(buffer);
 		}
-		if (strcmp(to, data[i].to)) {
+		if (!strcmp(to, data[i].to))
+			continue;
+		if (!data[i].alternative)
 			error("FAIL: %s(%s) => '%s' != '%s'\n",
 				funcname, data[i].from, to, data[i].to);
-			failed = 1;
-		}
+		else if (!strcmp(to, data[i].alternative))
+			continue;
+		else
+			error("FAIL: %s(%s) => '%s' != '%s', '%s'\n",
+				funcname, data[i].from, to, data[i].to,
+				data[i].alternative);
+		failed = 1;
 	}
 	return failed;
 }
