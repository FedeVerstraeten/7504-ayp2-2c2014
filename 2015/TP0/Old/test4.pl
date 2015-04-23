#! /usr/bin/perl
#
# test4.pl - genera una secuencia de pares complejos de entrada
# de tal forma que la salida demodulada de la misma alterne el
# signo.
#
# $Id: test4.pl,v 1.2 2015/04/05 19:18:30 lesanti Exp $

$pi = abs(atan2(0, -1));
$sign = 1.0;

while (1) {
	$phi += $pi / 10 * $sign;
	$re = cos($phi);
	$im = sin($phi);
	$sign *= -1.0;

	print "($re, $im)\n" x 44;
}
