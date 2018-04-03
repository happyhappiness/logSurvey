my $reConstructor = $Pairs{$Thing}->[0];
my $reDestructor = $Pairs{$Thing}->[1];

my %Alive = ();
my $Count = 0;
while (<STDIN>) {
	if (/$reConstructor/) {
		#die($_) if $Alive{$1};
		$Alive{$1} = $_;
		++$Count;
	} 
	elsif (/$reDestructor/) {
		#warn("unborn: $_") unless $Alive{$1};
		$Alive{$1} = undef();
	}
}

printf(STDERR "Found %d %s\n", $Count, $Thing);

my $AliveCount = 0;
foreach my $alive (sort grep { defined($_) } values %Alive) {
	next unless defined $alive;
	printf("Alive: %s", $alive);
	++$AliveCount;
}

printf(STDERR "found %d still-alive %s\n", $AliveCount, $Thing);

exit(0);
