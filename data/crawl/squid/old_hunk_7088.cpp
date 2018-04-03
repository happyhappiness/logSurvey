}

static void
dump_wordlist(wordlist * list)
{
    printf("{");
    while (list != NULL) {
	printf("%s ", list->key);
	list = list->next;
    }
    printf("}");
}

static void
