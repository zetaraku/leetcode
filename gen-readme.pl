#!/usr/bin/perl
use File::Basename;

my %dtag = (
  easy => '<span style="color: #00af9b;">Easy</span>',
  medium => '<span style="color: #ffb800;">Medium</span>',
  hard => '<span style="color: #ff2d55;">Hard</span>',
);
my %dcount = (
  easy => 0,
  medium => 0,
  hard => 0,
);

my @fileinfo;

foreach my $difficulty ('easy', 'medium', 'hard') {
  foreach my $filepath (<code/$difficulty/*>) {
    my $filename = basename($filepath);
    my ($no) = $filename =~ /^(\d+)/;
    my ($title, $link, $tc, $sc);

    open my $fd, '<', $filepath or die "Can't open $filepath: $!";
    while (<$fd>) {
      $title = $1 if m"^(?://|#|--) Title: (.*)$";
      $link = $1 if m"^(?://|#|--) Link: (.*)$";
      $tc = $1 if m"^(?://|#|--) Time complexity: (.*)$";
      $sc = $1 if m"^(?://|#|--) Space complexity: (.*)$";
    }
    close $fd;

    push @fileinfo, {
      difficulty => $dtag{$difficulty},
      no => $no // 9999,
      title => $title || undef,
      link => $link || undef,
      filename => $filename,
      filepath => $filepath,
      tc => $tc // 'N/A',
      sc => $sc // 'N/A',
    };

    $dcount{$difficulty}++;
  }
}

print <<EOF;
# leetcode

My [LeetCode](https://leetcode.com/) submissions

- $dtag{easy}: $dcount{easy}
- $dtag{medium}: $dcount{medium}
- $dtag{hard}: $dcount{hard}

## Index

| No. | Difficulty | Title | Code | Time complexity | Space complexity |
| ---:| ---------- | ----- | ---- | --------------- | ---------------- |
EOF

foreach (sort { $a->{no} <=> $b->{no} } @fileinfo) {
  my $title = defined $_->{link} ? "[$_->{title}]($_->{link})" : "$_->{title}";
  my $code = "[$_->{filename}](./$_->{filepath})";

  print <<LINE;
| $_->{no} | $_->{difficulty} | $title | $code | `$_->{tc}` | `$_->{sc}` |
LINE
}
