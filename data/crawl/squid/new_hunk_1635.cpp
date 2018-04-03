my $reConstructor = $Pairs{$Thing}->[0];
my $reDestructor = $Pairs{$Thing}->[1];

my %AliveCount = ();
my %AliveImage = ();
my $Count = 0;
while (<STDIN>) {
	if (my @conIds = (/$reConstructor/)) {
		my $id = join(':', @conIds);
		#die($_) if $Alive{$id};
		$AliveImage{$id} = $_;
		++$Count unless $AliveCount{$id}++;
	} 
	elsif (my @deIds = (/$reDestructor/)) {
		my $id = join(':', @deIds);
		#warn("unborn: $_") unless $AliveCount{$id};
		$AliveImage{$id} = undef() unless --$AliveCount{$id};
	}
}

printf(STDERR "Found %d %s\n", $Count, $Thing);

my $aliveCount = 0;
foreach my $alive (sort grep { defined($_) } values %AliveImage) {
	next unless defined $alive;
	printf("Alive: %s", $alive);
	++$aliveCount;
}

printf(STDERR "found %d still-alive %s\n", $aliveCount, $Thing);

exit(0);
