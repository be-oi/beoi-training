program ghostbusters;

{
	Source: http://www.algorithmist.com/index.php/Longest_Increasing_Subsequence.cpp
	Adapted by G. Geeraerts
}

const MAX=20;

var
	a, b : array [0..MAX-1] of integer;
	k, l : integer;
	nb_ghostbusters, nb_instances : integer;


{ 
	Finds longest strictly increasing subsequence. O(n log k) algorithm. 
	a is the sequence of inputs, of length n 
	the function should write in b the sequences of indices (terminated by -1) s.t. a[b[0]], a[b[1]], ... is the longest
	increasing sequence in a 
}
procedure find_lis(var a : array of integer; var b : array of integer; n : integer);
	var
		u, v, i, j, c : integer;
		p : array [1..MAX] of integer;

	begin	
		j := -1;
		
		if n <> 0 then begin
			
			j := j+1;
			b[j] := 0;
			
			for i := 1 to n-1 do begin
				{ 
					If next element a[i] is greater than last element of current longest subsequence a[b.back()], 
					just push it at back of "b" and continue
				}
				if a[b[j]] < a[i]	then begin
					p[i] := b[j];
					j := j+1;
					b[j] := i;
					continue;
				end;
						
				{
					Binary search to find the smallest element referenced by b which is just bigger than a[i]
					Note : Binary search is performed on b (and not a). Size of b is always <=k and 
					hence contributes O(log k) to complexity.    				
				}

				u := 0;
				v := j;
				while u < v do begin		
					c := (u + v) div 2;
					if a[b[c]] < a[i] then 
						u := c+1
					else 
						v := c;
				end;
				
				{ Update b if new value is smaller then previously referenced value }
				if (a[i] < a[b[u]]) then begin
					if u > 0 then
						p[i] := b[u-1];
					b[u] := i;
				end;

			end; { endfor i := 0 to n-1}

			u := j+1;
			v := b[j];
				
			while u > 0 do begin
				u := u-1;
				b[u] := v;
				v := p[v];
			end;
					
			b[j+1] := -1 ;
				
		end; { endif n <> 0 }
	end; {end procedure}

{
	Usage sample
}
begin
	
	{ All values are assumed in the interval [-90, 90] }
	read(nb_instances, nb_ghostbusters);
	
	for k := 0 to nb_instances-1 do begin
		for l := 0 to nb_ghostbusters-1 do begin
			read(a[l]);
		end;
				
		find_lis(a, b, nb_ghostbusters);
		
		l := 0;
		while b[l] <> -1 do begin
			write(b[l]+1, ' ');
			l := l+1;
		end;
		writeln;
		
	end;
end.
	
