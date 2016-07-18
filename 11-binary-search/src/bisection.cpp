double f(double x) {
	return x*x*x - 4*x - 9;
}

double bisection(double low, double high, double EPS) {
	while(true) { // depends on your problem
		double mid = (low + high)/2;
		double val = f(mid);
		if(abs(val) < EPS)
			return mid;
		if(val > 0)
			high = mid;
		else if(val < 0)
			low = mid;
	}
}