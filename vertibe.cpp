#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<array>
using namespace std;

int vertibe(array<array<float,3>, 3> & alpha,array<array<int,3>, 3> & path,const array<array<float,3>, 3> & a,const array<array<float,2>, 3> & b,const array<float,3> & pi,const vector<string> & o,const vector<string> & h,map<string,int> & o2idx){
	int T = o.size();
	int statenum = h.size();

	int index,score,i,j,t;
	for(t=0; t<T; t++){
		for(i=0; i<statenum; i++){
			if(t==0){
				alpha[t][i] = pi[i]*b[i][o2idx[o[t]]];
				index = i;
			}else{
				score = 0;
				for(j=0; j<statenum; j++){
					if(alpha[t-1][j]*a[j][i]*b[i][o2idx[o[t]]] > alpha[t][i]){
						alpha[t][i] = alpha[t-1][j]*a[j][i]*b[i][o2idx[o[t]]];
					}
					if(alpha[t-1][j]*a[j][i] > score){
						score = alpha[t-1][j]*a[j][i];
						index = j;
					}		
				}
			}
			path[t][i] = index;
		}
	}

	return index;

}


int main(){
	array<array<float,3>, 3> a;
	a[0] = array<float,3> {{0.5,0.2,0.3}};
	a[1] = array<float,3> {{0.3,0.5,0.2}};
	a[2] = array<float,3> {{0.2,0.3,0.5}};

	array<array<float,2>, 3> b;
	b[0] = array<float,2> {{0.5,0.5}};
	b[1] = array<float,2> {{0.4,0.6}};
	b[2] = array<float,2> {{0.7,0.3}};

	array<float,3> pi {{0.2,0.4,0.4}};

	vector<string> h  {"盒子1","盒子2","盒子3"};
	vector<string> o  {"红","白","红"};

	map<string,int> o2idx = {{"红",0},{"白",1}};

	int T = o.size();
	int statenum = h.size();

	array<array<float,3>, 3> alpha {{0}};
	array<array<int,3>, 3> path {{0}};

	int index;
	index = vertibe(alpha,path,a,b,pi,o,h,o2idx);
	cout << "the probility is: " << endl;
	cout << alpha[T-1][index] << endl;

	cout << "the path is: " << endl;
	cout << index << endl;
	for(int i=T-1;i>0;i--){
		index = path[i][index];
		cout << index <<endl;
	}
	
	return 0;
}
