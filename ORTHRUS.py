#!/usr/bin/env python
import sys
from twython import Twython

# figure out what we're going to tweet
tweetStr = "Wooo! command line tweeting!"

# open file with access keys and tokens
f = open("/home/kimbsy/Documents/ORTHRUS.access")

# assign keys and tokens
secrets = f.read().split('\n')

# sort them
apiKey = secrets[0]
apiSecret = secrets[1]
accessToken = secrets[2]
accessTokenSecret = secrets[3]

# instantiate Twython
api = Twython(apiKey,apiSecret,accessToken,accessTokenSecret)

# tweet
# api.update_status(status=tweetStr)

print(tweetStr)
