				int ret;

#if DBRT_DEBUG > 1
				fprintf(stderr, "%s:\n", first);
				for (i = 0; i < src_size; i++) {
					fprintf(stderr, " %d ", i);
					if (src[i])
						fprintf(stderr, "%06x %s\n", src[i]->ce_mode, sha1_to_hex(src[i]->sha1));
					else
						fprintf(stderr, "\n");
				}
#endif
				ret = o->fn(src, o, remove);
				if (ret < 0)
					return ret;

#if DBRT_DEBUG > 1
				fprintf(stderr, "Added %d entries\n", ret);
#endif
				o->pos += ret;
			} else {