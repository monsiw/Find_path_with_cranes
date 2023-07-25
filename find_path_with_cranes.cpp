#include <iostream>
#include <vector>
using namespace std;

bool solution(const vector<int> &A, const vector<int> &P, int B, int E){
	bool approved1 = false; 
	bool approved2 = false;
	if(A.size()==P.size()){
		int positive_span=0;
		for(int i=0; i<A.size(); i++){
			if(A[i] > 0){ 
				positive_span=1;
			}else{
				positive_span=0;
				break;
			} 	
		}
		if(positive_span==1){
			vector <int> right_edge;
			vector <int> left_edge;
			int left_var, right_var;
			for(int i=0; i<A.size(); i++){
				right_var=P[i]+A[i];
				left_var=P[i]-A[i];
				right_edge.push_back(right_var);
				left_edge.push_back(left_var);
			}
			for(int i=0; i<A.size(); i++){
				if(B>E){
					if(B >= left_edge[i] && B <= right_edge[i]){ 
						approved1=true;
						if(E >= left_edge[i] && E <= right_edge[i]){
							approved2=true;
							cout<<"true";
							return true;
						}else{
    						for(int j=i; j<A.size(); j++){ 
    							if(E >= left_edge[j] && E <= right_edge[j]){ 
    								if(left_edge[j] <= right_edge[i]){ 
    									approved2=true;
    									cout<<"true";
    									return true;
    								}else{
    									int contact_right_edge=right_edge[i];
    									int contact_left_edge=left_edge[j]; 
    									for(int l=0; l<A.size(); l++){
    										if(contact_right_edge>=left_edge[l] && contact_left_edge<=right_edge[l]){
    											approved2=true; 
    											cout<<"true";
    											return true;
    										}
    									}
    								}								
    							}		
    						}						    
						}
					}	
				}else{
					if(E >= left_edge[i] && E <= right_edge[i]){ 
						approved1=true;
						if(B >= left_edge[i] && B <= right_edge[i]){
							approved2=true;
							cout<<"true";
							return true;						    
						}else{
    						for(int j=A.size()-1; j>=0; j--){ 
    							if(B >= left_edge[j] && B <= right_edge[j]){ 
    								if(left_edge[i] <= right_edge[j]){ 
    									approved2=true;
    									cout<<"true";
    									return true;
    								}else{
    									int contact_right_edge=right_edge[j];
    									int contact_left_edge=left_edge[i]; 
    									for(int l=A.size(); l>=0; l--){
    										if(contact_right_edge>=left_edge[l]&&contact_left_edge<=right_edge[l]){
    											approved2=true;
    											cout<<"true";
    											return true;
    										}
    									}
    								}								
    							}		
    						}						    
						}
					}	
				}
			}
		}
		if(approved1!=true || approved2!=true){
		    cout<<"This point does not fit in this crane";
		    return false;
		}
	}else{
		cout<<"Invalid declaration of cranes";
		return false;
	}
}

int main(){
    //const vector<int> &A = {2,1};
    //const vector<int> &P = {5,1};
    //solution(A,P,2,6);
    //should return false
    //solution(A,P,3,6);
    //should return true
    //const vector<int> &A = {5,5,1};
    //const vector<int> &P = {3,3,6};
    //solution(A,P,4,8);
    //should return true
    //const vector<int> &A = {1,3};
    //const vector<int> &P = {2,6};
    //solution(A,P,1,5);
    //should return true
    const vector<int> &A = {1,4,2};
    const vector<int> &P = {10,4,7};
    solution(A,P,11,1);
    //should return true	
}
