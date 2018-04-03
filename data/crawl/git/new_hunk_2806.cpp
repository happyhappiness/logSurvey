			v->s = xmemdupz(sigpos, siglen);
		else if (!strcmp(name, "contents"))
			v->s = xstrdup(subpos);
		else if (skip_prefix(name, "contents:lines=", &valp)) {
			struct strbuf s = STRBUF_INIT;
			const char *contents_end = bodylen + bodypos - siglen;

			if (strtoul_ui(valp, 10, &v->u.contents.lines))
				die(_("positive value expected contents:lines=%s"), valp);
			/*  Size is the length of the message after removing the signature */
			append_lines(&s, subpos, contents_end - subpos, v->u.contents.lines);
			v->s = strbuf_detach(&s, NULL);
		}
	}
}

