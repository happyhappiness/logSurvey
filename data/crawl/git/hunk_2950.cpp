 	if (state->message_id)
 		argv_array_push(&cp.args, "-m");
 
+	switch (state->scissors) {
+	case SCISSORS_UNSET:
+		break;
+	case SCISSORS_FALSE:
+		argv_array_push(&cp.args, "--no-scissors");
+		break;
+	case SCISSORS_TRUE:
+		argv_array_push(&cp.args, "--scissors");
+		break;
+	default:
+		die("BUG: invalid value for state->scissors");
+	}
+
 	argv_array_push(&cp.args, am_path(state, "msg"));
 	argv_array_push(&cp.args, am_path(state, "patch"));
 
