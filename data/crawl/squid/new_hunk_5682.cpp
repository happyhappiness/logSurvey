    k->bytes &= 0x3FF;
}

void
debugObj(int section, int level, const char *label, void *obj, ObjPackMethod pm)
{
