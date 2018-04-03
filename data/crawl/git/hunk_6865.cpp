 
 static void add_child(pid_t pid, struct sockaddr *addr, int addrlen)
 {
-	struct child *newborn;
-	newborn = xcalloc(1, sizeof *newborn);
-	if (newborn) {
-		struct child **cradle;
-
-		live_children++;
-		newborn->pid = pid;
-		memcpy(&newborn->address, addr, addrlen);
-		for (cradle = &firstborn; *cradle; cradle = &(*cradle)->next)
-			if (!memcmp(&(*cradle)->address, &newborn->address,
-				   sizeof newborn->address))
-				break;
-		newborn->next = *cradle;
-		*cradle = newborn;
-	}
-	else
-		logerror("Out of memory spawning new child");
+	struct child *newborn, **cradle;
+
+	/*
+	 * This must be xcalloc() -- we'll compare the whole sockaddr_storage
+	 * but individual address may be shorter.
+	 */
+	newborn = xcalloc(1, sizeof(*newborn));
+	live_children++;
+	newborn->pid = pid;
+	memcpy(&newborn->address, addr, addrlen);
+	for (cradle = &firstborn; *cradle; cradle = &(*cradle)->next)
+		if (!memcmp(&(*cradle)->address, &newborn->address,
+			    sizeof(newborn->address)))
+			break;
+	newborn->next = *cradle;
+	*cradle = newborn;
 }
 
-/*
- * Walk from "deleted" to "spawned", and remove child "pid".
- *
- * We move everything up by one, since the new "deleted" will
- * be one higher.
- */
 static void remove_child(pid_t pid)
 {
 	struct child **cradle, *blanket;
