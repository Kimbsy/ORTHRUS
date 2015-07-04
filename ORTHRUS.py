#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
from twython import Twython

# figure out what we're going to tweet
tweetStr = ""

temp_data = open("data/temperature.data").read().split("\n")
food_data = open("data/food.data").read().split("\n")
wheel_data = open("data/wheel.data").read().split("\n")

print(temp_data)
print(food_data)
print(wheel_data)

if temp_data[0] != "":
    tweetStr += "Temp: " + str(temp_data[0]) + " ºC\n"


# open file with access keys and tokens
f = open("/home/kimbsy/Documents/ORTHRUS.access")

# assign keys and tokens
secrets = f.read().split("\n")

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
