#include <iostream>
#include <string.h>
using namespace std;

int N;
char DIC[110][110];
bool LI[26][26];
bool V[26];
char sol[27];
int soli;
bool inv;

void topological_sort(int idx)
{
	if (V[idx])
		return;
	V[idx] = true;
	for (int i = 0; i < 26; i++)
		if (LI[idx][i])
			topological_sort(i);
	sol[--soli] = (char)('a'+idx);
}

bool get_res()
{
	for (int i = 25; i >= 0; i--)
		if (!V[i])
			topological_sort(i);

/*
	for (int i = 0; i < 26; i++)
		if (LI[i][i])
			return true;
			*/

	for (int i = 0; i < 26; i++)
		for (int j = i+1; j < 26; j++)
			if (LI[sol[j]-'a'][sol[i]-'a'])
				return true;
	return false;
}

void make_deps()
{
	int ca_st = -1;
	char ca = -1;
	for (int j = 1; j < N; j++) {
		int i = j - 1;
		int len = min(strlen(DIC[i]), strlen(DIC[j]));
		int k;
		for (k = 0; k < len; k++)
			if (DIC[i][k] != DIC[j][k]) {
				int a = DIC[i][k] - 'a';
				int b = DIC[j][k] - 'a';
				LI[a][b] = true;
				break;
			}
		if (k == len && strlen(DIC[i]) > strlen(DIC[j])) {
			inv = true;
			return;
		}
	}
}

int main()
{
	sol[26] = 0;
	soli = 26;
	memset(LI, 0, sizeof(LI));
	memset(V, 0, sizeof(V));
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> DIC[i];
	make_deps();

	if (inv || get_res())
		cout << "Impossible" << endl;
	else
		cout << sol << endl;
	return 0;
}
