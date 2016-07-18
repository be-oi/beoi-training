double f(double x) {
	return x*x*x - 4*x - 9;
}

double bisection(double low, double high, double EPS) {
	double mid = (low + high)/2;
	double val = f(mid);
	if(abs(val) < EPS)
		return mid;
	if(val > 0)
		return bisection(low, mid, EPS);
	else if(val < 0)
		return bisection(mid, high, EPS);
}