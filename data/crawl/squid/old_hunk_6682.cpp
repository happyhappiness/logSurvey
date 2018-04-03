    storeAppendPrintf(e, "%2s\t %-20s\t %5s\t %6s\t %6s\n",
	"id", "name", "#alive", "%err", "%repeat");
    for (ht = 0; ht < HDR_ENUM_END; ht++) {
	field_attrs_t *f = Headers+ht;
	storeAppendPrintf(e, "%2d\t %-20s\t %5d\t %6.3lf\t %6.3lf\n",
	    f->id, f->name, f->stat.aliveCount,
	    xpercent(f->stat.errCount, f->stat.parsCount), 
	    xpercent(f->stat.repCount, f->stat.parsCount));
    }
    storeAppendPrintf(e, "%s\n", "<hr size=1 noshade>");
