#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define endl "\n"
#define lli long long int
#define ll long long
#define mp make_pair
#define pb push_back

typedef map<int,int>::iterator it_map;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  

    map<int,int> cell;
    string s,sb;
    int r=0,ic=1,bq=0;

    cin>>s;
    cell[ic]=0;

    while(r<s.size()){

        if(s[r]=='r' || s[r]=='l'){
            if(s[r]=='r'){
                ic++;
            }else{
                ic--;
            }
            it_map i=cell.find(ic);
            if(i==cell.end()){
                cell[ic]=0;
            }else{
                cell[ic]++;
                cell[ic]=cell[ic]%127;
            }
            r++;
        }

        if(s[r]=='u'){
            cell[ic]++;
            cell[ic]=cell[ic]%127;
            r++;
        }

        if(s[r]=='w'){
            cell[ic]--;
            if(cell[ic]<0){
                cell[ic]=127-cell[ic]%127;
            }
            r++;
        }

        if(s[r]=='b'){
            if(cell[ic]==0){
                bq=0;
                sb=s.substr(r+1,s.size()-r+1);
                for(int i=0;i<sb.size();i++){
                    if(sb[i]=='b'){
                        bq++;
                    }
                    if(sb[i]=='d' && bq>0){
                        bq--;
                    }
                    if(sb[i]=='d' && bq==0){
                        r+=i+2;
                    }
                }
            }else{
                r++;
            }
        }

        if(s[r]=='d'){
            if(cell[ic]==0){
                r++;
            }else{
                bq=0;
                sb=s.substr(0,r);
                reverse(sb.begin(),sb.end());
                for(int i=0;i<sb.size();i++){
                    if(sb[i]=='d'){
                        bq++;
                    }
                    if(sb[i]=='b' && bq>0){
                        bq--;
                    }
                    if(sb[i]=='b' && bq==0){
                        r-=i;
                    }
                }
            }
        }

        if(s[r]=='p'){
            cout<<"l"<<endl;
            cout<<char(cell[ic])<<endl;
            r++;
        }
    }
}