 		die("Unhandled message id: %s", msg_id);
 	type = parse_msg_type(msg_type);
 
+	if (type != FSCK_ERROR && msg_id_info[id].msg_type == FSCK_FATAL)
+		die("Cannot demote %s to %s", msg_id, msg_type);
+
 	if (!options->msg_type) {
 		int i;
 		int *msg_type = xmalloc(sizeof(int) * FSCK_MSG_MAX);
