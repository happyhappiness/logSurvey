             usage();
             exit(0);
         default:
-            fprintf(stderr, "%s: FATAL: unknown option: -%c. Exiting\n", program_name, opt);
+            std::cerr << program_name << ": FATAL: unknown option: -" <<
+                static_cast<char>(optopt) << ". Exiting" << std::endl;
             usage();
             exit(1);
         }
