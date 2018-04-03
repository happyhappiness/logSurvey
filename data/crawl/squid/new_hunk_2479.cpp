                if (arg)
                    storeAppendPrintf(entry, "{%s}", arg);

                storeAppendPrintf(entry, "%s", t->label);

                if (t->space)
                    entry->append(" ", 1);
