					printf("      %s\n", msg);
			}
			putchar('\n');
		}

		onelines->strdup_strings = 1;
		string_list_clear(onelines, 0);
		free(onelines);
		log->list.items[i].util = NULL;
	}
