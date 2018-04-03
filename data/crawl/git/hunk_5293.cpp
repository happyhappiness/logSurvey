 		}
 		string = ep;
 	}
+
+	if (rule & WS_TAB_IN_INDENT && rule & WS_INDENT_WITH_NON_TAB)
+		die("cannot enforce both tab-in-indent and indent-with-non-tab");
 	return rule;
 }
 
