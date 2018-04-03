                if (t->zero)
                    entry->append("0", 1);

                if (t->width)
                    storeAppendPrintf(entry, "%d", (int) t->width);

                if (t->precision)
                    storeAppendPrintf(entry, ".%d", (int) t->precision);

                if (arg)
                    storeAppendPrintf(entry, "{%s}", arg);
