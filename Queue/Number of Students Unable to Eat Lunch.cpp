//https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/

//TC:O(n^2)     //SC:O(n)
int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n=students.size();
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            q.push(students[i]);
        }
        for(int i=0;i<n;i++)
        {
                int cnt=0;
                while(cnt<q.size() && q.front()!=sandwiches[i])
                {
                    q.push(q.front());
                    q.pop();
                    cnt++;
                }
                if(cnt==q.size())
                    return cnt;
                q.pop();            
        }
        return q.size();
    }

//TC:O(n)     //SC:O(1)
int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n=students.size();
        int c1=0,c0=0;
        for(int i=0;i<n;i++)
        {
            if(students[i])
                c1++;
            else
                c0++;
        }
        for(int i=0;i<n;i++)
        {
            if(sandwiches[i])
            {
                if(c1)
                    c1--;
                else
                    return n-i;
            }
            else
            {
                if(c0)
                    c0--;
                else
                    return n-i;
            }
        }
        return 0;
    }