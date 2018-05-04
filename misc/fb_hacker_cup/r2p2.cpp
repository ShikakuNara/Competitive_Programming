#include <bits/stdc++.h>
using namespace std;


int main()
{
	cout<<"hi"<<endl;
	ifstream in("pie_progress_example_input.txt");
  ofstream out("outputr2p2.txt");

  	int T, N, M;
  	int a[300][300];
  	in >> T ;

for(int num=0; num < T; num++)
{
	cout<<"STUCK IN TEST LOOP...\n";
  	in>> N >> M;

  	//getting all costs
  	for(int i =0; i < N; i++)
  		for(int j =0; j < M; j++)
  		{
  			in >> a[i][j];
  		}


  	//sorting costs of each day
  	for(int i =0; i<M; i++)
  		sort(a[i], a[i] + M);

  	//adding the p*p term
  	for(int i =0; i < N; i++)
  		for(int j =0; j < M; j++)
  		{
  			a[i][j] += 2 * j + 1;
  		}

  	int taken = 1; //number of pies taken
  				   //first pie aleady taken
  	int pieRow[300]; //how many pies taken each day
  	int cost = a[0][0];//cost of first pie

  	//initialising rows
  	for(int i=0; i<N; i++)
  		pieRow[i] = -1;
  	pieRow[0] = 0; //first pie taken

  	//taking n pies
  	while(taken < N)
  	{
  		cout<<"STUCK IN PIE LOOP...\n";
  		//minimum of new pies
  		int min[2] = {0, pieRow[0] + 1};

  		int i = 0;
  		while( pieRow[i] >= 0 && i < N) //days visited
  		{
  			cout<<"STUCK IN DAY LOOP...\n";
  			//next pie of covered days
  			if( a[min[0]][min[1]] < a[i][pieRow[0] + 1] )
  			{
  				min[0] = i;
  				min[1] = pieRow[0] + 1;
  			}
  			i++;
  		}
  		//first pie of new day
  		if( a[min[0]][min[1]] < a[i][pieRow[0] + 1] )
		{
			min[0] = i;
			min[1] = pieRow[0] + 1;
		}

		//updation
  		pieRow[min[0]] = min[1];
  		cost += a[min[0]][min[1]];

  		taken++;
  	}

  	out<< "Case #"<<num+1<<": "<<cost<<endl;
}

















	return 0;
}
