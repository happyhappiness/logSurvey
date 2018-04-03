     statHistDump(&f->cd.peer_choice_count, sentry, &statHistIntDumper);
     storeAppendPrintf(sentry, "\ncd.peer_ichoice_count histogram:\n");
     statHistDump(&f->cd.peer_ichoice_count, sentry, &statHistIntDumper);
+    storeAppendPrintf(sentry, "\ncd.on_xition_count histogram:\n");
+    statHistDump(&f->cd.on_xition_count, sentry, &statHistIntDumper);
 #endif
 #if TOO_MUCH_OUTPUT
     storeAppendPrintf(sentry, "icp.query_svc_time histogram:\n");
