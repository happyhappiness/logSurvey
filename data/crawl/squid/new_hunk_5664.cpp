	if (hlp->n_running < hlp->n_to_start / 2)
	    fatalf("Too few %s processes are running", hlp->id_name);
    }
    cbdataReferenceDone(srv->parent);
    cbdataFree(srv);
}
