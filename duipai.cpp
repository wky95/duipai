#include <bits/stdc++.h>
#include <sys/time.h>
#define debug(x) cerr<<#x<<" = "<<x<<'\n';
#define int long long
using namespace std;
mt19937_64 seed (time (NULL));
#define rnd(l,r) uniform_int_distribution<long long> ((l), (r)) (seed)

string readTxt(string file){
    string res;
    ifstream infile;
    infile.open(file.data());
    assert(infile.is_open());

    char c;
    infile >> noskipws;
    while (!infile.eof()){
        infile>>c;
        if(c!='\n' or !infile.eof()){
            cout<<c;
            res.push_back(c);
        }
    }
    infile.close();
    return res;
}
void duipai(){
/// compile start
    system("g++ -std=c++17 ../codeforces.cpp -o ../codeforces");
    system("g++ -std=c++17 temp.cpp -o temp");
/// compile comlpete

/// run start
    string myans,corretans;
    struct timeval tv;
    struct timeval start_tv;

    gettimeofday(&start_tv, NULL);
    system("./../codeforces < in.txt > cfout.txt");
    double elapsed = 0.0;
    gettimeofday(&tv, NULL);
    elapsed = (tv.tv_sec - start_tv.tv_sec) + (tv.tv_usec - start_tv.tv_usec) / 1000000.0;
    cout<<"my answer: ";
    cout<<"(total time: "<<elapsed<<"s)\n";
    myans=readTxt("cfout.txt");
    
    gettimeofday(&start_tv, NULL);
    system("./temp < in.txt > tempout.txt");
    elapsed = 0.0;
    gettimeofday(&tv, NULL);
    elapsed = (tv.tv_sec - start_tv.tv_sec) + (tv.tv_usec - start_tv.tv_usec) / 1000000.0;
    cout<<"correct answer: ";
    cout<<"(total time: "<<elapsed<<"s)\n";
    corretans=readTxt("tempout.txt");
/// run complete
    if(myans==corretans)cout<<"AC\n";
    else cout<<"WA\n";
}

ofstream of;
string file="in.txt";
int n=5000;

void gendata(){
/// genertating data start
    of.open(file.data());
    of<<n<<' '<<rnd(1,n)<<' '<<rnd(1,n)<<'\n';
    for(int i=1;i<=n;i++){
        of<<rnd(1,100000)<<' ';
    }
    of<<'\n';
    of.close();
/// genertating data complete
}

signed main(){
    ///  生測資
    gendata();

    /// 對拍
    duipai();
}