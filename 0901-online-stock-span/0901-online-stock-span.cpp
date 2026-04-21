class StockSpanner {
public:
    vector<int> prices;
    stack<int> st; // stores indices

    StockSpanner() {
        
    }
    
    int next(int price) {
        prices.push_back(price);
        int i = prices.size() - 1;

        
        while (!st.empty() && prices[st.top()] <= price) {
            st.pop();
        }

        int span;
        if (st.empty()) {
            span = i + 1;
        } else {
            span = i - st.top();
        }

        st.push(i);
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */