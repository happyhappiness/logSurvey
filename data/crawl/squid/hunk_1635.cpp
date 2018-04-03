 my $reConstructor = $Pairs{$Thing}->[0];
 my $reDestructor = $Pairs{$Thing}->[1];
 
-my %Alive = ();
+my %AliveCount = ();
+my %AliveImage = ();
 my $Count = 0;
 while (<STDIN>) {
-	if (/$reConstructor/) {
-		#die($_) if $Alive{$1};
-		$Alive{$1} = $_;
-		++$Count;
+	if (my @conIds = (/$reConstructor/)) {
+		my $id = join(':', @conIds);
+		#die($_) if $Alive{$id};
+		$AliveImage{$id} = $_;
+		++$Count unless $AliveCount{$id}++;
 	} 
-	elsif (/$reDestructor/) {
-		#warn("unborn: $_") unless $Alive{$1};
-		$Alive{$1} = undef();
+	elsif (my @deIds = (/$reDestructor/)) {
+		my $id = join(':', @deIds);
+		#warn("unborn: $_") unless $AliveCount{$id};
+		$AliveImage{$id} = undef() unless --$AliveCount{$id};
 	}
 }
 
 printf(STDERR "Found %d %s\n", $Count, $Thing);
 
-my $AliveCount = 0;
-foreach my $alive (sort grep { defined($_) } values %Alive) {
+my $aliveCount = 0;
+foreach my $alive (sort grep { defined($_) } values %AliveImage) {
 	next unless defined $alive;
 	printf("Alive: %s", $alive);
-	++$AliveCount;
+	++$aliveCount;
 }
 
-printf(STDERR "found %d still-alive %s\n", $AliveCount, $Thing);
+printf(STDERR "found %d still-alive %s\n", $aliveCount, $Thing);
 
 exit(0);
