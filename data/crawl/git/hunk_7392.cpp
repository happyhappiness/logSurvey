 		if (get_sha1_hex(buffer+7, sha1) || buffer[47] != '\n')
 			return objerror(&commit->object, "invalid 'parent' line format - bad sha1");
 		buffer += 48;
+		parents++;
+	}
+	graft = lookup_commit_graft(commit->object.sha1);
+	if (graft) {
+		struct commit_list *p = commit->parents;
+		parents = 0;
+		while (p) {
+			p = p->next;
+			parents++;
+		}
+		if (graft->nr_parent == -1 && !parents)
+			; /* shallow commit */
+		else if (graft->nr_parent != parents)
+			return objerror(&commit->object, "graft objects missing");
+	} else {
+		struct commit_list *p = commit->parents;
+		while (p && parents) {
+			p = p->next;
+			parents--;
+		}
+		if (p || parents)
+			return objerror(&commit->object, "parent objects missing");
 	}
 	if (memcmp(buffer, "author ", 7))
 		return objerror(&commit->object, "invalid format - expected 'author' line");
