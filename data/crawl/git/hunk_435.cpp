 			baa = 1;
 		}
 	}
-	if (baa) {
-		int opt = 0160;
-		find_alignment(sb, &opt);
-		output(sb, opt);
-		die("Baa %d!", baa);
-	}
+	if (baa)
+		sb->on_sanity_fail(sb, baa);
+}
+
+static void sanity_check_on_fail(struct blame_scoreboard *sb, int baa)
+{
+	int opt = OUTPUT_SHOW_SCORE | OUTPUT_SHOW_NUMBER | OUTPUT_SHOW_NAME;
+	find_alignment(sb, &opt);
+	output(sb, opt);
+	die("Baa %d!", baa);
 }
 
 static unsigned parse_score(const char *arg)
