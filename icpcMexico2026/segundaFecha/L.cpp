#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long u64;
static const int MAXN = 70000000;
uint64_t isComp[(MAXN>>6)+2];
uint64_t comp[(MAXN>>6)+2];
int32_t cnt[MAXN+1];

static inline void setbit(uint64_t* a,int i){ a[i>>6]|=(1ULL<<(i&63)); }
static inline bool getbit(const uint64_t* a,int i){ return (a[i>>6]>>(i&63))&1ULL; }

static inline u64 powmod(u64 a,u64 e,u64 m){
    u64 r=1%m; a%=m;
    while(e){ if(e&1) r=(r*a)%m; a=(a*a)%m; e>>=1; }
    return r;
}

static char buf[1<<20];
static int bl=0,bp=0;
static inline int gc(){ if(bp==bl){ bl=fread(buf,1,1<<20,stdin); bp=0; if(!bl) return -1;} return buf[bp++]; }
static inline int readInt(){
    int c=gc(); while(c<'0'||c>'9') c=gc();
    int v=0; while(c>='0'&&c<='9'){ v=v*10+c-'0'; c=gc(); }
    return v;
}

int main(){
    setbit(isComp,0); setbit(isComp,1);
    for(long long i=2;i*i<=MAXN;i++)
        if(!getbit(isComp,(int)i))
            for(long long j=i*i;j<=MAXN;j+=i) setbit(isComp,(int)j);

    for(int n=3;n<=MAXN;n+=2) setbit(comp,n); // p=2 case

    for(long long p=5;p<=MAXN;p+=4){
        if(getbit(isComp,(int)p)) continue;
        u64 e4=(u64)(p-1)/4, r=0;
        for(u64 a=2;;a++){
            u64 x=powmod(a,e4,(u64)p);
            if((x*x)%(u64)p==(u64)(p-1)){ r=x; break; }
        }
        u64 r2=(u64)p-r;
        {
            long long st=(r*r+1==(u64)p)?(long long)r+p:(long long)r;
            for(long long n=st;n<=MAXN;n+=p) setbit(comp,(int)n);
        }
        {
            long long st=(r2*r2+1==(u64)p)?(long long)r2+p:(long long)r2;
            for(long long n=st;n<=MAXN;n+=p) setbit(comp,(int)n);
        }
    }

    int run=0; cnt[0]=0;
    for(int n=1;n<=MAXN;n++){ if(!getbit(comp,n)) run++; cnt[n]=run; }

    int Q=readInt();
    string out; out.reserve((size_t)Q*9);
    for(int i=0;i<Q;i++){
        int N=readInt(); int v=cnt[N];
        char t[12]; int l=0;
        if(v==0) t[l++]='0';
        else while(v>0){ t[l++]=char('0'+v%10); v/=10; }
        while(l>0) out.push_back(t[--l]);
        out.push_back('\n');
    }
    fwrite(out.data(),1,out.size(),stdout);
    return 0;
}