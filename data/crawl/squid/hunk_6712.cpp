 	"id", "name", "#alive", "%err", "%repeat");
     for (ht = 0; ht < HDR_ENUM_END; ht++) {
 	field_attrs_t *f = Headers+ht;
-	storeAppendPrintf(e, "%2d\t %-20s\t %5d\t %6.3f\t %6.3f\n",
+	storeAppendPrintf(e, "%2d\t %-20s\t %5d\t %6.3lf\t %6.3lf\n",
 	    f->id, f->name, f->stat.aliveCount,
 	    xpercent(f->stat.errCount, f->stat.parsCount), 
 	    xpercent(f->stat.repCount, f->stat.parsCount));