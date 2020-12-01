#include<iostream>
#include<map>
#include<vector>
using namespace std;

typedef map<string,float> mapfloat;
typedef pair<string,float> PAIR;
template<class _Tp>
struct cmp:public binary_function<_Tp,_Tp,bool>
{
	bool operator()(const _Tp& x,const _Tp& y) const{return x.second>y.second;}
};

void beam_search(mapfloat& sequence, const vector<vector<float> >& data,const int beam_size) {
	mapfloat candidate;
	vector<PAIR> vectorsortmap;
	string path;
	float score;
	typename mapfloat::iterator it;
	for(int i=0;i<data.size();i++){
		candidate.clear();
		if(sequence.size() == 0){
			for(int j=0;j<data[0].size();j++){
				path = "";
				score = 0.0;
				path = path+to_string(j);
				score += data[i][j];
				candidate[path] = score;
			}
		}else{
			for(it=sequence.begin();it!=sequence.end();it++){
				for(int j=0;j<data[0].size();j++){
					path = it->first;
					score = it->second;
					path = path+to_string(j);
					score += data[i][j];
					candidate[path] = score;
				}
			}
		}

		
		for(it=candidate.begin();it!=candidate.end();it++){
			vectorsortmap.push_back(*it);
		}
		sequence.clear();
		sort(vectorsortmap.begin(),vectorsortmap.end(),cmp<PAIR>());
		for (int i = 0; i < beam_size; i++){
			sequence[vectorsortmap[i].first] = vectorsortmap[i].second;
		}
		vectorsortmap.clear();
	}	
}

int main(){
	vector<vector<float> > data = {{0.1, 0.2, 0.3, 0.4, 0.5},
		{0.5, 0.4, 0.3, 0.2, 0.1},
		{0.1, 0.2, 0.3, 0.4, 0.5},
		{0.5, 0.4, 0.3, 0.2, 0.1},
		{0.1, 0.2, 0.3, 0.4, 0.5},
		{0.5, 0.4, 0.3, 0.2, 0.1},
		{0.1, 0.2, 0.3, 0.4, 0.5},
		{0.5, 0.4, 0.3, 0.2, 0.1},
		{0.1, 0.2, 0.3, 0.4, 0.5},
		{0.5, 0.4, 0.3, 0.2, 0.1}};
	mapfloat sequence;
	beam_search(sequence,data,3);
	for(auto& it:sequence){
		cout << it.first << ' ' << it.second << endl;
	}
	return 0;
}

