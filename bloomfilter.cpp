#include<vector>
#include<iostream>
#include<string>
using namespace std;

template<typename T>
class bloomfilter
{
  private:
    vector<bool> bit_array;
    int elem_size;
    int bit_array_size;
    int hash_fun_size;
  public:
    bloomfilter(const int bs,const int hs):bit_array_size(bs),hash_fun_size(hs){
      for(int i=0;i<bs;i++){
        bit_array.push_back(false);
      }
    };
    ~bloomfilter(){};
    void insert(T obj);
    bool contain(T obj);
    int hash(T obj,int salt);
};

template<typename T>
void bloomfilter<T>::insert(T obj){
  int hash_code;
  for(int i=0;i<hash_fun_size;i++){
    hash_code = hash(obj,i);
    bit_array[hash_code] = true;
  }
}

template<typename T>
bool bloomfilter<T>::contain(T obj){
  int hash_code;
  for(int i=0;i<hash_fun_size;i++){
    hash_code = hash(obj,i);
    if(!bit_array[hash_code]){
      return false;
    }
  }
  return true;
}

//hash function 需要针对不同的对象设计不同的版本，用模板偏特化解决，参考std的标准hash function
template<>
int bloomfilter<int>::hash(int obj,int salt){
  int hash_code;
  hash_code = (obj+salt)%bit_array.size();
  return hash_code;
}

template<>
int bloomfilter<string>::hash(string obj,int salt){
  int hash_code=0;
  for(int i=0;i<(int)obj.size();i++){
    hash_code += int(obj[i]);
  }
  hash_code = (hash_code+salt)%bit_array.size();
  return hash_code;
}
int main(){
  bloomfilter<int> bfint(1000,5);
  bloomfilter<string> bfstring(1000,5);
  bfint.insert(1);
  bfint.insert(2);
  bfint.insert(3);
  cout << bfint.contain(1) << endl;
  cout << bfint.contain(4) << endl;
  cout << bfint.contain(5) << endl;
  bfstring.insert("string");
  bfstring.insert("include");
  bfstring.insert("struct");
  cout << bfstring.contain("string") << endl;
  cout << bfstring.contain("inckude") << endl;
  cout << bfstring.contain("vector") << endl;
  return 0;
}
