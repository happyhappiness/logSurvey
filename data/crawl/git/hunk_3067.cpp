 	struct stat st;
 	struct child_process cp;
 	int counter = 0, len, ret;
+	unsigned char rev[20];
 
 	if (!new->commit)
 		die(_("no branch specified"));
