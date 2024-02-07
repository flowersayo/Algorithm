class MinStack
{

public:
    typedef pair<int, int> ci; // 스택에 {값,최솟값} 을 동시에 저장하기
    const int INF = INT_MAX;   // 2147483647
    stack<ci> st;

    int min_value;

    MinStack()
    {
        min_value = INF;
    }

    void push(int val)
    {
        min_value = min(min_value, val);
        st.push({val, min_value});
    }

    void pop()
    {
        st.pop();

        if (!st.empty())
        {
            ci top_element = st.top();
            min_value = top_element.second; // 최솟값 업데이트
        }
        else
        {
            min_value = INF;
        }
    }

    int top()
    {

        return st.top().first;
    }

    int getMin()
    {
        ci top_element = st.top();

        return top_element.second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */