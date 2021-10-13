// Lab - 2 Assignment

/*

Consider a reference string (sequence of page numbers to be accessed). Given this string, determine if a given page generates a H (hit) or M (Miss). Number of page frames shall be an user input. Implement FIFO and OPT policies. Outcome of the program should be a sequence of H and M. And overall number of page hits and number of page faults and hit ratio.

*/

#include<bits/stdc++.h>
using namespace std;

//  This function change string to the vector of pages
vector<int> changeStrToPage(string str){
	vector<int> pages;
	int page = 0;
	for(int i=0;i<str.size();i++){
		if(str[i]!='-'){
			page = page*10 + (str[i] - '0');
		}
		else{
			pages.push_back(page);
			page = 0;
		}
	}
	pages.push_back(page);
	return pages;
}

// This function will find the hit and miss for the respective page using FIFO
pair<int,int> HitAndMissByFIFO(vector<int> pages,int number_of_frame){
	unordered_map<int,bool> m;
	queue<int> q;
	int hit = 0;
	int miss = 0;
	
	cout<<endl<<endl;
	cout<<"By First In First Out (FIFO) Page replacement Policy"<<endl;
	for(int i=0;i<pages.size();i++){
		if(m.find(pages[i]) != m.end()){
			hit++;
			cout<<"Page: "<<pages[i]<<" - Hit"<<endl;
		}
		else{
			miss++;
			cout<<"Page: "<<pages[i]<<" - Miss"<<endl;
			if(q.size() < number_of_frame){
				q.push(pages[i]);
				m[pages[i]] = true;
			}
			else{
				int t = q.front();
				q.pop();
				m.erase(t);
				q.push(pages[i]);
				m[pages[i]] = true;
			}
		}
	}
	return make_pair(hit,miss);
}

// This function will find the hit and miss for the respective page using OPT
pair<int,int> HitAndMissByOPT(vector<int> pages,int number_of_frame){
	int hit = 0,miss = 0;
	
	set<pair<int,int>> s;
	unordered_map<int,bool> m;
	
	int counter = 0;
	cout<<endl<<endl;
	cout<<"By Opimal Page replacement Policy(OPT)"<<endl;
	for(int i=0;i<pages.size();i++){
		if(m.find(pages[i]) != m.end()){
			hit++;
			cout<<"Page: "<<pages[i]<<" - Hit"<<endl;
			
			for(auto it = s.begin(); it != s.end();it++){
				auto t = *it;
				if(t.second == pages[i]){
					s.erase(it);
					break;
				}
			}
			
			s.insert(make_pair(counter,pages[i]));
			counter++;
			
		}
		else{
			miss++;
			cout<<"Page: "<<pages[i]<<" - Miss"<<endl;
			
			if(s.size() < number_of_frame) {
				s.insert(make_pair(counter,pages[i]));
				counter++;
				m[pages[i]] = true;
			}
			else{
				auto it = s.begin();
				s.erase(it);
				auto t = *it;
				m.erase(t.second);
				s.insert(make_pair(counter,pages[i]));
				counter++;
				m[pages[i]] = true;
			}
		}
	}
	
	
	return make_pair(hit,miss);
}

int main(){
	
	string str;
	cout<<"Enter the string of pages seperated by -"<<endl;
	cin>>str;
	
	cout<<"Enter the number of frames"<<endl;
	int number_of_frame;
	cin>>number_of_frame;
	
	vector<int> pages = changeStrToPage(str);
	
	cout<<endl<<endl;
	cout<<"Pages : ";
	for(auto ele: pages){
		cout<<ele<<" ";
	}
	cout<<endl;
	
	pair<int,int> res1 = HitAndMissByFIFO(pages,number_of_frame);
	
	cout<<"Total Hit: "<<res1.first<<" Total Miss: "<<res1.second<<endl;
	int t = __gcd(res1.first,res1.second);
	cout<<"Hit Ratio: "<<res1.first/t<<" : "<<res1.second/t<<endl;
	
	pair<int,int> res2 = HitAndMissByOPT(pages,number_of_frame);
	
	cout<<"Total Hit: "<<res2.first<<" Total Miss: "<<res2.second<<endl;
	int t1 = __gcd(res2.first,res2.second);
	cout<<"Hit Ratio: "<<res2.first/t1<<" : "<<res2.second/t1<<endl;
	
	
	return 0;
}


/* Input Format

7-0-1-2-0-3-0-4-2-3-0-3-2-3     // Page of string in this fashion                                     
4	// Number of frames

*/


