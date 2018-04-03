 {
 	va_list params;
 
-	flush_output(o);
+	if (o->buffer_output < 2)
+		flush_output(o);
+	else {
+		strbuf_complete(&o->obuf, '\n');
+		strbuf_addstr(&o->obuf, "error: ");
+	}
 	va_start(params, err);
 	strbuf_vaddf(&o->obuf, err, params);
 	va_end(params);
-	error("%s", o->obuf.buf);
-	strbuf_reset(&o->obuf);
+	if (o->buffer_output > 1)
+		strbuf_addch(&o->obuf, '\n');
+	else {
+		error("%s", o->obuf.buf);
+		strbuf_reset(&o->obuf);
+	}
 
 	return -1;
 }
