#include<bits/stdc++.h>

int data_f[10000005],data_a[10000005];
inline void generate_deg(int seed){
    std::mt19937 engine(seed);int n = 1000000;std::vector<int>f(n + 5),a(n + 5),ind(n + 5),rev(n + 5),deg(n + 5);
    for(int i = 1;i <= n;++i)a[i] = engine() % 100000000 + 1;
    std::set<int>A;A.insert(1);deg[1] = 1;
	for(int i = 2;i <= n;++i){while(i - *(A.begin()) > 20)A.erase(A.begin());int s = engine() % A.size();auto it = A.begin();for(int i = 1;i <= s;++i)++it;f[i] = *it;deg[f[i]] ++ ;if(deg[f[i]] == 4){A.erase(it);}deg[i] = 1;A.insert(i);}
    for(int i = 1;i <= n;++i){data_a[i] = a[i];}
    for(int i = 1;i < n;++i){data_f[i] = f[i + 1];}
}
inline void generate(int seed){
    std::mt19937 engine(seed);int n = 1000000;std::vector<int>f(n + 5),a(n + 5),deg(n + 5);
    for(int i = 1;i <= n;++i)a[i] = engine() % 100000000 + 1;
    std::set<int>A;A.insert(1);deg[1] = 1;
	for(int i = 2;i <= n;++i){while(i - *(A.begin()) > 20)A.erase(A.begin());int s = engine() % A.size();auto it = A.begin();for(int i = 1;i <= s;++i)++it;f[i] = *it;deg[f[i]] ++ ;deg[i] = 1;A.insert(i);}
    for(int i = 1;i <= n;++i){data_a[i] = a[i];}
    for(int i = 1;i < n;++i){data_f[i] = f[i + 1];}
}



int n;
int seed;

int main(){
    scanf("%d",&id);
    if(id < 19){
        scanf("%d",&n);
        for(int i = 1;i <= n;++i)scanf("%d",&data_a[i]);
        for(int i = 1;i < n;++i)scanf("%d",&data_f[i]);
    }
    if(id == 19 || id == 20){n = 10000000;scanf("%d",&seed);generate_deg(seed);}
    if(id > 20){n = 10000000;scanf("%d",&seed);generate(seed);}
    /*
    .....
    user_solve
    */
}