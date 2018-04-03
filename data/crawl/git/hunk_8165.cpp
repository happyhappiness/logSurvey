 	if (opt->add_signoff)
 		len = append_signoff(&msgbuf, &msgbuf_len, len,
 				     opt->add_signoff);
+	if (opt->show_log_size)
+		printf("log size %i\n", len);
+
 	printf("%s%s%s", msgbuf, extra, sep);
 	free(msgbuf);
 }
