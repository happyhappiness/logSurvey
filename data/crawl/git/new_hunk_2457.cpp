					break;
				if (!p->parents)
					die ("Can't find replacement commit for tag %s\n",
					     oid_to_hex(&tag->object.oid));
				p = p->parents->item;
			}
			tagged_mark = get_object_mark(&p->object);
