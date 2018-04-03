 				rule |= whitespace_rule_names[i].rule_bits;
 			break;
 		}
+		if (strncmp(string, "tabwidth=", 9) == 0) {
+			unsigned tabwidth = atoi(string + 9);
+			if (0 < tabwidth && tabwidth < 0100) {
+				rule &= ~WS_TAB_WIDTH_MASK;
+				rule |= tabwidth;
+			}
+			else
+				warning("tabwidth %.*s out of range",
+					(int)(len - 9), string + 9);
+		}
 		string = ep;
 	}
 
