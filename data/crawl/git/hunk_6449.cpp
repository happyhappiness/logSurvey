 		key_delim = '\n';
 	}
 
+	if (HAS_MULTI_BITS(types)) {
+		error("only one type at a time.");
+		usage_with_options(builtin_config_usage, builtin_config_options);
+	}
+
 	if (get_color_slot)
 	    actions |= ACTION_GET_COLOR;
 	if (get_colorbool_slot)