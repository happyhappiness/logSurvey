				printf("Removing %s\n",
				       ent->name + prefix_offset);
			}
			unlink(ent->name);
		}
	}
	free(seen);

	strbuf_release(&directory);
	return 0;
}
