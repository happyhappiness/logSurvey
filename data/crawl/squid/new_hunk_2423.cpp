                if (t->zero)
                    entry->append("0", 1);

                if (t->widthMin >= 0)
                    storeAppendPrintf(entry, "%d", t->widthMin);

                if (t->widthMax >= 0)
                    storeAppendPrintf(entry, ".%d", t->widthMax);

                if (arg)
                    storeAppendPrintf(entry, "{%s}", arg);
