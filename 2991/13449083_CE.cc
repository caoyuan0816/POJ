#include <cstdio>
#include <cmath>

#define LSon(x) ((x) << 1)
#define RSon(x) ((x) << 1 | 1)

const int MAXN = 10002;
const int ROOT = 1;
const double PI = acos(-1.0);
const double EPS = 1e-8;

struct Seg {
    double x, y;
    int flag;
    int degree;
};

void Rotate(Seg& node, int degree);

struct SegTree {
    Seg node[MAXN << 2];
    void Update(int pos) {
        node[pos].x = node[LSon(pos)].x + node[RSon(pos)].x;
        node[pos].y = node[LSon(pos)].y + node[RSon(pos)].y;
    }
    void Build(int l, int r, int pos) {
        node[pos].x = node[pos].y = 0;
        node[pos].flag = 0;
        node[pos].degree = 0;
        if (l == r) {
            scanf("%lf", &node[pos].y);
            return;
        }
        int m = l + r >> 1;
        Build(l, m, LSon(pos));
        Build(m + 1, r, RSon(pos));
        Update(pos);
    }
    void Push(int pos) {
        Seg& father = node[pos];
        Seg& lson = node[LSon(pos)];
        Seg& rson = node[RSon(pos)];
        if (father.flag) {
            Rotate(lson, father.flag);
            Rotate(rson, father.flag);
            lson.flag += father.flag;
            rson.flag += father.flag;
            father.flag = 0;
        }
    }
    void Modify(int l, int r, int pos, int x, int y, int z) {
        if (x <= l && r <= y) {
            Rotate(node[pos], z);
            node[pos].flag += z;
            return;
        }
        Push(pos);
        int m = l + r >> 1;
        if (x <= m) Modify(l, m, LSon(pos), x, y, z);
        if (y > m) Modify(m + 1, r, RSon(pos), x, y, z);
        Update(pos);
    }
    int Query(int l, int r, int pos, int x) {
        if (l == r) return node[pos].degree;
        Push(pos);
        int m = l + r >> 1;
        if (x <= m) return Query(l, m, LSon(pos), x);
        else return Query(m + 1, r, RSon(pos), x);
    }
};

int n, c;
int s, a;

SegTree tree;

double GetRad(int x);

int main() {
    bool first = true;
    while (scanf("%d%d", &n, &c) != EOF) {
        tree.Build(0, n - 1, ROOT);   
        printf("%s", first ? first = false, "" : "\n");
        for (int i = 0; i < c; i++) {
            scanf("%d%d", &s, &a);   
            int degree = tree.Query(0, n - 1, ROOT, s - 1) + 180 + a -
                tree.Query(0, n - 1, ROOT, s);
            tree.Modify(0, n - 1, ROOT, s, n - 1, degree);
            printf("%.2lf %.2lf\n", tree.node[ROOT].x + EPS, tree.node[ROOT].y + EPS);
        }
    }

    return 0;
}

double GetRad(int x) {
    return x * PI / 180;
}

void Rotate(Seg& node, int degree) {
    double rad = GetRad(degree);
    double x = node.x; double y = node.y;
    node.x = x * cos(rad) + y * -sin(rad);
    node.y = x * sin(rad) + y * cos(rad);
    node.degree = (node.degree + degree) % 360;
}
