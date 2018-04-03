 			unsigned char sha1[20];
 			if (get_sha1_hex(m.buf, sha1) < 0)
 				die("Corrupt MERGE_HEAD file (%s)", m.buf);
-			add_parent(&sb, sha1);
+			pptr = &commit_list_insert(lookup_commit(sha1), pptr)->next;
 		}
 		fclose(fp);
 		strbuf_release(&m);
 	} else {
 		reflog_msg = "commit";
-		strbuf_addf(&sb, "parent %s\n", sha1_to_hex(head_sha1));
+		pptr = &commit_list_insert(lookup_commit(head_sha1), pptr)->next;
 	}
-
-	strbuf_addf(&sb, "author %s\n",
-		    fmt_ident(author_name, author_email, author_date, IDENT_ERROR_ON_NO_NAME));
-	strbuf_addf(&sb, "committer %s\n", git_committer_info(IDENT_ERROR_ON_NO_NAME));
-	if (!is_encoding_utf8(git_commit_encoding))
-		strbuf_addf(&sb, "encoding %s\n", git_commit_encoding);
-	strbuf_addch(&sb, '\n');
+	parents = reduce_heads(parents);
 
 	/* Finally, get the commit message */
-	header_len = sb.len;
+	strbuf_init(&sb, 0);
 	if (strbuf_read_file(&sb, git_path(commit_editmsg), 0) < 0) {
 		rollback_index_files();
 		die("could not read commit message");
