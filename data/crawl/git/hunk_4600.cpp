 		m++;
 	}
 	if (!z)
-		die("insane in-reply-to: %s", msg_id);
+		die(_("insane in-reply-to: %s"), msg_id);
 	if (++z == m)
 		return a;
 	return xmemdupz(a, z - a);
