					die("Multiple --remote specified");
				remote = arg + 9;
				continue;
			}
			if (arg[0] != '-')
				no_more_options = 1;