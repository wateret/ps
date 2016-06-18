#include <stdio.h>
#include <vector>
using namespace std;

typedef long long ll;

struct Pt {
	int x, y;
	Pt(int x, int y) : x(x), y(y) {}
	Pt() {}
};

struct Line {
	Pt st, ed;
	Line(Pt st, Pt ed) : st(st), ed(ed) {}
	Line() {}
	bool isPtOut(Pt p) const {
		return ((ll)(p.y-st.y))*(ed.x-st.x) >= ((ll)(p.x-st.x))*(ed.y-st.y);
	}
};

class QuadTree {
	// layout
	// |01|
	// |32|
	Pt lt;
	Pt rb;
	QuadTree* sec[4];
	vector<Pt> pts;

	bool contains(Pt p) {
		return (lt.y <= p.y && p.y < rb.y)
			&& (lt.x <= p.x && p.x < rb.x);
	}
	bool insertToChild(Pt p) {
		for (int j = 0; j < 4; j++)
			if (sec[j]->insert(p))
				return true;;
		return false;
	}
	void divide() {
		// calculate area for each sections
		Pt centre = Pt((lt.x+rb.x)/2, (lt.y+rb.y)/2);
		sec[0] = new QuadTree(lt, centre);
		sec[1] = new QuadTree(Pt(centre.x, lt.y), Pt(rb.x, centre.y));
		sec[2] = new QuadTree(centre, rb);
		sec[3] = new QuadTree(Pt(lt.x, centre.y), Pt(centre.x, rb.y));

		/*
		// distribute points -> no need?
		for(int i = 0, sz = pts.size(); i < sz; i++)
			insertToChild(pts[i]);	// if it returns false, error! but not handled
		// current tree does not have points anymore
		pts.clear();
		*/
	}
	bool isLeaf() { return !sec[0]; }
public:
	static const int capacity = 64;
	QuadTree(Pt lt, Pt rb) : lt(lt), rb(rb) {
		sec[0] = NULL;
		pts.reserve(capacity);
	}
	bool insert(Pt p) {
		// Ignore objects that do not belong in this quad tree
		if (!contains(p))
			return false;
		// If there is space in this quad tree, add the object here
		if (pts.size() < capacity) {
			pts.push_back(p);
			return true;
		}

		if (isLeaf())
			divide();
		return insertToChild(p);	// if it returns false, error! but not handled
	}
	bool outerPtExist(const Line& line) {
		bool t[4];
		t[0] = line.isPtOut(lt);
		t[1] = line.isPtOut(rb);
		t[2] = line.isPtOut(Pt(lt.x, rb.y));
		t[3] = line.isPtOut(Pt(rb.x, lt.y));
		if (t[0]&&t[1]&&t[2]&&t[3]) {	// outer
			// if this node contains at least 1 point, return true
			if (pts.size() > 0)
				return true;
		} else if (t[0]||t[1]||t[2]||t[3]) {	// intersect
			for (int i = 0, sz = pts.size(); i < sz; i++)
				if (line.isPtOut(pts[i]))
					return true;
			if (isLeaf())
				return false;
			for (int i = 0; i < 4; i++)
				if (sec[i]->outerPtExist(line))
					return true;
		}
		return false;
	}
};

#define MXI 1000000010

int N, M;
Pt A[100010];
Pt B[20010];

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		A[i] = Pt(a, b);
	}
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		B[i] = Pt(a, b);
	}

	QuadTree qt(Pt(-MXI, -MXI), Pt(MXI, MXI));
	for (int i = 0; i < M; i++)
		qt.insert(B[i]);

	A[N] = A[0];
	bool ans = true;
	for (int i = 0; i < N; i++) {
		if (qt.outerPtExist(Line(A[i], A[i+1]))) {
			ans = false;
			break;
		}
	}
	printf("%s\n", ans ? "YES" : "NO");

	return 0;
}
