// https://leetcode.com/problems/design-browser-history/

class BrowserHistory {
public:
    vector<string> history;
    int i=0;
    BrowserHistory(string homepage) {
        history.push_back("");
        history.push_back(homepage);
        i++;
    }
    
    void visit(string url) {
        history.erase(history.begin()+i+1,history.end());
        history.push_back(url);
        i++;
    }
    
    string back(int steps) {
        if(i > steps) {
            i -= steps;
        } else {
            i = 1;
        }
        return history[i];
    }
    
    string forward(int steps) {
        if(history.size() - i -1 >  steps) {
            
           i+= steps; 
        } else {
            i = history.size() -1;
        }
        return history[i];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */