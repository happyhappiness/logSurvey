				struct strbuf target = STRBUF_INIT;
				strbuf_add(&target, base, serverlen);
				strbuf_add(&target, data + i, posn - i - 7);
				warning("adding alternate object store: %s",
					target.buf);
				newalt = xmalloc(sizeof(*newalt));
				newalt->next = NULL;
				newalt->base = strbuf_detach(&target, NULL);
