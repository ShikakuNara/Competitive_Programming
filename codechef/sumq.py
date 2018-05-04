# cook your dish here
# constant
M  = 1000000007;

def func(y, xsum, zsum, vx, vz):
	return (y*((((xsum*vz)%M)+((zsum*vx)%M))%M))%M+(vx*((vz*((y*y)%M))%M))%M+(xsum*zsum)%M;

t=int(input());


while(t>0):
	
	p,q,r =input().split();
	a = list(map(int,input().split()));
	b = list(map(int,input().split()));
	c = list(map(int,input().split()));

	p=int(p);
	q=int(q);
	r=int(r);

	a.sort();
	b.sort();
	c.sort();

	Sum = 0;
	xsum = 0;
	zsum = 0;
	vx = 0;
	vz = 0;

	for i in range(0,q):
		for j in range(vx,p):
			if a[j] > b[i]:
				break;
			
			vx += 1;
			xsum = ( xsum + a[j]) % M;

		for j in range(vz,r):
			if c[j] > b[i]:
				break;
			
			vz += 1;
			zsum = ( zsum + c[j]) % M;

		Sum = ( Sum + func(b[i], xsum, zsum, vx, vz)  ) % M;

	print(Sum, "\n");

	t=t-1;