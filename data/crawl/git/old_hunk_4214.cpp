

    def getClientSpec(self):
        specList = p4CmdList( "client -o" )
        temp = {}
        for entry in specList:
            for k,v in entry.iteritems():
                if k.startswith("View"):

                    # p4 has these %%1 to %%9 arguments in specs to
                    # reorder paths; which we can't handle (yet :)
                    if re.search('%%\d', v) != None:
                        print "Sorry, can't handle %%n arguments in client specs"
                        sys.exit(1)
                    if re.search('\*', v) != None:
                        print "Sorry, can't handle * mappings in client specs"
                        sys.exit(1)

                    if v.startswith('"'):
                        start = 1
                    else:
                        start = 0
                    index = v.find("...")

                    # save the "client view"; i.e the RHS of the view
                    # line that tells the client where to put the
                    # files for this view.

                    # check for individual file mappings - those which have no '...'
                    if  index < 0 :
                        v,cv = v.strip().split()
                        v = v[start:]
                        self.haveSingleFileClientViews = True
                    else:
                        cv = v[index+3:].strip() # +3 to remove previous '...'
                        cv=cv[:-3]
                        v = v[start:index]

                    # now save the view; +index means included, -index
                    # means it should be filtered out.
                    if v.startswith("-"):
                        v = v[1:]
                        include = -len(v)
                    else:
                        include = len(v)

                    # store the View #number for sorting
                    # and the View string itself (this last for documentation)
                    temp[v] = (include, cv, int(k[4:]),k)

        self.clientSpecDirs = temp.items()
        # Perforce ViewNN with higher #numbers override those with lower
        # reverse sort on the View #number
        self.clientSpecDirs.sort( lambda x, y:  y[1][2] -  x[1][2]  )
        if self.verbose:
            for val in self.clientSpecDirs:
                    print "clientSpecDirs: %s %s" % (val[0],val[1])

    def run(self, args):
        self.depotPaths = []
