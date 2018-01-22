#include <cstdio>
#include <cmath>

#define LSon(x) ((x) << 1)
#define RSon(x) ((x) << 1 | 1)

const int MAXN = 10002;
const int ROOT = 1;
const double PI = acos(-1.0);
const double EPS = 1e-8;

struct Seg {
&nbsp; &nbsp; double x, y;
&nbsp; &nbsp; int flag;
&nbsp; &nbsp; int degree;
};

void Rotate(Seg& node, int degree);

struct SegTree {
&nbsp; &nbsp; Seg node[MAXN << 2];
&nbsp; &nbsp; void Update(int pos) {
&nbsp; &nbsp; &nbsp; &nbsp; node[pos].x = node[LSon(pos)].x + node[RSon(pos)].x;
&nbsp; &nbsp; &nbsp; &nbsp; node[pos].y = node[LSon(pos)].y + node[RSon(pos)].y;
&nbsp; &nbsp; }
&nbsp; &nbsp; void Build(int l, int r, int pos) {
&nbsp; &nbsp; &nbsp; &nbsp; node[pos].x = node[pos].y = 0;
&nbsp; &nbsp; &nbsp; &nbsp; node[pos].flag = 0;
&nbsp; &nbsp; &nbsp; &nbsp; node[pos].degree = 0;
&nbsp; &nbsp; &nbsp; &nbsp; if (l == r) {
&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; scanf("%lf", &node[pos].y);
&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; return;
&nbsp; &nbsp; &nbsp; &nbsp; }
&nbsp; &nbsp; &nbsp; &nbsp; int m = l + r >> 1;
&nbsp; &nbsp; &nbsp; &nbsp; Build(l, m, LSon(pos));
&nbsp; &nbsp; &nbsp; &nbsp; Build(m + 1, r, RSon(pos));
&nbsp; &nbsp; &nbsp; &nbsp; Update(pos);
&nbsp; &nbsp; }
&nbsp; &nbsp; void Push(int pos) {
&nbsp; &nbsp; &nbsp; &nbsp; Seg& father = node[pos];
&nbsp; &nbsp; &nbsp; &nbsp; Seg& lson = node[LSon(pos)];
&nbsp; &nbsp; &nbsp; &nbsp; Seg& rson = node[RSon(pos)];
&nbsp; &nbsp; &nbsp; &nbsp; if (father.flag) {
&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; Rotate(lson, father.flag);
&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; Rotate(rson, father.flag);
&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; lson.flag += father.flag;
&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; rson.flag += father.flag;
&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; father.flag = 0;
&nbsp; &nbsp; &nbsp; &nbsp; }
&nbsp; &nbsp; }
&nbsp; &nbsp; void Modify(int l, int r, int pos, int x, int y, int z) {
&nbsp; &nbsp; &nbsp; &nbsp; if (x <= l && r <= y) {
&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; Rotate(node[pos], z);
&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; node[pos].flag += z;
&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; return;
&nbsp; &nbsp; &nbsp; &nbsp; }
&nbsp; &nbsp; &nbsp; &nbsp; Push(pos);
&nbsp; &nbsp; &nbsp; &nbsp; int m = l + r >> 1;
&nbsp; &nbsp; &nbsp; &nbsp; if (x <= m) Modify(l, m, LSon(pos), x, y, z);
&nbsp; &nbsp; &nbsp; &nbsp; if (y > m) Modify(m + 1, r, RSon(pos), x, y, z);
&nbsp; &nbsp; &nbsp; &nbsp; Update(pos);
&nbsp; &nbsp; }
&nbsp; &nbsp; int Query(int l, int r, int pos, int x) {
&nbsp; &nbsp; &nbsp; &nbsp; if (l == r) return node[pos].degree;
&nbsp; &nbsp; &nbsp; &nbsp; Push(pos);
&nbsp; &nbsp; &nbsp; &nbsp; int m = l + r >> 1;
&nbsp; &nbsp; &nbsp; &nbsp; if (x <= m) return Query(l, m, LSon(pos), x);
&nbsp; &nbsp; &nbsp; &nbsp; else return Query(m + 1, r, RSon(pos), x);
&nbsp; &nbsp; }
};

int n, c;
int s, a;

SegTree tree;

double GetRad(int x);

int main() {
&nbsp; &nbsp; bool first = true;
&nbsp; &nbsp; while (scanf("%d%d", &n, &c) != EOF) {
&nbsp; &nbsp; &nbsp; &nbsp; tree.Build(0, n - 1, ROOT); &nbsp;&nbsp;
&nbsp; &nbsp; &nbsp; &nbsp; printf("%s", first ? first = false, "" : "\n");
&nbsp; &nbsp; &nbsp; &nbsp; for (int i = 0; i < c; i++) {
&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; scanf("%d%d", &s, &a); &nbsp;&nbsp;
&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; int degree = tree.Query(0, n - 1, ROOT, s - 1) + 180 + a -
&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; tree.Query(0, n - 1, ROOT, s);
&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; tree.Modify(0, n - 1, ROOT, s, n - 1, degree);
&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; printf("%.2lf %.2lf\n", tree.node[ROOT].x + EPS, tree.node[ROOT].y + EPS);
&nbsp; &nbsp; &nbsp; &nbsp; }
&nbsp; &nbsp; }

&nbsp; &nbsp; return 0;
}

double GetRad(int x) {
&nbsp; &nbsp; return x * PI / 180;
}

void Rotate(Seg& node, int degree) {
&nbsp; &nbsp; double rad = GetRad(degree);
&nbsp; &nbsp; double x = node.x; double y = node.y;
&nbsp; &nbsp; node.x = x * cos(rad) + y * -sin(rad);
&nbsp; &nbsp; node.y = x * sin(rad) + y * cos(rad);
&nbsp; &nbsp; node.degree = (node.degree + degree) % 360;
}
