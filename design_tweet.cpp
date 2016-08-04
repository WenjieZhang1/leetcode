#include <stdio.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <list>
#include <string>
using namespace std;
class design_tweet
{
private:
	struct tweet
	{
		int user_id;
		string tweet_text;
		int timestamp;
		tweet(int x, string y, int z) : user_id(x), tweet_text(y), timestamp(z) {};
	};
	struct Compare
	{
		bool operator()(pair<list<tweet> :: iterator, list<tweet> :: iterator> p1, 
						pair<list<tweet> :: iterator, list<tweet> :: iterator> p2){
			return p1.first -> timestamp < p2.first -> timestamp;
		}
	};
	unordered_map<int, unordered_set<int>> follow_map;
	unordered_map<int, list<tweet>> send_twitter;
	int timestamp = 0;
public:
	design_tweet();

	void postTweet(int userId, string tweet_text) {
		follow_map[user_id].insert(user_id);
		send_twitter[user_id].push_front(tweet(user_id, tweet_text, timestamp++));
	}

	vector<string> getNewsFeed(int userId){
		vector<string> res;
		if(follow_map[user_id].size() == 0){
			return res;
		}
		priority_queue<pair<pair<list<tweet> :: iterator, list<tweet> :: iterator>, 
					   vector<pair<list<tweet> :: iterator, list<tweet> :: iterator>>, Compare> pq;
		for(auto it : follow_map[user_id]){
			if(send_twitter[it].size() != 0){
				pq.push(make_pair(send_twitter[it].begin(), send_twitter[it].end()));
			}
		}
		int idx = 0;
		while(!pq.empty() && idx < 10){
			pair<pair<list<tweet> :: iterator, list<tweet> p = pq.top();
			res.push_back(p.first -> tweet_text);
			if(++p.first != p.second){
				pq.push(p);
			}
			idx++;
		}
		return res;
	}

	~design_tweet();
	
};