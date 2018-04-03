 			ctx.argv[0] = "--children";
 			reverse = 1;
 		}
-		n = handle_revision_opt(&revs, ctx.argc, ctx.argv,
-					&ctx.cpidx, ctx.out);
-		if (n <= 0) {
-			error("unknown option `%s'", ctx.argv[0]);
-			usage_with_options(blame_opt_usage, options);
-		}
-		ctx.argv += n;
-		ctx.argc -= n;
+		parse_revision_opt(&revs, &ctx, options, blame_opt_usage);
 	}
 parse_done:
 	argc = parse_options_end(&ctx);
