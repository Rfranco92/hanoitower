#include <iostream>
#include <vector>
using namespace std;

int count = 0;
vector<int> start;
vector<int> mid;
vector<int> last;

void add(char letter, int num)
{
    if (letter == 'A'){
        start.insert(start.begin(), num);
    }
    else if(letter == 'B'){
        mid.insert(mid.begin(), num);
    }
    else if(letter == 'C'){
        last.insert(last.begin(), num);
    }
}

void subtract(char letter)
{
    if (letter == 'A'){
        start.erase(start.begin());
    }
    else if(letter == 'B'){
        mid.erase(mid.begin());
    }
    else if(letter == 'C'){
        last.erase(last.begin());
    }
    
}

void declareState (char type){
    cout << "Tower " << type << " contains";
    
    if (type == 'A'){
    if (start.size() == 0) {
        cout << " nothing" << endl;
    } 
    else{
    for (int i = 0; i < start.size(); i++){
    cout << " " << start[i]; 
    }
    }
    }
    else if(type == 'B'){
        if (mid.size() == 0) {
            cout << " nothing" << endl;
        }
        else{
        for (int i = 0; i < mid.size(); i++){
        cout << " "  << mid[i]; 
        }
        
    }
    }
    else if(type == 'C'){
         if (last.size() == 0) {
        cout << " nothing" << endl;
        }
        else{
        for (int i = 0; i < last.size(); i++){
        cout << " " << last[i];
        }
    }
    }
    cout << endl;
    
}
void toh(int x,char start ,char goal,char mid)
{
	if(x==1)
	{   
	    count++;
	    cout<<count<< ". Move disc 1 from "<<start<<" to "<<goal<<endl; //only disc remaining
	    add(goal, x);
	    subtract (start);
	    declareState('A');
	    declareState('B');
	    declareState('C');
	}
	else
	{
		toh(x-1,start,mid,goal) ; //Moving n-1 poles to auxillary pole
		count ++;
        cout<<count<< ". Move disc "<<x<<" from "<<start<<" to "<<goal<<endl;
        add(goal, x);
	    subtract (start);
	    declareState('A');
	    declareState('B');
	    declareState('C');
		toh(x-1,mid,goal,start); // Move n-1 poles to destination
	}
}
int main(int argc, char *argv[])
{	char a,b,c;
	int x;
	a='A'; //Start disc
	b='B'; //Auxillary disc
	c='C'; //End Discx
	cout << "Enter value of discs, please make it at most 6" << endl;
	cin>>x;
	for (int i = 0; i < x; i++){
	start.insert(start.end(), i+1);
	}
	if (x > 6){
	    cout << "Too many discs for this equation" << endl;
	    return 0;
	}
	toh(x,a,c,b);
	cout << "The total of steps taken for this equation is " << count << endl; 
	return 0;
}