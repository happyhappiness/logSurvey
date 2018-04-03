 			remote->receivepack = xstrdup(value);
 		else
 			error("more than one receivepack given, using the first");
+	} else if (!strcmp(subkey, ".uploadpack")) {
+		if (!remote->uploadpack)
+			remote->uploadpack = xstrdup(value);
+		else
+			error("more than one uploadpack given, using the first");
 	}
 	return 0;
 }
