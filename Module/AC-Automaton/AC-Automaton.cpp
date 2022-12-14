#include <cstdio>
#include <cstring>
#include <queue>

struct Trie_Node {
    int nxt[27];
    int fail, tot;
    char ts;
};

#define maxn 1000006

struct Trie {
    Trie_Node  tree[maxn];
    bool       vis [maxn];
    const int  root = 0;
    int        Len;
    void initNode(int it, char ts) {
        tree[it].ts = ts;
        tree[it].tot = 0;
        memset(tree[it].nxt, 0, sizeof(tree[it].nxt));
    }
    void init() {
        for (int i = 0; i < maxn; i++) {
            initNode(i, '\0');
        }
        Len = 1;
    }
    void insert(char *ch) {
        int len = strlen(ch), nowId = root;
        for (int i = 0; i < len; i++) {
            if (tree[nowId].nxt[ch[i] - 'a'] == root) {
                initNode(Len, ch[i]);
                tree[nowId].nxt[ch[i] - 'a'] = Len;
                Len++;
            }
            nowId = tree[nowId].nxt[ch[i] - 'a'];
        }
        tree[nowId].tot++;
    }
    void build() {
        tree[root].fail = root;
        static std::queue<int> q;
        for (int i = 0; i < 26; i++) {
            if (tree[root].nxt[i]) {
                q.push(tree[root].nxt[i]);
                tree[tree[root].nxt[i]].fail = root;
            }
        }

        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int i = 0; i < 26; i++) {
                if (tree[u].nxt[i]) {
                    tree[tree[u].nxt[i]].fail = tree[tree[u].fail].nxt[i];
                    q.push(tree[u].nxt[i]);
                } else {
                    tree[u].nxt[i] = tree[tree[u].fail].nxt[i];
                }
            }
        }
    }
    int query(char *ch) {
        memset(vis, 0, sizeof(vis));
        int ans = 0;
        int len = strlen(ch), nowId = root;
        for (int i = 0; i < len; i++) {
            int nxtId = tree[nowId].nxt[ch[i] - 'a'];
            while (nxtId > root) {
                if (vis[nxtId]) {
                    break;
                } else {
                    vis[nxtId] = true;
                }
                if (tree[nxtId].tot != 0) {
                    ans += tree[nxtId].tot;
                    tree[nxtId].tot = 0;
                }
                nxtId = tree[nxtId].fail;
            }
            nowId = tree[nowId].nxt[ch[i] - 'a'];
        }
        return ans;
    }
}tr;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        static char chr[maxn];
        int n;
        tr.init();
        scanf("%d", &n);
        while (n--) {
            scanf("%s", chr);
            tr.insert(chr);
        }
        tr.build();
        scanf("%s", chr);
        printf("%d\n", tr.query(chr));
    }
    return 0;
}