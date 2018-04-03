if len(args) == 1:
    origin = args[0]

if len(master) == 0:
    sys.stdout.write("Auto-detecting current branch: ")
    master = os.popen("git-name-rev HEAD").read().split(" ")[1][:-1]
    if len(master) == 0 or not os.path.exists("%s/refs/heads/%s" % (gitdir, master)):
        die("\nFailed to detect current branch! Aborting!");
    sys.stdout.write("%s\n" % master)

def system(cmd):
    if os.system(cmd) != 0: