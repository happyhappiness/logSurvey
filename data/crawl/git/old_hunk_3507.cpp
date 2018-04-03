			bottom = 1;
			top = menu_stuff->nr;
		} else {
			switch (menu_stuff->type) {
			default:
				die("Bad type of menu_stuff when parse choice");
			case MENU_STUFF_TYPE_MENU_ITEM:
				menu_item = (struct menu_item *)menu_stuff->stuff;
				for (i = 0; i < menu_stuff->nr; i++, menu_item++) {
					if (((*ptr)->len == 1 &&
					     *(*ptr)->buf == menu_item->hotkey) ||
					    !strcasecmp((*ptr)->buf, menu_item->title)) {
						bottom = i + 1;
						top = bottom;
						break;
					}
				}
				break;
			case MENU_STUFF_TYPE_STRING_LIST:
				string_list_item = ((struct string_list *)menu_stuff->stuff)->items;
				for (i = 0; i < menu_stuff->nr; i++, string_list_item++) {
					if (!strcasecmp((*ptr)->buf, string_list_item->string)) {
						bottom = i + 1;
						top = bottom;
						break;
					}
				}
				break;
			}
		}

		if (top <= 0 || bottom <= 0 || top > menu_stuff->nr || bottom > top ||
