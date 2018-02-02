#include<map>
#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

template<typename T>
void input(T &x) {
	x=0; T a=1;
	register char c=getchar();
	for(;c<48||c>57;c=getchar())
		if(c==45) a=-1;
	for(;c>=48&&c<=57;c=getchar())
		x=x*10+c-48;
	x*=a;
	return;
}

typedef string str;

struct PROBLEM {
	str p,link;
	bool operator < (const PROBLEM &q) const {
		if(p.size()!=q.p.size())
			return p.size()<q.p.size();
		return p<q.p;
	}
};

map<str,int> id;
string Const_link[110];

struct OnlineJudge {
	
	static const int MAXN=10010;
	
	PROBLEM pro[MAXN];
	int cnt;
	string Oj;
	bool flag;

	OnlineJudge(): cnt(0),flag(false) {}

	void add_problem(str oj,str p) {
		str &s=pro[++cnt].link;
		pro[cnt].p=p,s=Const_link[id[oj]];
		if(oj!="codeforces") s+=p;
		else {
			for(int i=0;i<p.size();i++) {
				if(p[i]>='A'&&p[i]<='Z') s+="/";
				s+=p[i];
			}
		}
		return;
	}

	void Order() {
		sort(pro+1,pro+cnt+1),flag=true;
		return;
	}

	void Print() {
		if(!flag) Order();
		printf("| OnlineJudge: %s | Status(0/%d) |\n",Oj.c_str(),cnt);
		printf("| :-------------- | :----: |\n");
		for(int i=1;i<=cnt;i++)
			printf("| [%s](%s) | N/A |\n",pro[i].p.c_str(),pro[i].link.c_str());
		puts("");
		return;
	}

};

str get_OnlineJudge(str s) {
	for(int i=0;i<s.size();i++)
		if(s[i]>='A'&&s[i]<='Z')
			s[i]=s[i]-'A'+'a';
	if(s=="sphereonlinejudge") s="spoj";
	if(s=="libreoj") s="loj";
	if(s=="universalonlinejudge") s="uoj";
	if(s=="cf") s="codeforces";
	if(s=="cc") s="codechef";
	if(s=="qingcheng"||s=="qc") s="tsinsen";
	if(s=="lg") s="luogu";
	return s;
}

str get_Problem(str oj,str p) {
	int x=id[oj];
	if(x!=9&&x!=11&&x!=3&&x!=4) return p;
	bool flag=false;
	if((x==9&&p[0]=='P')||(x==11&&p[0]=='A')||((x==3||x==4)&&p[0]=='#')) {
		str ret;
		for(int i=1;i<p.size();i++)
		ret+=p[i];
		return ret;
	}
	return p;
}

OnlineJudge OJ[110];

struct Data {
	int cnt,id;
	bool operator < (const Data &q) const {
		return cnt>q.cnt;
	}
};

Data a[110];

int main() {
	id["bzoj"]=1,id["hdu"]=2,id["uoj"]=3,id["loj"]=4,
	id["codeforces"]=5,id["codechef"]=6,id["poj"]=7,
	id["ural"]=8,id["luogu"]=9,id["51nod"]=10,
	id["tsinsen"]=11,id["gym"]=12,id["spoj"]=13;
	
	Const_link[1]="http://www.lydsy.com/JudgeOnline/problem.php?id=";
	Const_link[2]="http://acm.hdu.edu.cn/showproblem.php?pid=";
	Const_link[3]="http://uoj.ac/problem/";
	Const_link[4]="https://loj.ac/problem/";
	Const_link[5]="http://codeforces.com/problemset/problem/";
	Const_link[6]="https://www.codechef.com/problems/";
	Const_link[7]="http://poj.org/problem?id=";
	Const_link[8]="http://acm.timus.ru/problem.aspx?space=1&num=";
	Const_link[9]="https://www.luogu.org/problemnew/show/P";
	Const_link[10]="http://www.51nod.com/onlineJudge/questionCode.html#!problemId=";
	Const_link[11]="http://www.tsinsen.com/A";
	Const_link[12]="http://codeforces.com/gym/";
	Const_link[13]="http://www.spoj.com/problems/";
	
	OJ[1].Oj="BZOJ",OJ[2].Oj="HDU",OJ[3].Oj="UOJ",OJ[4].Oj="LOJ",
	OJ[5].Oj="CodeForces",OJ[6].Oj="CodeChef",OJ[7].Oj="POJ",OJ[8].Oj="URAL",
	OJ[9].Oj="Luogu",OJ[10].Oj="51Nod",OJ[11].Oj="Tsinsen",OJ[12].Oj="Gym",
	OJ[13].Oj="SPOJ";
	
	str str_in,str_out;
	cin>>str_in>>str_out;
	if(str_in!="no") freopen(str_in.c_str(),"r",stdin);
	if(str_out!="no") freopen((str_out+".md").c_str(),"w",stdout);
	for(int i=0;i<110;i++) a[i].id=i;
	str oj,p;
	while(cin>>oj>>p) {
		oj=get_OnlineJudge(oj),p=get_Problem(oj,p);
		OJ[id[oj]].add_problem(oj,p);
		a[id[oj]].cnt++;
	}
	sort(a+1,a+14);
	for(int i=1;i<=14;i++)
		if(OJ[a[i].id].cnt) OJ[a[i].id].Print();
		else break;
	if(str_in!="no") fclose(stdin);
	if(str_out!="no") fclose(stdout);
	return 0;
}
