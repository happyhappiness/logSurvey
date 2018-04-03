				int ret;

#if DBRT_DEBUG > 1
				printf("%s:\n", first);
				for (i = 0; i < src_size; i++) {
					printf(" %d ", i);
					if (src[i])
						printf("%s\n", sha1_to_hex(src[i]->sha1));
					else
						printf("\n");
				}
#endif
				ret = o->fn(src, o, remove);
				if (ret < 0)
					return ret;

#if DBRT_DEBUG > 1
				printf("Added %d entries\n", ret);
#endif
				o->pos += ret;
			} else {