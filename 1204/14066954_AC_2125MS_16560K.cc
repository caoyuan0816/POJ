//Author: Yuan25
//I THINK THEREFORE I AM

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstring>

using namespace std;

int N,M,L;
vector<string> puzzle;

//定义八个方向,A,B,C,D,E,F,G,H
int dx[8] = {-1,-1,0,1,1,1,0,-1};
int dy[8] = {0,1,1,1,0,-1,-1,-1};

struct Ans{
    bool flag;
    int x,y;
    char dir;
    Ans():x(0),y(0),flag(false){
        dir = ' ';
    }
};

vector<Ans*> anss;

//此节点用于拥有26个大写或小写字母的问题
struct Node{
    
    //标记是否为单词节点
    bool flag;
    //当前深度
    int deep;
    //记录答案
    Ans *ans;
    Node *ch[26];
    //记录他的后缀节点
    Node *suffix;
    
    Node():flag(false){
        memset(ch, 0, sizeof(ch));
        suffix = NULL;
        deep = 0;
    }
};

Node *root;
vector<Node*> trie;

//trie树插入操作，构造trie树
void trie_insert(string &str, int deep, Node *node){
    
    node->deep = deep;
    if (deep == str.length()) {
        (*node).flag = true;
        node->ans = new Ans();
        anss.push_back(node->ans);
        return;
    }
    
    Node *next = (*node).ch[str[deep]-'A'];
    if (next == NULL) {
        next = (*node).ch[str[deep]-'A'] = new Node();
        trie.push_back(next);
        trie_insert(str,deep+1,next);
    }else{
        trie_insert(str, deep+1, next);
    }
    return;
}

//在trie树的基础上构造trie图
//BFS遍历所有节点
void build_trie_graph(){
    
    queue<Node*> que;
    que.push(root);
    
    while (!que.empty()) {
        Node* cur = que.front();
        que.pop();
        for (int i = 0; i < 26; i++) {
            if (cur->ch[i] == NULL) {
                if (cur == root) {
                    cur->ch[i] = root;
                }else{
                    cur->ch[i] = cur->suffix->ch[i];
                    if (cur->suffix->ch[i]->flag) {
                        cur->ch[i]->flag = true;
                    }
                }
            }else{
                if (cur == root) {
                    cur->ch[i]->suffix = root;
                }else{
                    cur->ch[i]->suffix = cur->suffix->ch[i];
                }
                que.push(cur->ch[i]);
            }
        }
    }
    
    return;
}

//使用trie图当做字典，在原串str上匹配，得到原串中是否含有字典中词语，为减小复杂度，匹配到第一个就退出
void trie_graph_match(string &str, int x, int y, int dir){
    
    Node* cur = root;
    for (int i = 0 ; i < str.length(); i++) {
        cur = cur->ch[str[i]-'A'];
        if (cur->flag && !cur->ans->flag) {
            int beg = i - (cur->deep) + 1;
            cur->ans->x = x + beg * dx[dir];
            cur->ans->y = y + beg * dy[dir];
            cur->ans->dir = dir+'A';
            cur->ans->flag = true;
        }
    }
    return;
}

//所有节点的析构
void trie_clean(){
    for (int i = 0 ; i < trie.size(); i++) {
        if (trie[i]->flag) {
            delete trie[i]->ans;
        }
        delete trie[i];
    }
    return;
}


bool check(int x, int y){
    return (x >= 0 && x <= N-1 && y >= 0 && y <= M-1);
}

//得到每个X,Y位置处的所有原串并测试
void test(int x, int y){
    
    string use;
    int a,b;
    
    //分别测试八个方向
    for (int i = 0; i < 8; i++) {
        a = x, b = y;
        if (check(a+dx[i],b+dy[i]) && !check(a-dx[i],b-dy[i])) {
            use.clear();
            while (check(a,b)) {
                use.push_back(puzzle[a][b]);
                a += dx[i];
                b += dy[i];
            }
            trie_graph_match(use, x, y, i);
        }
    }
}

int main(void) {
    
    //优化IO速度
    std::ios::sync_with_stdio(false);
    
    root = new Node();
    trie.push_back(root);
    root->suffix = root;
    
    cin >> N >> M >> L;
    
    string use;
    for (int i = 0; i < N; i++) {
        cin >> use;
        puzzle.push_back(use);
    }
    
    for (int i = 0; i < L; i++) {
        cin >> use;
        trie_insert(use, 0, root);
    }
    build_trie_graph();
    
    for (int i = 0; i < M; i++) {
        test(0,i);
        test(N-1,i);
    }
    
    for (int i = 1; i < N-1; i++) {
        test(i,0);
        test(i,N-1);
    }
    
    for (int i = 0; i < anss.size(); i++) {
        cout << anss[i]->x << " " << anss[i]->y << " " << anss[i]->dir<<" "<<endl;
    }
    
    trie_clean();
    return 0;
}