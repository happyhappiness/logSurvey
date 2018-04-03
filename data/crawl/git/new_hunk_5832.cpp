					continue;
				}
				if (!getcwd(cwd, PATH_MAX))
					die_errno("unable to get current working directory");
				printf("%s/.git\n", cwd);
				continue;
			}
