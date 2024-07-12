vector<int> ns(n,n),ps(n,-1),ng(n,n),pg(n,-1);

        stack<int> s;

        for(int i=n-1;i>=0;i--){

            while(s.size()>0&&nums[s.top()]>nums[i])
            s.pop();

            if(s.size()>0) ns[i]=s.top();
            s.push(i);
        }
        while(!s.empty())s.pop();


         for(int i=n-1;i>=0;i--){

            while(s.size()>0&&nums[s.top()]<=nums[i])
            s.pop();

            if(s.size()>0) ng[i]=s.top();
            s.push(i);
        }
        while(!s.empty())s.pop();

         for(int i=0;i<n;i++){

            while(s.size()>0&&nums[s.top()]>=nums[i])
            s.pop();

            if(s.size()>0) ps[i]=s.top();
            s.push(i);
        }
        while(!s.empty())s.pop();

         for(int i=0;i<n;i++){

            while(s.size()>0&&nums[s.top()]<nums[i])
            s.pop();

            if(s.size()>0) pg[i]=s.top();
            s.push(i);
        }