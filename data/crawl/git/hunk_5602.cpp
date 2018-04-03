 
 		strbuf_addf(&buf, "fetch %s %s\n",
 			    sha1_to_hex(posn->old_sha1), posn->name);
-		write_in_full(helper->in, buf.buf, buf.len);
-		strbuf_reset(&buf);
+	}
 
-		if (strbuf_getline(&buf, file, '\n') == EOF)
+	strbuf_addch(&buf, '\n');
+	if (write_in_full(data->helper->in, buf.buf, buf.len) != buf.len)
+		die_errno("cannot send fetch to %s", data->name);
+
+	while (1) {
+		strbuf_reset(&buf);
+		if (strbuf_getline(&buf, data->out, '\n') == EOF)
 			exit(128); /* child died, message supplied already */
+
+		if (!prefixcmp(buf.buf, "lock ")) {
+			const char *name = buf.buf + 5;
+			if (transport->pack_lockfile)
+				warning("%s also locked %s", data->name, name);
+			else
+				transport->pack_lockfile = xstrdup(name);
+		}
+		else if (!buf.len)
+			break;
+		else
+			warning("%s unexpectedly said: '%s'", data->name, buf.buf);
 	}
+	strbuf_release(&buf);
 	return 0;
 }
 
