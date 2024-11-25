// Time Complexity : O(n + m) && Space Complexity : O(n + m)
class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> res;
        int i = 0, j = 0;
        int n = nums1.size(), m = nums2.size();
        while(i < n && j < m)
        {
            if(nums1[i][0] == nums2[j][0])
            {
                res.push_back({nums1[i][0], nums1[i][1] + nums2[j][1]});
                i++; j++;
            }
            else if(nums1[i][0] < nums2[j][0])
            {
                res.push_back({nums1[i][0], nums1[i][1]});
                i++;
            }
            else
            {
                res.push_back({nums2[j][0], nums2[j][1]});
                j++;
            }
        }
        while(i < n)
        {
            res.push_back({nums1[i][0], nums1[i][1]});
            i++;
        }
        while(j < m)
        {
            res.push_back({nums2[j][0], nums2[j][1]});
            j++;
        }
        return res;
    }
};
