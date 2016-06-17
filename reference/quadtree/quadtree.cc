#include <iostream>
#include <vector>
using namespace std;

struct Point {
  int x, y;
  Point(int x, int y) : x(x), y(y) {}
  Point() : x(0), y(0) {}
};

class QuadTree {
  // layout
  // |01|
  // |32|
  Point lt;
  Point rb;
  QuadTree* sec[4];
  vector<Point> pts;

  bool contains(Point p) {
    return (lt.y <= p.y && p.y < rb.y)
      && (lt.x <= p.x && p.x < rb.x);
  }

  bool insertToChild(Point p) {
    for (int j = 0; j < 4; j++)
      if (sec[j]->insert(p))
        return true;
    return false;
  }

  void divide() {
    // calculate area for each sections
    Point centre = Point((lt.x+rb.x)/2, (lt.y+rb.y)/2);
    sec[0] = new QuadTree(lt, centre);
    sec[1] = new QuadTree(Point(centre.x, lt.y), Point(rb.x, centre.y));
    sec[2] = new QuadTree(centre, rb);
    sec[3] = new QuadTree(Point(lt.x, centre.y), Point(centre.x, rb.y));

    /*
    // distribute points
    for(int i = 0, sz = pts.size(); i < sz; i++)
      insertToChild(pts[i]);  // if it returns false, error! but not handled
    // current tree does not have points anymore
    pts.clear();
    */
  }

  bool isLeaf() { return !sec[0]; }

 public:
  static const int capacity = 4;
  QuadTree(Point lt, Point rb) : lt(lt), rb(rb) {
    sec[0] = NULL;
  }

  bool insert(Point p) {
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
    return insertToChild(p);    // if it returns false, error! but not handled
  }

};

bool isLeft(Point p1, Point p2, Point q) {
  return ((p2.x - p1.x) * (q.y - p1.y) - (p2.y - p1.y) * (q.x - p1.x)) > 0;
}
