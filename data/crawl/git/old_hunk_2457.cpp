					break;
				if (!p->parents)
					die ("Can't find replacement commit for tag %s\n",
					     sha1_to_hex(tag->object.sha1));
				p = p->parents->item;
			}
			tagged_mark = get_object_mark(&p->object);
