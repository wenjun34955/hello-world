#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<string>
using namespace std;
typedef pair<string,int> PAIR;
typedef map<string,int> MAP;

template<class _Tp>
struct cmp :public binary_function<_Tp,_Tp,bool> 
{
	bool operator()(const _Tp& x, const _Tp& y) const{
		return x.second < y.second;
	}
};

template<class _Tp>
PAIR sort_map(_Tp& dic){
	typename _Tp::iterator it;
	vector<PAIR> vectorMap;
	for(it = dic.begin(); it!=dic.end();it++){
		vectorMap.push_back(*it);
	}
	sort(vectorMap.begin(),vectorMap.end(),cmp<PAIR>());
	PAIR minElem(vectorMap[0]);
	dic.clear();
	for(int i=1;i<vectorMap.size();i++){
		dic[vectorMap[i].first] = vectorMap[i].second;
	}
	return minElem;
}

int main(){
	MAP dic1;
	MAP dic2;
	map<string,MAP> adjacency;
	dic1 = {{"D",0}};
	dic2 = {{"A",1000},{"B",1000},{"C",3},{"E",4},{"F",1000},{"G",1000}};
	adjacency["A"] = {{"B",12},{"C",1000},{"D",1000},{"E",1000},{"F",16},{"G",14}};
	adjacency["B"] = {{"A",12},{"C",10},{"D",1000},{"E",1000},{"F",7},{"G",1000}};
	adjacency["C"] = {{"A",1000},{"B",10},{"D",3},{"E",5},{"F",6},{"G",1000}};
	adjacency["D"] = {{"A",1000},{"B",1000},{"C",3},{"E",4},{"F",1000},{"G",1000}};
	adjacency["E"] = {{"A",1000},{"B",1000},{"C",5},{"D",4},{"F",2},{"G",8}};
	adjacency["F"] = {{"A",16},{"B",7},{"C",6},{"D",1000},{"E",2},{"G",9}};
	adjacency["G"] = {{"A",14},{"B",1000},{"C",1000},{"D",1000},{"E",8},{"F",9}};
	MAP::iterator it2;
	MAP::iterator it1;
	while(dic2.size()>0){
		PAIR minElem;
		minElem = sort_map(dic2);
		dic1[minElem.first] = minElem.second;
		for(it2=dic2.begin();it2!=dic2.end();it2++){
			for(it1=dic1.begin();it1!=dic1.end();it1++){
				if(it2->second > adjacency[it2->first][it1->first]+dic1[it1->first]){
					it2->second = adjacency[it2->first][it1->first]+dic1[it1->first];
				}
			}
		}
	}
	for(auto &it:dic1){
		cout << it.first << ' ' << it.second << endl;
	}
	return 0;
}



