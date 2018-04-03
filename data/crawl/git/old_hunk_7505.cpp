				}
#endif
				ret = o->fn(src, o, remove);

#if DBRT_DEBUG > 1
				printf("Added %d entries\n", ret);
