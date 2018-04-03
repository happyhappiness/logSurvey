     const Vector<ServiceConfig*> &configs = serviceConfigs;
     debugs(93,3, "Found " << configs.size() << " service configs.");
     for (VISCI i = configs.begin(); i != configs.end(); ++i) {
+		const ServiceConfig &cfg = **i;
+		if (FindService(cfg.key) != NULL) {
+			debugs(93,0, "ERROR: Duplicate adaptation service name: " <<
+                cfg.key);
+			continue; // TODO: make fatal
+		}
         ServicePointer s = createService(**i);
         if (s != NULL)
             AllServices().push_back(s);