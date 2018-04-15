 		}
 	}
 
-	PRINT_TO_SOCK (fh, "0 Done: %i successful, %i errors\n",
+	cmd_error (CMD_OK, &err, "Done: %i successful, %i errors",
 			success, error);
 
-	strarray_free (plugins, plugins_num);
-	strarray_free (identifiers, identifiers_num);
+	cmd_destroy (&cmd);
 	return (0);
 #undef PRINT_TO_SOCK
-} /* int handle_flush */
+} /* cmd_status_t cmd_handle_flush */
+
+void cmd_destroy_flush (cmd_flush_t *flush)
+{
+	if (flush == NULL)
+		return;
+
+	strarray_free (flush->plugins, flush->plugins_num);
+	flush->plugins = NULL;
+	flush->plugins_num = 0;
+
+	sfree (flush->identifiers);
+	flush->identifiers_num = 0;
+} /* void cmd_destroy_flush */
 
 /* vim: set sw=4 ts=4 tw=78 noexpandtab : */
 
