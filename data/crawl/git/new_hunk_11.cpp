			refspec_updated = 1;
			strbuf_splice(&buf2,
				      ptr-buf2.buf + strlen(":refs/remotes/"),
				      strlen(rename.old_name), rename.new_name,
				      strlen(rename.new_name));
		} else
			warning(_("Not updating non-default fetch refspec\n"
				  "\t%s\n"
