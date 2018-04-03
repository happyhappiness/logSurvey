 		}
 		if (annotated_cnt && !list) {
 			if (debug)
-				fprintf(stderr, "finished search at %s\n",
+				fprintf(stderr, _("finished search at %s\n"),
 					sha1_to_hex(c->object.sha1));
 			break;
 		}
