$pi = abs(atan2(0, -1));
$sign = 1.0;

while (1) {
	$phi += $pi / 10 * $sign;
	$re = cos($phi);
	$im = sin($phi);
	$sign *= -1.0;

	print "($re, $im)\n" x 44;
} 
