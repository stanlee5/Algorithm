class Solution {
public:
    int myAtoi(string str) {
        int t=0,flag=0;
        auto p=str.begin();
        while (*p==' ')
            p++;
        if (*p=='-')
            p++,flag=1;
        else if (*p=='+')
            p++;
            
        for (;p!=str.end();p++)
        {
            if (*p<'0' || *p>'9')
                break;
            if (t>214748364)
            {
                t=-1;
                break;
            }
            t = t*10 + (*p-'0');
        }
        if (t<0)
        {
            if (flag)
                t = -2147483648;
            else
                t = 2147483647;
        }
        else if (flag)
            t = -t;
        return t;
    }
};
