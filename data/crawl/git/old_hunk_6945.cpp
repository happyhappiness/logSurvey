string_list_append("foo", &list);
string_list_append("bar", &list);
for (i = 0; i < list.nr; i++)
	printf("%s\n", list.items[i].path)
----

NOTE: It is more efficient to build an unsorted list and sort it
