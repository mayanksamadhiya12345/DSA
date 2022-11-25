//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void dfs(int i,int j,int n,int m,int initial_color,int color,vector<vector<bool>>& vis,vector<vector<int>>& image)
    {
        if(i<0 || i>=n || j<0 || j>=m || image[i][j]!=initial_color || vis[i][j])
            return;
        
        vis[i][j] = true;              // mark as visited
        image[i][j] = color;           // assign new color for curr cell
         
        dfs(i+1,j,n,m,initial_color,color,vis,image);   // bottom
        dfs(i-1,j,n,m,initial_color,color,vis,image);   // top
        dfs(i,j-1,n,m,initial_color,color,vis,image);   // left
        dfs(i,j+1,n,m,initial_color,color,vis,image);   // right
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) 
    {
        int n = image.size();
        int m = image[0].size();
        int initial_color = image[sr][sc];
        vector<vector<bool>> vis(n,vector<bool> (m,false));
        
        dfs(sr,sc,n,m,initial_color,newColor,vis,image);
        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends