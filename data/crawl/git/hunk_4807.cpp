 	}
 	if (!remote->url_nr)
 		die("remote %s has no configured URL", dest);
+
+	if (get_url) {
+		printf("%s\n", *remote->url);
+		return 0;
+	}
+
 	transport = transport_get(remote, NULL);
 	if (uploadpack != NULL)
 		transport_set_option(transport, TRANS_OPT_UPLOADPACK, uploadpack);
