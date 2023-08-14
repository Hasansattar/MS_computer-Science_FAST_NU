//	Takes Y-iterations
int power( int X, int Y )
{
	if( Y == 1 )
		return X;
	return X * power(X, Y-1);
}

//	Takes Y+1-iterations
int power( int X, int Y )
{
	if( Y == 0 )
		return 1;
	return X * power(X, Y-1);
}

