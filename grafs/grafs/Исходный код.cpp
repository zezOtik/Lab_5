/**
\file: main.cpp
*/
#include <iostream>
#include <fstream>

using namespace std;

/*! \brief void main() - tochka vhoda v programmu
*	Chitaet razmer grafa, potom matricu grafa.
*	( -1 == "puti net" )
*   Vyvodit kratchaishie rasstoyaniya ot pervoy tochki do ostalnyh */

void main()
{

	int N;
	cin >> N;
	int** A = new int*[N];
	for (int i = 0; i<N; i++)
	{
		A[i] = new int[N];
		for (int j = 0; j<N; j++) cin >> A[i][j];
	}

	int* Ves = new int[N];
	int* Byl = new int[N];
	int Index = 0;
	int IndexNext = 0;
	Ves[0] = 0;
	for (int i = 1; i<N; i++)
	{
		Ves[i] = -1;
		Byl[i] = 0;
	}
	while (Index != N - 1)
	{
		Byl[Index] = 1;
		for (int i = 0; i<N; i++)
		{
			if ((!Byl[i]) &&
				(A[Index][i] != -1) &&
				(Ves[i] == -1 || Ves[i] > Ves[Index] + A[Index][i]))
			{
				Ves[i] = Ves[Index] + A[Index][i];
			}
		}

		IndexNext = -1;
		for (int i = 0; i<N && IndexNext == -1; i++)
			if (!Byl[i] && Ves[i] != -1) IndexNext = i;

		for (int i = 0; i<N; i++)
		{
			if ((!Byl[i]) && (Ves[i] != -1) && (Ves[i]<Ves[IndexNext]))
				IndexNext = i;
		}

		Index = IndexNext;
	}

	for (int i = 1; i<N; i++) cout << Ves[i] << ' ';
	cout << '\n';

	system("pause");

}