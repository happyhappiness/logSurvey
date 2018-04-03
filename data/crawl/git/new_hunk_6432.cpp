	return 0;
}

int add_push_to_show_info(struct string_list_item *push_item, void *cb_data)
{
	struct show_info *show_info = cb_data;
	struct push_info *push_info = push_item->util;
	struct string_list_item *item;
	int n;
	if ((n = strlen(push_item->string)) > show_info->width)
		show_info->width = n;
	if ((n = strlen(push_info->dest)) > show_info->width2)
		show_info->width2 = n;
	item = string_list_append(push_item->string, show_info->list);
	item->util = push_item->util;
	return 0;
}

int show_push_info_item(struct string_list_item *item, void *cb_data)
{
	struct show_info *show_info = cb_data;
	struct push_info *push_info = item->util;
	char *src = item->string, *status = NULL;

	switch (push_info->status) {
	case PUSH_STATUS_CREATE:
		status = "create";
		break;
	case PUSH_STATUS_DELETE:
		status = "delete";
		src = "(none)";
		break;
	case PUSH_STATUS_UPTODATE:
		status = "up to date";
		break;
	case PUSH_STATUS_FASTFORWARD:
		status = "fast forwardable";
		break;
	case PUSH_STATUS_OUTOFDATE:
		status = "local out of date";
		break;
	case PUSH_STATUS_NOTQUERIED:
		break;
	}
	if (status)
		printf("    %-*s %s to %-*s (%s)\n", show_info->width, src,
			push_info->forced ? "forces" : "pushes",
			show_info->width2, push_info->dest, status);
	else
		printf("    %-*s %s to %s\n", show_info->width, src,
			push_info->forced ? "forces" : "pushes",
			push_info->dest);
	return 0;
}

static int show(int argc, const char **argv)
{
	int no_query = 0, result = 0, query_flag = 0;
