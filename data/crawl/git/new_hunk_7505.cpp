				}
#endif
				ret = o->fn(src, o, remove);
				if (ret < 0)
					return ret;

#if DBRT_DEBUG > 1
				printf("Added %d entries\n", ret);
