 #include "utils_cmd_flush.h"
 
 cmd_status_t cmd_parse_flush (size_t argc, char **argv,
-		cmd_flush_t *ret_flush, cmd_error_handler_t *err)
+		cmd_flush_t *ret_flush, const cmd_options_t *opts,
+		cmd_error_handler_t *err)
 {
-	if (ret_flush == NULL)
+
+	if ((ret_flush == NULL) || (opts == NULL))
 	{
 		errno = EINVAL;
 		cmd_error (CMD_ERROR, err, "Invalid arguments to cmd_parse_flush.");
