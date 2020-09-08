# import the module 
import tweepy 

# assign the values accordingly 
consumer_key = 'vG4qN6vZn47PfLvQiOl5vEgwI'
consumer_secret = 'I50fXTBjtopq2jAkfztGwFmifOLpYj0tshRSyruOThFRgNnMr8'
access_token = '3141790171-XjYckAXh1NrgTUgJvZ4y5JCOiDmcAps2YyByP2z'
access_token_secret = '4dbPGQK0voro1tRhMwcGnw1wjdCjLPxpNnAQIbBQInioc'

# authorization of consumer key and consumer secret 
auth = tweepy.OAuthHandler(consumer_key, consumer_secret) 

# set access to user's access key and access secret 
auth.set_access_token(access_token, access_token_secret) 

# calling the api 
api = tweepy.API(auth) 

# the screen_name of the targeted user 
screen_name = "geeksforgeeks"

# printing the latest 20 followers of the user 
for follower in api.followers(screen_name): 
	print(follower.screen_name) 
